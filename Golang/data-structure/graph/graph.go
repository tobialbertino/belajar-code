package graph

import "fmt"

// Graph structure, represent an adjacency list Graph
type Graph struct {
	Vertices []*Vertex
}

// Vertex structure
type Vertex struct {
	Key      int
	Adjacent []*Vertex
}

// Add Vertex
func (g *Graph) AddVertex(k int) {
	if contains(g.Vertices, k) {
		err := fmt.Errorf("Vertex %v not added because it is an existing key", k)
		fmt.Println(err.Error())
	} else {
		g.Vertices = append(g.Vertices, &Vertex{Key: k})
	}
}

// addEdge, adds an edge to the graph
func (g *Graph) AddEdge(from, to int) {
	// get vertex
	fromVertex := g.getvertex(from)
	toVertex := g.getvertex(to)
	// check error
	if fromVertex == nil || toVertex == nil {
		err := fmt.Errorf("invalid edge (%v-->%v)", from, to)
		fmt.Println(err.Error())
	} else if contains(fromVertex.Adjacent, to) {
		err := fmt.Errorf("existing edge (%v-->%v)", from, to)
		fmt.Println(err.Error())
	} else {
		// add edge
		fromVertex.Adjacent = append(fromVertex.Adjacent, toVertex)
	}
}

// GetVertex, returns a pointer to the vertex with a key integer
func (g *Graph) getvertex(k int) *Vertex {
	for i, v := range g.Vertices {
		if v.Key == k {
			return g.Vertices[i]
		}
	}
	return nil
}

// contains
func contains(s []*Vertex, k int) bool {
	for _, v := range s {
		if k == v.Key {
			return true
		}
	}
	return false
}

func (g *Graph) Print() {
	for _, v := range g.Vertices {
		fmt.Printf("\nVertex %v : ", v.Key)
		for _, v := range v.Adjacent {
			fmt.Printf(" %v", v.Key)

		}
	}
	fmt.Println()
}

func TestGraph() {
	test := &Graph{}

	for i := 0; i < 5; i++ {
		test.AddVertex(i)
	}

	test.AddEdge(1, 2)
	test.AddEdge(1, 2)
	test.AddEdge(6, 2)
	test.AddEdge(3, 2)
	test.Print()
}
