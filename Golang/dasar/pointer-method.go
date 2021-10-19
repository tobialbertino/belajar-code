/**
pada pointer-method/func, pada func main()
tidak perlu menambahkan variabel pointer
*/

package main

import "fmt"

type Man struct {
	Name string
}

func (man *Man) married() {
	man.Name = "Mr. " + man.Name
}

func main() {
	tobi := Man{"Tobi"}
	tobi.married()

	fmt.Println(tobi.Name)
}
