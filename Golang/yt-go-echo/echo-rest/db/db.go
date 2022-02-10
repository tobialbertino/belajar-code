package db

import (
	"database/sql"
	"echo-rest/config"

	_ "github.com/go-sql-driver/mysql"
)

var db *sql.DB
var err error

func Init() {
	conf := config.GetConfig()

	connectionString := conf.DB_USERNAME + ":" + conf.DB_PASSWORD + "@tcp(" + conf.DB_HOST + ":" + conf.DB_PORT + ")/" + conf.DB_NAME
	// username:password@protocol(address:3306)/dbname?param=value

	db, err = sql.Open("mysql", connectionString)
	if err != nil {
		panic("connectionString error")
	}

	err = db.Ping()
	if err != nil {
		panic("DSN Invalid")
	}

}

func CreateConnection() *sql.DB {
	return db
}
