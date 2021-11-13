package web

import (
	"fmt"
	"net/http"
	"testing"
)

func DownloadFile(rw http.ResponseWriter, request *http.Request) {
	file := request.URL.Query().Get("file")
	if file == "" {
		rw.WriteHeader(http.StatusBadRequest)
		fmt.Fprint(rw, "BAD REQUEST")
		return
	}

	rw.Header().Add("Content-Disposition", "attachment; filename=\""+file+"\"")
	http.ServeFile(rw, request, "./resources/"+file)
}

func TestDownloadFIle(t *testing.T) {
	server := http.Server{
		Addr:    "localhost:8080",
		Handler: http.HandlerFunc(DownloadFile),
	}

	err := server.ListenAndServe()
	if err != nil {
		panic(err)
	}
}
