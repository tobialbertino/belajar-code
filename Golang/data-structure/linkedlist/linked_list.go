package linkedlist

import (
	"fmt"
)

type Node struct {
	Data int
	Next *Node
}

type LinkedList struct {
	Head   *Node
	Length int
}

func (l *LinkedList) PrePend(n *Node) {
	second := l.Head
	l.Head = n
	l.Head.Next = second
	l.Length++
}

func (l *LinkedList) DeleteWithValue(value int) {
	if l.Length == 0 {
		return
	}

	if l.Head.Data == value {
		l.Head = l.Head.Next
		l.Length--
		return
	}
	previousToDelete := l.Head

	for previousToDelete.Next.Data != value {
		previousToDelete = previousToDelete.Next
		if previousToDelete.Next == nil {
			return
		}
	}

	previousToDelete.Next = previousToDelete.Next.Next
	l.Length--
}

func (l LinkedList) PrintDataList() {
	toPrint := l.Head
	for i := 0; i < l.Length; i++ {
		fmt.Printf("%v \n", toPrint.Data)
		toPrint = toPrint.Next
	}
}
