package helper

import (
	"fmt"
	"runtime"
	"testing"

	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func BenchmarkTable(b *testing.B) {
	benchmarks := []struct {
		name    string
		request string
	}{
		{
			name:    "Tobi",
			request: "Tobi",
		},
		{
			name:    "Albertino",
			request: "Albertino",
		},
		{
			name:    "Muhamad Khoiru Tobi Albertino",
			request: "Muhamad Khoiru Tobi Albertino",
		},
	}

	for _, benchmark := range benchmarks {
		b.Run(benchmark.name, func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				HelloWorld(benchmark.request)
			}
		})
	}
}

func BenchmarkSub(b *testing.B) {
	b.Run("Tobi", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			HelloWorld("Tobi")
		}
	})
	b.Run("Albertino", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			HelloWorld("Albertino")
		}
	})
}

func BenchmarkHelloWorld(b *testing.B) {
	for i := 0; i < b.N; i++ {
		HelloWorld("Tobi")
	}
}

func BenchmarkHelloWorldAlbertino(b *testing.B) {
	for i := 0; i < b.N; i++ {
		HelloWorld("Albertino")
	}
}

func TestTableHelloWorld(t *testing.T) {
	tests := []struct {
		name     string
		request  string
		expected string
	}{
		{
			name:     "Tobi",
			request:  "Tobi",
			expected: "Hello Tobi",
		},
		{
			name:     "Albertino",
			request:  "Albertino",
			expected: "Hello Albertino",
		},
		{
			name:     "Joko",
			request:  "Joko",
			expected: "Hello Joko",
		},
	}

	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			result := HelloWorld(test.request)
			require.Equal(t, test.expected, result)
		})
	}
}

func TestSubTest(t *testing.T) {
	t.Run("Tobi", func(t *testing.T) {
		result := HelloWorld("Tobi")
		assert.Equal(t, "Hello Tobi", result, "result must be 'Hello Tobi") // Error
	})
	t.Run("Albertino", func(t *testing.T) {
		result := HelloWorld("Albertino")
		assert.Equal(t, "Hello Albertino", result, "result must be 'Hello Albertino") // Error
	})
}

func TestMain(m *testing.M) {
	// before
	fmt.Println("BEFORE Unit Test")

	m.Run()

	// after
	fmt.Println("AFTER Unit Test")
}

func TestSkip(t *testing.T) {
	if runtime.GOOS == "darwin" {
		t.Skip("Cannot run on Mac OS")
	}
}

func TestHelloWorldRequire(t *testing.T) {
	result := HelloWorld("Tobi")
	require.Equal(t, "Hello Tobi", result, "result must be 'Hello Tobi") // FailNow
	fmt.Println("TestHelloWorldRequire Done")
}

func TestHelloWorldAssert(t *testing.T) {
	result := HelloWorld("Tobi")
	assert.Equal(t, "Hello Tobi", result, "result must be 'Hello Tobi") // Error
	fmt.Println("TestHelloWorldAssert Done")
}

func TestHelloWorldTobi(t *testing.T) {
	result := HelloWorld("Tobi")

	if result != "Hello Tobi" {
		// error
		t.Error("Must be Hello 'Tobi'")
	}
	fmt.Println("Test TestHelloWorldTobi Done")
}

func TestHelloWorldALbertino(t *testing.T) {
	result := HelloWorld("Albertino")

	if result != "Hello Albertino" {
		// error
		t.Error("Must be Hello 'Albertino'")
	}
	fmt.Println("Test TestHelloWorldTobi Done")
}
