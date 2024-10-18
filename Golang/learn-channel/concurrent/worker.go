package concurrent

import (
	"fmt"
	"sync"
	"time"
)

func worker(id int, jobs <-chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	for j := range jobs {
		fmt.Println("worker", id, "started  job", j)
		time.Sleep(time.Second) // Simulate job processing time
		fmt.Println("worker", id, "finished job", j)
	}
}

func MainWorker() {

	const numJobs = 5
	const numWorker = 3
	wg := new(sync.WaitGroup)
	jobs := make(chan int, numJobs)

	// Start the workers
	for w := 1; w <= numWorker; w++ {
		wg.Add(1)
		go worker(w, jobs, wg)
	}

	// Send jobs to the workers
	for j := 1; j <= numJobs; j++ {
		jobs <- j
	}
	// Close the jobs channel after sending all jobs
	close(jobs)

	// Wait for all workers to finish
	wg.Wait()
}
