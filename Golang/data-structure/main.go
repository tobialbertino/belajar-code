package main

import (
	"data-structure/graph"
	"data-structure/hashtable"
	"data-structure/heap"
	"data-structure/linkedlist"
	"data-structure/stackqueue"
	"data-structure/tree"
	"data-structure/trie"
)

func main() {
	graph.TestGraph()
}

// temp code
func TestHeap() {
	heap.TestMaxHeap()
}

func TestHash() {
	hashtable.TestHash()
}

func TestTrie() {
	trie.TestTrie()
}

func TestTree() {
	tree.TestBinary()
}

func TestStackQueue() {
	stackqueue.TestStack()
	stackqueue.TestQueue()
}

func TestLinkedList() {
	// linked_list
	myList := linkedlist.LinkedList{}
	node1 := &linkedlist.Node{Data: 1}
	node2 := &linkedlist.Node{Data: 2}
	node3 := &linkedlist.Node{Data: 3}
	node4 := &linkedlist.Node{Data: 4}
	node5 := &linkedlist.Node{Data: 5}
	myList.PrePend(node1)
	myList.PrePend(node2)
	myList.PrePend(node3)
	myList.PrePend(node4)
	myList.PrePend(node5)
	myList.PrintDataList()
	println("________")

	myList.DeleteWithValue(1)
	// case no value
	myList.DeleteWithValue(23)
	myList.PrintDataList()

	// case null linked_list
	emptyList := linkedlist.LinkedList{}
	emptyList.DeleteWithValue(9)
	emptyList.PrintDataList()
}
