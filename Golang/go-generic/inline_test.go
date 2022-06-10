package gogeneric

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func FindMin[T interface{ int | int64 | float64 }](first, second T) T {
	if first < second {
		return first
	} else {
		return second
	}
}

func TestFindMin(t *testing.T) {
	assert.Equal(t, 100, FindMin(200, 100))
	assert.Equal(t, int64(100), FindMin[int64](200, 100))
	assert.Equal(t, float64(100), FindMin[float64](200, 100))
}

func GetFirst[T []E, E any](slice T) E {
	first := slice[0]
	return first
}

func TestGetFirst(t *testing.T) {
	names := []string{
		"Tobi", "Albertino",
	}

	first := GetFirst(names)
	assert.Equal(t, "Tobi", first)
}
