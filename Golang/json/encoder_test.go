package json

import (
	"encoding/json"
	"os"
	"testing"
)

func TestEncoder(t *testing.T) {
	writer, _ := os.Create("customer_out.json")
	encoder := json.NewEncoder(writer)

	customer := &Customer{
		FirstName:  "M",
		MiddleNmae: "Khoiru",
		LastName:   "Tobi",
	}

	encoder.Encode(customer)
}
