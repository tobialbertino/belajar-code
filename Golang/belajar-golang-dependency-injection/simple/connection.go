package simple

import "fmt"

type Connection struct {
	*File
}

func (c *Connection) close() {
	fmt.Println("Close Connection", c.File.Name)
}

func NewConnection(file *File) (*Connection, func()) {
	connection := &Connection{File: file}
	return connection, func() {
		connection.close()
	}
}
