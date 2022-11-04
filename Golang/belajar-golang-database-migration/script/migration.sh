migrate create -ext sql -dir db/migrations create_table_category

migrate -database "mysql://root:mysql@tcp(localhost:3306)/belajar_golang_database_migration" -path db/migrations up

migrate -database "mysql://root:mysql@tcp(localhost:3306)/belajar_golang_database_migration" -path db/migrations down

# force dirty state to cer...
migrate -database "mysql://root:mysql@tcp(localhost:3306)/belajar_golang_database_migration" -path db/migrations force ver

# check version 
migrate -database "mysql://root:mysql@tcp(localhost:3306)/belajar_golang_database_migration" -path db/migrations version

# additional task
migrate create -ext sql -dir db/migrations create_table_first
migrate create -ext sql -dir db/migrations create_table_second
migrate create -ext sql -dir db/migrations create_table_third

migrate create -ext sql -dir db/migrations sample_dirty_state