docker build -t tobialbertino/redis:v1 .

docker image inspect tobialbertino/redis:v1

docker container create --name redisDocker -p 6379:6379 tobialbertino/redis:v1 

docker container start redisDocker
docker container logs redisDocker
docker container stop redisDocker
docker container rm redisDocker

redis-cli -h 127.0.0.1 -p 6379
auth tobi secret

# Redis pipeline 
redis-cli -h localhost -p 6379 -n 0 --pipe < input-bulk.txt

# Redis Transaction, 
multi # start transaction
set apple "Apple"
set samsung "Samsung"
set xiaomi "Xiaomi"
exec # commit transaction

# Redis Transaction, discard
multi # start transaction
set apple "Apple"
set samsung "Samsung"
set xiaomi "Xiaomi"
discard # rollback transaction

# Redis Monitor 
monitor # Listen for all request received by the server in real time

# Redis Server Information
info # Get information and statistics about the server
config get <key> # Get the value of a configuration parameter from redis.conf

# Redis Client Connection
client list # get the list og client connections
client id # Returns the client ID for the current connection
client kill ip:port # Kill the connection of a client


