package gogeneric

import (
	"testing"

	"github.com/stretchr/testify/assert"
	"golang.org/x/exp/constraints"
	"golang.org/x/exp/maps"
	"golang.org/x/exp/slices"
)

func ExperimentalMin[T constraints.Ordered](first, second T) T {
	if first < second {
		return first
	} else {
		return second
	}
}

func TestExperimentalMin(t *testing.T) {
	assert.Equal(t, 100, ExperimentalMin(300, 100))
	assert.Equal(t, 100.0, ExperimentalMin(300.0, 100.0))
}

func TestExperimentalMaps(t *testing.T) {
	first := map[string]string{
		"Name": "Tobi",
	}
	second := map[string]string{
		"Name": "Tobi",
	}

	assert.True(t, maps.Equal(first, second))
}

func TestExperimentalSlice(t *testing.T) {
	first := []string{"Tobi"}
	second := []string{"Tobi"}

	assert.True(t, slices.Equal(first, second))
}
