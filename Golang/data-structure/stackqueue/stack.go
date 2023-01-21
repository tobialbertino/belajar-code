package stackqueue

import "fmt"

// stack represents stack that hold a slice
type Stack struct {
	Items []int
}

// push, will add value at the end
func (s *Stack) Push(i int) {
	s.Items = append(s.Items, i)
}

// pop, will remove value at the end
// and return the removed value
func (s *Stack) Pop() int {
	lenStack := len(s.Items) - 1
	toRemove := s.Items[lenStack]
	s.Items = s.Items[:lenStack]
	return toRemove
}

func TestStack() {
	myStack := Stack{}
	myStack.Push(100)
	myStack.Push(200)
	myStack.Push(300)
	fmt.Println(myStack)

	myStack.Pop()
	fmt.Println(myStack)

}
