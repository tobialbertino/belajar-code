package concurrent

import (
	"fmt"
	"sync"
)

func SimpleCH() {
	const LenChan = 10
	jobs := make(chan int, LenChan)
	wg := new(sync.WaitGroup)

	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := 0; i < LenChan; i++ {
			jobs <- i
		}

		close(jobs)
	}()

	go func() {
		wg.Wait()
	}()

	for val := range jobs {
		fmt.Println(val)
	}
}

func ping(pings chan<- string, msg string) {
	pings <- msg
}

func pong(pings <-chan string, pongs chan<- string) {
	msg := <-pings
	pongs <- msg
}

func PingPong() {
	pings := make(chan string, 1)
	pongs := make(chan string, 1)

	ping(pings, "passed message everything is fine")
	pong(pings, pongs)

	fmt.Println(<-pongs)
}
