package main

import (
	"container/ring"
	"fmt"
	"strconv"
)

func main() {
	var data *ring.Ring = ring.New(5)

	data.Value = "Tobi"

	// var data2 = data.Next()
	// data2.Value = "Albertino"

	for i := 0; i < data.Len(); i++ {
		data.Value = "Data" + strconv.FormatInt(int64(i), 10)
		data = data.Next()
	}

	data.Do(func(value interface{}) {
		fmt.Println(value)
	})

}
