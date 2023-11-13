docker build -t tobialbertino/redis:v1 .

docker image inspect tobialbertino/redis:v1

docker container create --name redisDocker -p 6379:6379 tobialbertino/redis:v1 

docker container rm redisDocker
docker container start redisDocker
docker container logs redisDocker
docker container stop redisDocker