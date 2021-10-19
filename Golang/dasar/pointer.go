package main

import "fmt"

type Address struct {
	City, Province, Country string
}

func changeCountryToIndonesia(address *Address) {
	address.Country = "Indonesia"
}

func main() {
	addres1 := Address{"Subang", "Jawa barat", "Indonesia"}
	addres2 := &addres1 // pointer
	var addres3 *Address = &addres1
	// var addres4 *Address = &Address{"Malang", "Jawa timur", "Indonesia"}

	addres2.City = "Bandung"

	// membuat Address baru dan hanya addres2 yg ikut
	// addres2 = &Address{"Jakarta", "DKI Jakarta", "Indonesia"}

	// paksa semua untuk ubah apapun yg meganmbil reference addres1
	*addres2 = Address{"Jakarta", "DKI Jakarta", "Indonesia"}

	fmt.Println(addres1)
	fmt.Println(addres2)
	fmt.Println(addres3)

	var addres4 *Address = new(Address)
	addres4.City = "Tangerang"
	fmt.Println(addres4)

	var alamat = Address{
		City:     "Tangerang",
		Province: "Banten",
		Country:  "",
	}
	var alamatPointer *Address = &alamat
	changeCountryToIndonesia(alamatPointer)
	// changeCountryToIndonesia(&alamat)

	fmt.Println(alamat)
}
