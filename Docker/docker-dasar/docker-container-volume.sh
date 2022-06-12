docker volume create mongodata

# Add mount data to volume docker

# add env docker container using volume docker
docker container create --name mongovolume --publish 27019:27017 --mount "type=volume,source=mongodata,destination=/data/db" --env MONGO_INITDB_ROOT_USERNAME="test" --env MONGO_INITDB_ROOT_PASSWORD="test" mongo:latest

docker container stop mongovolume

docker container rm mongovolume