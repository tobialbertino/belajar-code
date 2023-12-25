package main_test

import (
	"bytes"
	_ "embed"
	"encoding/json"
	"errors"
	"github.com/gofiber/fiber/v2"
	"github.com/gofiber/template/mustache/v2"
	"github.com/stretchr/testify/assert"
	"io"
	"mime/multipart"
	"net/http"
	"net/http/httptest"
	"strings"
	"testing"
)

var engine = mustache.New("./template", ".mustache")

var app = fiber.New(fiber.Config{
	Views: engine,
	ErrorHandler: func(ctx *fiber.Ctx, err error) error {
		ctx.Status(fiber.StatusInternalServerError)
		return ctx.SendString("Error: " + err.Error())
	},
})

func TestRoutingHelloWorld(t *testing.T) {
	app.Get("/", func(ctx *fiber.Ctx) error {
		return ctx.SendString("Hello World")
	})

	request := httptest.NewRequest(http.MethodGet, "/", strings.NewReader(""))

	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello World", string(bodyBytes))
}

func TestCtx(t *testing.T) {
	app.Get("/hello", func(ctx *fiber.Ctx) error {
		name := ctx.Query("name", "Guest")
		return ctx.SendString("Hello " + name)
	})

	request := httptest.NewRequest(http.MethodGet, "/hello?name=Tobi", strings.NewReader(""))
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello Tobi", string(bodyBytes))

	request = httptest.NewRequest(http.MethodGet, "/hello", strings.NewReader(""))
	resp, err = app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err = io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello Guest", string(bodyBytes))
}

func TestHttpRequest(t *testing.T) {
	app.Get("/request", func(ctx *fiber.Ctx) error {
		first := ctx.Get("firstname")
		last := ctx.Cookies("lastname")
		return ctx.SendString("Hello " + first + " " + last)
	})

	request := httptest.NewRequest(http.MethodGet, "/request", strings.NewReader(""))
	request.Header.Add("firstname", "Tobi")
	request.AddCookie(&http.Cookie{Name: "lastname", Value: "Albertino"})
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello Tobi Albertino", string(bodyBytes))
}

func TestRouteParameter(t *testing.T) {
	app.Get("/users/:userId/orders/:orderId", func(ctx *fiber.Ctx) error {
		userId := ctx.Params("userId")
		orderId := ctx.Params("orderId")
		return ctx.SendString("Get Order " + orderId + " From User " + userId)
	})

	request := httptest.NewRequest(http.MethodGet, "/users/Tobi/orders/10", strings.NewReader(""))
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Get Order 10 From User Tobi", string(bodyBytes))
}

func TestFormRequest(t *testing.T) {
	app.Post("/hello", func(ctx *fiber.Ctx) error {
		name := ctx.FormValue("name")
		return ctx.SendString("Hello " + name)
	})

	body := strings.NewReader("name=Tobi")
	request := httptest.NewRequest(http.MethodPost, "/hello", body)
	request.Header.Set(fiber.HeaderContentType, fiber.MIMEApplicationForm)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello Tobi", string(bodyBytes))
}

//go:embed source/sample.txt
var exampleFile []byte

func TestFormUpload(t *testing.T) {
	app.Post("/upload", func(ctx *fiber.Ctx) error {
		file, err := ctx.FormFile("file")
		if err != nil {
			return err
		}

		err = ctx.SaveFile(file, "./target/"+file.Filename)
		if err != nil {
			return err
		}

		return ctx.SendString("Upload Success")
	})

	body := new(bytes.Buffer)
	writer := multipart.NewWriter(body)
	file, err := writer.CreateFormFile("file", "sample.txt")
	assert.Nil(t, err)

	_, err = file.Write(exampleFile)
	if err != nil {
		panic(err)
	}

	err = writer.Close()
	if err != nil {
		panic(err)
	}

	request := httptest.NewRequest(http.MethodPost, "/upload", body)
	request.Header.Set(fiber.HeaderContentType, writer.FormDataContentType())
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Upload Success", string(bodyBytes))
}

type LoginRequest struct {
	Username string `json:"username"`
	Password string `json:"password"`
}

func TestRequestBody(t *testing.T) {
	app.Post("/login", func(ctx *fiber.Ctx) error {
		var req LoginRequest
		body := ctx.Body()

		err := json.Unmarshal(body, &req)
		if err != nil {
			return err
		}
		return ctx.SendString("Hello " + req.Username)
	})

	body := strings.NewReader(`{"username":"Tobi", "password":"secret"}`)
	request := httptest.NewRequest(http.MethodPost, "/login", body)
	request.Header.Set(fiber.HeaderContentType, fiber.MIMEApplicationJSON)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello Tobi", string(bodyBytes))
}

type RegisterRequest struct {
	Username string `json:"username" xml:"username" form:"username"`
	Password string `json:"password" xml:"password" form:"password"`
	Name     string `json:"name" xml:"name" form:"name"`
}

func TestBodyParser(t *testing.T) {
	app.Post("/register", func(ctx *fiber.Ctx) error {
		var req = new(RegisterRequest)
		err := ctx.BodyParser(req)
		if err != nil {
			return err
		}
		return ctx.SendString("Register Success " + req.Username)
	})
}

func TestBodyParserJSON(t *testing.T) {
	TestBodyParser(t)

	body := strings.NewReader(`{"username":"Tobi","password":"secret","name":"Tobi Albertino"}`)
	request := httptest.NewRequest(http.MethodPost, "/register", body)
	request.Header.Set(fiber.HeaderContentType, fiber.MIMEApplicationJSON)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Register Success Tobi", string(bodyBytes))
}

func TestBodyParserFORM(t *testing.T) {
	TestBodyParser(t)

	body := strings.NewReader(`username=Tobi&password=secret&name=Tobi+Albertino`)
	request := httptest.NewRequest(http.MethodPost, "/register", body)
	request.Header.Set(fiber.HeaderContentType, fiber.MIMEApplicationForm)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Register Success Tobi", string(bodyBytes))
}

func TestBodyParserXML(t *testing.T) {
	TestBodyParser(t)

	body := strings.NewReader(`
		<RegisterRequest>
			<username>Tobi</username>
			<password>secret</password>
			<name>Tobi Albertino</name>
		</RegisterRequest>
	`)
	request := httptest.NewRequest(http.MethodPost, "/register", body)
	request.Header.Set(fiber.HeaderContentType, fiber.MIMEApplicationXML)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Register Success Tobi", string(bodyBytes))
}

func TestResponseJSON(t *testing.T) {
	app.Get("/user", func(ctx *fiber.Ctx) error {
		return ctx.JSON(fiber.Map{
			"username": "Tobi",
			"name":     "Tobi Albertino",
		})
	})

	body := strings.NewReader("")
	request := httptest.NewRequest(http.MethodGet, "/user", body)
	request.Header.Set(fiber.HeaderAccept, fiber.MIMEApplicationJSON)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, `{"name":"Tobi Albertino","username":"Tobi"}`, string(bodyBytes))
}

func TestDownloadFile(t *testing.T) {
	app.Get("/download", func(ctx *fiber.Ctx) error {
		return ctx.Download("./source/sample.txt", "contoh.txt")
	})

	body := strings.NewReader("")
	request := httptest.NewRequest(http.MethodGet, "/download", body)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)
	assert.Equal(t, `attachment; filename="contoh.txt"`, resp.Header.Get(fiber.HeaderContentDisposition))

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, `this is sample file for upload`, string(bodyBytes))
}

func TestRoutingGroup(t *testing.T) {
	helloWorld := func(ctx *fiber.Ctx) error {
		return ctx.SendString("Hello World")
	}

	api := app.Group("/api")
	api.Get("/hello", helloWorld)
	api.Get("/world", helloWorld)

	web := app.Group("/web")
	web.Get("/hello", helloWorld)
	web.Get("/world", helloWorld)

	body := strings.NewReader("")
	request := httptest.NewRequest(http.MethodGet, "/api/world", body)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "Hello World", string(bodyBytes))
}

func TestStatic(t *testing.T) {
	app.Static("/public", "./source")

	body := strings.NewReader("")
	request := httptest.NewRequest(http.MethodGet, "/public/sample.txt", body)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, "this is sample file for upload", string(bodyBytes))
}

func TestErrorHandler(t *testing.T) {
	app.Get("/error", func(ctx *fiber.Ctx) error {
		return errors.New("ups")
	})

	body := strings.NewReader("")
	request := httptest.NewRequest(http.MethodGet, "/error", body)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusInternalServerError, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Equal(t, `Error: ups`, string(bodyBytes))
}

func TestView(t *testing.T) {
	app.Get("/view", func(ctx *fiber.Ctx) error {
		return ctx.Render("index", fiber.Map{
			"title":   "Hello Title",
			"header":  "Hello Header",
			"content": "Hello Content",
		})
	})

	body := strings.NewReader("")
	request := httptest.NewRequest(http.MethodGet, "/view", body)
	resp, err := app.Test(request)
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, resp.StatusCode)

	bodyBytes, err := io.ReadAll(resp.Body)
	assert.Nil(t, err)
	assert.Contains(t, string(bodyBytes), "Hello Title")
	assert.Contains(t, string(bodyBytes), "Hello Header")
	assert.Contains(t, string(bodyBytes), "Hello Content")
}

func TestClient(t *testing.T) {
	client := fiber.AcquireClient()
	defer fiber.ReleaseClient(client)

	agent := client.Get("https://example.com")
	status, resp, err := agent.String()
	assert.Nil(t, err)
	assert.Equal(t, http.StatusOK, status)
	assert.Contains(t, resp, "Example Domain")
}
