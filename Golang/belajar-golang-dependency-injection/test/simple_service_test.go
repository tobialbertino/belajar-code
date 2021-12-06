package test

import (
	"fmt"
	"programmerzamannow/belajar-golang-restful-api/simple"
	"testing"
)

func TestSimpleService(t *testing.T) {
	simpleService, err := simple.InitializeService()
	fmt.Println(err)
	fmt.Println(simpleService.SimpleRepository)
}
