package tree

import "fmt"

var Count int

// Node represent the components of a ninary search tree
type Node struct {
	Key   int
	Left  *Node
	Right *Node
}

// insert, will add noed to the tree
// the key to add should not be already in the tree
func (n *Node) Insert(k int) {
	if k > n.Key {
		// move right
		if n.Right == nil {
			n.Right = &Node{Key: k}
		} else {
			n.Right.Insert(k)
		}
	} else if k < n.Key {
		// move left
		if n.Left == nil {
			n.Left = &Node{Key: k}
		} else {
			n.Left.Insert(k)
		}
	}
}

// search, will take in a key value
// and return true if there is a node with that value
func (n *Node) Search(k int) bool {
	Count++

	if n == nil {
		return false
	}

	if k > n.Key {
		// move right
		return n.Right.Search(k)
	} else if k < n.Key {
		// move left
		return n.Left.Search(k)
	}

	return true
}

func TestBinary() {
	tree := &Node{Key: 100}
	tree.Insert(200)
	tree.Insert(50)
	fmt.Println(tree)

	tree.Insert(20)
	tree.Insert(60)
	tree.Insert(300)
	tree.Insert(350)
	fmt.Println(tree.Search(1000))
	fmt.Println(Count)
}
