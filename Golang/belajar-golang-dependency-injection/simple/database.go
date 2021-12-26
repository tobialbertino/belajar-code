package simple

type Database struct {
	Name string
}

type DatabaseMongoDB Database
type DatabasePosgreSQL Database

func NewDatabaseMongoDB() *DatabaseMongoDB {
	return (*DatabaseMongoDB)(&Database{Name: "MongoDB"})
}

func NewDatabasePosgreSQL() *DatabasePosgreSQL {
	return (*DatabasePosgreSQL)(&Database{Name: "PosgreSQL"})
}

type DatabaseRepository struct {
	DatabasePostgreSQL *DatabasePosgreSQL
	DatabaseMongoDB    *DatabaseMongoDB
}

func NewDatabaseRepository(postgreSQL *DatabasePosgreSQL, mongoDB *DatabaseMongoDB) *DatabaseRepository {
	return &DatabaseRepository{DatabasePostgreSQL: postgreSQL, DatabaseMongoDB: mongoDB}
}
