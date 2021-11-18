package json

import (
	"encoding/json"
	"fmt"
	"testing"
)

func TestJSONArray(t *testing.T) {

	customer := &Customer{
		FirstName:  "M",
		MiddleNmae: "Khoiru",
		LastName:   "Tobi",
		Age:        21,
		Married:    false,
		Hobbies:    []string{"gaming", "reading", "coding"},
	}

	bytes, _ := json.Marshal(customer)
	fmt.Println(string(bytes))
}

func TestJSONArrayDecode(t *testing.T) {
	jsonString := `{"FirstName":"M","MiddleNmae":"Khoiru","LastName":"Tobi","Age":21,"Married":false,"Hobbies":["gaming","reading","coding"]}`
	jsonBytes := []byte(jsonString)

	customer := &Customer{}
	err := json.Unmarshal(jsonBytes, customer)
	if err != nil {
		panic(err)
	}

	fmt.Println(customer)
	fmt.Println(customer.LastName)
	fmt.Println(customer.Hobbies)
}

func TestJSONArrayComplex(t *testing.T) {
	customer := &Customer{
		LastName: "Tobi",
		Addresses: []Address{
			{
				Street:     "Belum ada",
				Country:    "Indo",
				PostalCode: "123",
			},
			{
				Street:     "Belum ada apa apa",
				Country:    "Indo",
				PostalCode: "12345",
			},
		},
	}

	bytes, _ := json.Marshal(customer)
	fmt.Println(string(bytes))
}

func TestJSONArrayComplexDecode(t *testing.T) {
	jsonString := `{"FirstName":"","MiddleNmae":"","LastName":"Tobi","Age":0,"Married":false,"Hobbies":null,"Adresses":[{"Street":"Belum ada","Country":"Indo","PostalCode":"123"},{"Street":"Belum ada apa apa","Country":"Indo","PostalCode":"12345"}]}`

	jsonBytes := []byte(jsonString)

	customer := &Customer{}
	err := json.Unmarshal(jsonBytes, customer)
	if err != nil {
		panic(err)
	}

	fmt.Println(customer)
	fmt.Println(customer.LastName)
	fmt.Println(customer.Addresses)
}

func TestOnlyJSONArrayComplexDecode(t *testing.T) {
	jsonString := `[{"Street":"Belum ada","Country":"Indo","PostalCode":"123"},{"Street":"Belum ada apa apa","Country":"Indo","PostalCode":"12345"}]`

	jsonBytes := []byte(jsonString)

	addresses := &[]Address{}
	err := json.Unmarshal(jsonBytes, addresses)
	if err != nil {
		panic(err)
	}

	fmt.Println(addresses)
}

func TestOnlyJSONArrayComplex(t *testing.T) {
	Addresses := &[]Address{
		{
			Street:     "Belum ada",
			Country:    "Indo",
			PostalCode: "123",
		},
		{
			Street:     "Belum ada apa apa",
			Country:    "Indo",
			PostalCode: "12345",
		},
	}

	bytes, _ := json.Marshal(Addresses)
	fmt.Println(string(bytes))
}
