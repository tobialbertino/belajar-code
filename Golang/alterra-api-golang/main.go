package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

type ToDO struct {
	Kegiatan string `json:"kegiatan"`
	Waktu    string `json:"waktu"`
}

type JSONResponse struct {
	Code    int    `json:"code"`
	Success bool   `json:"success"`
	Message string `json:"message"`
	// Data    []ToDO `json:"data"`
	Data interface{} `json:"data"`
}

func main() {
	daftarKegiatan := []ToDO{}
	daftarKegiatan = append(daftarKegiatan, ToDO{
		Kegiatan: "Liburan ke Solo",
		Waktu:    "2020-11-30",
	})
	daftarKegiatan = append(daftarKegiatan, ToDO{
		Kegiatan: "Meeting Project",
		Waktu:    "2020-11-05",
	})

	http.HandleFunc("/", func(rw http.ResponseWriter, r *http.Request) {
		// GET http://localhost:8000
		if r.Method == http.MethodGet {
			//lakukan sesuatu untuk get
			rw.Header().Add("Content-Type", "application/json")
			res := JSONResponse{
				Code:    http.StatusOK,
				Success: true,
				Message: "Uji coba method get pada golang",
				Data:    daftarKegiatan,
			}

			resJSON, err := json.Marshal(res)
			if err != nil {
				fmt.Println("Terjadi Kesalahan")
				http.Error(rw, "Terjadi Kesalahan", http.StatusInternalServerError)
				return
			}

			rw.Write(resJSON)
		} else if r.Method == http.MethodPost {
			// lakukan sesuatu untuk post
			// menambahkan data baru
			// isi r.Body {JSON}
			// {
			// 	"kegiatan": "Percobaan",
			// 	"waktu": "2020-10-10"
			// }

			jsonDecode := json.NewDecoder(r.Body)
			aktivitasBaru := ToDO{}
			res := JSONResponse{}

			if err := jsonDecode.Decode(&aktivitasBaru); err != nil {
				fmt.Println("Terjadi Kesalahan")
				http.Error(rw, "Terjadi Kesalahan saat baca input", http.StatusInternalServerError)
				return
			}

			res.Code = http.StatusCreated
			res.Success = true
			res.Message = "Berhasil menambahkan data"
			res.Data = aktivitasBaru

			resJSON, err := json.Marshal(res)
			if err != nil {
				fmt.Println("Terjadi Kesalahan")
				http.Error(rw, "Terjadi Kesalahan", http.StatusInternalServerError)
				return
			}

			rw.Header().Add("Content-Type", "application/json")
			rw.Write(resJSON)
		}
	})

	fmt.Println("Listenong on : 8000")
	log.Fatal(http.ListenAndServe(":8000", nil))
}
