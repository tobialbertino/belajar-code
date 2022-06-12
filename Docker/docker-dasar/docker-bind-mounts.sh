# Add mount data to host source 

# add env docker container 
docker container create --name mongodata --publish 27018:27017 --mount "type=bind,source=/mnt/c/Users/TOBI/Documents/Github-belajar-code/belajar-code/Docker/docker-dasar/mongo-data,destination=/data/db" --env MONGO_INITDB_ROOT_USERNAME="test" --env MONGO_INITDB_ROOT_PASSWORD="test" mongo:latest