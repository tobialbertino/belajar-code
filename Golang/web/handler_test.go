package web

import (
	"fmt"
	"net/http"
	"testing"
)

func TestHandler(t *testing.T) {

	var handler http.HandlerFunc = func(writer http.ResponseWriter, request *http.Request) {
		// Logic web
		fmt.Fprint(writer, "Hello World!")
	}

	server := http.Server{
		Addr:    "localhost:8080",
		Handler: handler,
	}

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}

func TestServeMux(t *testing.T) {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(rw http.ResponseWriter, r *http.Request) {
		fmt.Fprint(rw, "Hello World!")
	})

	mux.HandleFunc("/hi", func(rw http.ResponseWriter, r *http.Request) {
		fmt.Fprint(rw, "Hi...")
	})

	mux.HandleFunc("/images/", func(rw http.ResponseWriter, r *http.Request) {
		fmt.Fprint(rw, "Images")
	})

	mux.HandleFunc("/images/thumbnails/", func(rw http.ResponseWriter, r *http.Request) {
		fmt.Fprint(rw, "thumbnails")
	})

	server := http.Server{
		Addr:    "localhost:8080",
		Handler: mux,
	}

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}

func TestRequest(t *testing.T) {
	var handler http.HandlerFunc = func(rw http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(rw, r.Method)
		fmt.Fprintln(rw, r.RequestURI)
	}

	server := http.Server{
		Addr:    "localhost:8080",
		Handler: handler,
	}

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}
