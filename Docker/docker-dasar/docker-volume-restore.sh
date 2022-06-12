docker volume create mongorestore

docker container run --rm --name ubunturestore --mount "type=bind,source=/mnt/c/Users/TOBI/Documents/Github-belajar-code/belajar-code/Docker/docker-dasar/backup,destination=/backup" --mount "type=volume,source=mongorestore,destination=/data" ubuntu:latest bash -c "cd /data && tar xvf /backup/backup.tar.gz --strip 1"

# test restore file 
docker container create --name mongorestore --publish 27020:27017 --mount "type=volume,source=mongorestore,destination=/data/db" --env MONGO_INITDB_ROOT_USERNAME="test" --env MONGO_INITDB_ROOT_PASSWORD="test" mongo:latest

docker container start mongorestore