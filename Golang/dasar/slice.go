package main

import "fmt"

func main() {
	var months = [...]string{
		"januari",
		"febuary",
		"maret",
		"april",
		"mei",
		"juni",
		"juli",
		"agustus",
		"september",
		"oktober",
		"november",
		"desember",
	}

	var slice1 = months[4:7]
	fmt.Println(slice1)
	fmt.Println(len(slice1))
	fmt.Println(cap(slice1))

	// var slice2 = months[4:7] // will replace source refference array
	var slice2 = months[10:] // new array for slice3
	fmt.Println((slice2))

	var slice3 = append(slice2, "Tobi") // will make new array
	fmt.Println(slice3)

	// tidak berubah
	fmt.Println(slice2)
	fmt.Println(months)

	newSLice := make([]string, 2, 5)

	newSLice[0] = "tobi"
	newSLice[1] = "albertino"

	fmt.Println(newSLice)
	fmt.Println(len(newSLice))
	fmt.Println(cap(newSLice))

	copySLice := make([]string, len(newSLice), cap(newSLice))
	copy(copySLice, newSLice)

	fmt.Println(copySLice)

	// iniArray := [...]int {0,1,2,3,4}
	iniArray := [5]int{0, 1, 2, 3, 4}
	iniSlice := []int{0, 1, 2, 3, 4}

	fmt.Println(iniArray)
	fmt.Println(iniSlice)
}
