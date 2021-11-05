package database

import (
	"database/sql"
	"fmt"
	"testing"

	_ "github.com/go-sql-driver/mysql"
)

func TestEmpty(t *testing.T) {
	fmt.Println("")
}

func TestOpenConnection(t *testing.T) {
	db, err := sql.Open("mysql", "root:mysql@tcp(localhost:3306)/belajar_golang_database")
	if err != nil {
		panic(err)
	}
	defer db.Close()

	// Use database

}
