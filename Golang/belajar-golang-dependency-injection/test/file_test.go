package test

import (
	"programmerzamannow/belajar-golang-restful-api/simple"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestConnection(t *testing.T) {
	connection, cleanUp := simple.InitializedConnection("Database")
	assert.NotNil(t, connection)

	cleanUp()
}
