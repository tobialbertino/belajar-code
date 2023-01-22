package hashtable

import "fmt"

const ArraySize = 7

// Hashtable structure, will hold an array
type Hashtable struct {
	Array [ArraySize]*Bucket
}

// Bucket structure, implement linked_list
type Bucket struct {
	Head *BucketNode
}

// BucketNode structure, linked_list node structure
type BucketNode struct {
	Key  string
	Next *BucketNode
}

// hash section
// Insert, will take in a key and add it to the hash table array
func (h *Hashtable) Insert(key string) {
	index := hash(key)
	h.Array[index].insert(key)
}

// Search
func (h *Hashtable) Search(key string) bool {
	index := hash(key)
	return h.Array[index].search(key)
}

// Delete
func (h *Hashtable) Delete(key string) {
	index := hash(key)
	h.Array[index].delete(key)
}

// linked_list section
// Insert, will take in a key, create a node with the key and insert the node in the bucket
func (b *Bucket) insert(k string) {
	if !b.search(k) {
		newNode := &BucketNode{Key: k}
		newNode.Next = b.Head
		b.Head = newNode
	} else {
		fmt.Print(k, "already exist")
	}
}

// Search, will take in a key and return true if the bucket has that key
func (b *Bucket) search(k string) bool {
	currentNode := b.Head
	for currentNode != nil {
		if currentNode.Key == k {
			return true
		}

		currentNode = currentNode.Next
	}

	return false
}

// Delete, will take in a key and delete the node from the Bucket
func (b *Bucket) delete(k string) {
	if b.Head.Key == k {
		b.Head = b.Head.Next
		return
	}

	previousNode := b.Head
	for previousNode.Next != nil {
		if previousNode.Next.Key == k {
			previousNode.Next = previousNode.Next.Next
		}

		previousNode = previousNode.Next
	}

}

// hash
func hash(key string) int {
	sum := 0
	for _, v := range key {
		sum += int(v)
	}

	return sum % ArraySize
}

// Init, will create a Bucket in each slot of the hash table
func Init() *Hashtable {
	result := &Hashtable{}

	for i := range result.Array {
		result.Array[i] = &Bucket{}
	}

	return result
}

func TestHash() {
	hashTable := Init()
	list := []string{
		"ERIC",
		"KENNY",
		"RANDY",
		"KYLE",
		"STAN",
		"BUTTERS",
		"TOKEN",
	}

	for _, v := range list {
		hashTable.Insert(v)
	}

	hashTable.Delete("STAN")
	fmt.Println("STAN", hashTable.Search("STAN"))
	fmt.Println("RANDY", hashTable.Search("RANDY"))
}
