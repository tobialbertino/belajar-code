package heap

import "fmt"

// MaxHeap struct, has a slice that holds the array
type MaxHeap struct {
	Array []int
}

// Insert, adds an element to the heap
func (h *MaxHeap) Insert(key int) {
	h.Array = append(h.Array, key)
	h.MaxHeapifyUp(len(h.Array) - 1)
}

// Extract return the largest key, and remove it from the heap
func (h *MaxHeap) Extract() int {
	extraced := h.Array[0]
	last := len(h.Array) - 1

	// when array empty
	if len(h.Array) == 0 {
		fmt.Println("cannot extract bacause array length is 0")
		return -1
	}
	// take out last index and put it in the root
	h.Array[0] = h.Array[last]
	h.Array = h.Array[:last]

	h.MaxHeapifyDown(0)

	return extraced
}

// MaxHeapifyDown will heapify top to bottom
func (h *MaxHeap) MaxHeapifyDown(index int) {
	lastIndex := len(h.Array) - 1
	l, r := left(index), right(index)
	childToCompare := 0
	// loop while index has at least one child
	for l <= lastIndex {
		if l == lastIndex { // when left child is the only child
			childToCompare = l
		} else if h.Array[l] > h.Array[r] { // when left child larger
			childToCompare = l
		} else { // when right child is larger
			childToCompare = r
		}

		// compare array value of current index to larger child and swap if smaller
		if h.Array[index] < h.Array[childToCompare] {
			h.Swap(index, childToCompare)
			index = childToCompare
			l, r = left(index), right(index)
		} else {
			return
		}
	}

}

// MaxHeapifyUp will heapify from bottom to top
func (h *MaxHeap) MaxHeapifyUp(index int) {
	for h.Array[parent(index)] < h.Array[index] {
		h.Swap(parent(index), index)
		index = parent(index)
	}
}

// get the parent index
func parent(i int) int {
	return (i - 1) / 2
}

// get the left child index
func left(i int) int {
	return i*2 + 1
}

// get the right child index
func right(i int) int {
	return i*2 + 2
}

// swap keys in the array

func (h *MaxHeap) Swap(i1, i2 int) {
	h.Array[i1], h.Array[i2] = h.Array[i2], h.Array[i1]
}

func TestMaxHeap() {
	m := &MaxHeap{}

	buildHeap := []int{10, 20, 30, 5, 7, 9, 11, 13, 15, 17}

	for _, v := range buildHeap {
		m.Insert(v)
		fmt.Println(m)
	}

	for i := 0; i < 5; i++ {
		m.Extract()
		fmt.Println(m)
	}
}
