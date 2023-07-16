package gogeneric

import (
	"fmt"
	"testing"
)

type Bag[T any] []T

func PrintBag[T any](bag Bag[T]) {
	for _, value := range bag {
		fmt.Println(value)
	}
}

func TestPrintBagString(t *testing.T) {
	names := Bag[string]{"M", "Khoitu", "Tobi"}
	PrintBag(names)
}

func TestPrintBagInt(t *testing.T) {
	names := Bag[int]{1, 2, 3, 4, 5}
	PrintBag(names)
}
