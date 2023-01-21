package stackqueue

import "fmt"

// Queue represents Queue that holds a slice
type Queue struct {
	Items []int
}

// Enqueue add a value at the end
func (q *Queue) Enqueue(i int) {
	q.Items = append(q.Items, i)
}

// Dequeue, Remove a value at the first
// and return removed value
func (q *Queue) Dequeue() int {
	toRemove := q.Items[0]
	q.Items = q.Items[1:]
	return toRemove
}

func TestQueue() {
	myQueue := Queue{}
	myQueue.Enqueue(100)
	myQueue.Enqueue(200)
	myQueue.Enqueue(300)
	fmt.Println(myQueue)

	myQueue.Dequeue()
	fmt.Println(myQueue)
}
