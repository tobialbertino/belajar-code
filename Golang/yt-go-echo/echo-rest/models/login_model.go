package models

import (
	"database/sql"
	"echo-rest/db"
	helper "echo-rest/helpers"
	"fmt"
)

type User struct {
	Id       int    `json:"id"`
	Username string `json:"username"`
}

func CheckLogin(username string, password string) (bool, error) {
	var obj User
	var pwd string

	connection := db.CreateConnection()

	SQL := "SELECT * FROM users WHERE username = ?"

	err := connection.QueryRow(SQL, username).Scan(
		&obj.Id, &obj.Username, &pwd,
	)
	if err == sql.ErrNoRows {
		fmt.Println("Username not found")
		return false, err
	}

	if err != nil {
		fmt.Println("Query error")
		return false, err
	}

	match, err := helper.CheckPasswordHash(password, pwd)
	if !match {
		fmt.Println("Hash and password doesn't match!")
		return false, err
	}

	return true, nil
}
