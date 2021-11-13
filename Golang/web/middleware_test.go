package web

import (
	"fmt"
	"net/http"
	"testing"
)

type LogMiddleware struct {
	Handler http.Handler
}

func (middleware *LogMiddleware) ServeHTTP(rw http.ResponseWriter, request *http.Request) {
	fmt.Println("Before execute handler")
	middleware.Handler.ServeHTTP(rw, request)
	fmt.Println("After execute handler")
}

type ErrorHandler struct {
	Handler http.Handler
}

func (errorHandler *ErrorHandler) ServeHTTP(rw http.ResponseWriter, request *http.Request) {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Println("Terjadi Error")
			rw.WriteHeader(http.StatusInternalServerError)
			fmt.Fprintf(rw, "Error : %s", err)
		}
	}()
	errorHandler.Handler.ServeHTTP(rw, request)
}

func TestMiddleware(t *testing.T) {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(rw http.ResponseWriter, request *http.Request) {
		fmt.Println("Handle executed")
		fmt.Fprint(rw, "Hello middleware")
	})
	mux.HandleFunc("/foo", func(rw http.ResponseWriter, request *http.Request) {
		fmt.Println("foo executed")
		fmt.Fprint(rw, "Hello foo")
	})
	mux.HandleFunc("/panic", func(rw http.ResponseWriter, request *http.Request) {
		fmt.Println("foo executed")
		panic("Ups Panic trouble")
	})

	logMiddleware := &LogMiddleware{
		Handler: mux,
	}

	errorHandler := &ErrorHandler{
		Handler: logMiddleware,
	}

	server := http.Server{
		Addr:    "localhost:8080",
		Handler: errorHandler,
	}

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}
