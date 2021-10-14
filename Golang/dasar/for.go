package main

import "fmt"

func main() {
	counter := 1

	for counter <= 10 {
		fmt.Println("perulangan ke ", counter)
		counter++
	}

	// with statement
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}

	slice := []string{"satu", "dua", "tiga"}

	for i := 0; i < len(slice); i++ {
		fmt.Println(slice[i])
	}

	for i, value := range slice {
		fmt.Println("index: ", i, "value: ", value)
	}
	// ganti "_" jika tidak perlu variabel
	for _, value := range slice {
		fmt.Println("value: ", value)
	}

	person := map[string]string{
		"name":  "Tobi",
		"title": "Programmer",
	}

	for key, value := range person {
		fmt.Println(key, "=>", value)
	}
}
