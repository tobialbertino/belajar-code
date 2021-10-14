package main

import "fmt"

type Costumer struct {
	Name, Addres string
	Age          int
}

func (costumer Costumer) sayHello(name string) {
	fmt.Println("Hello", name, "My name is", costumer.Name)
}

func (a Costumer) sayHuuu() {
	fmt.Println("Huuuuu", a.Name)
}

func main() {
	var tobi Costumer
	tobi.Name = "Tobi"
	tobi.Addres = "Indonesia"
	tobi.Age = 21

	tobi.sayHello("Joko")
	tobi.sayHuuu()

	fmt.Println(tobi.Name)
	fmt.Println(tobi.Addres)
	fmt.Println(tobi.Age)

	joko := Costumer{
		Name:   "Joko",
		Addres: "Cirebon",
		Age:    25,
	}

	// RISK
	budi := Costumer{"Budi", "Jakarta", 20}

	fmt.Println(joko)
	fmt.Println(budi)
}
