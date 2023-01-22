package trie

import (
	"fmt"
)

// AlphaberSize is the number of possible character in the trie
const AlphaberSize = 26

// Node
type Node struct {
	Children [AlphaberSize]*Node
	IsEnd    bool
}

// Trie represent a trie and has a pointer to the root node
type Trie struct {
	Root *Node
}

// Init trie will create new trie
func InitTrie() *Trie {
	result := &Trie{&Node{}}
	return result
}

// Insert will take in a word and add it to the trie, only lowercase
func (t *Trie) Insert(w string) {
	WordLength := len(w)
	currentNode := t.Root

	for i := 0; i < WordLength; i++ {
		charIndex := w[i] - 'a' // convert Ascii alphabet to range[0:26]
		if currentNode.Children[charIndex] == nil {
			currentNode.Children[charIndex] = &Node{}
		}
		currentNode = currentNode.Children[charIndex]
	}
	currentNode.IsEnd = true
}

// Search will take in a word and return true is that word included in the trie
func (t *Trie) Search(w string) bool {
	WordLength := len(w)
	currentNode := t.Root

	for i := 0; i < WordLength; i++ {
		charIndex := w[i] - 'a'
		if currentNode.Children[charIndex] == nil {
			return false
		}
		currentNode = currentNode.Children[charIndex]
	}
	return currentNode.IsEnd

}

func TestTrie() {
	myTrie := InitTrie()

	toAdd := []string{
		"aragorn",
		"aragon",
		"argon",
		"eragon",
		"oregio",
		"oregane",
		"oreo",
	}

	for _, v := range toAdd {
		myTrie.Insert(v)
	}

	fmt.Println(myTrie.Search("adsasf"))
}
