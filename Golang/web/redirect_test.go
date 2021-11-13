package web

import (
	"fmt"
	"net/http"
	"testing"
)

func RedirectTo(rw http.ResponseWriter, request *http.Request) {
	fmt.Print("Hello Redirect")
}

func RedirectFrom(rw http.ResponseWriter, request *http.Request) {
	// logic
	http.Redirect(rw, request, "/redirect-to", http.StatusTemporaryRedirect)
}

func RedirectOut(rw http.ResponseWriter, request *http.Request) {
	// logic
	http.Redirect(rw, request, "https://www.google.com", http.StatusTemporaryRedirect)
}

func TestRedirect(t *testing.T) {
	mux := http.NewServeMux()
	mux.HandleFunc("/redirect-from", RedirectFrom)
	mux.HandleFunc("/redirect-to", RedirectTo)
	mux.HandleFunc("/redirect-out", RedirectOut)

	server := http.Server{
		Addr:    "localhost:8080",
		Handler: mux,
	}

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}
