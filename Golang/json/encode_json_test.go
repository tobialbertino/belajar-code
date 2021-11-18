package json

import (
	"encoding/json"
	"fmt"
	"testing"
)

func logJson(data interface{}) {
	bytes, err := json.Marshal(data)
	if err != nil {
		panic(err)
	}
	fmt.Println(string(bytes))
}

func Test(t *testing.T) {
	logJson("Tobi")
	logJson(5)
	logJson(true)
	logJson([]string{"M", "Khoiru", "Tobi"})
}
