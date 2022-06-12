docker network create --driver bridge mongonetwork

docker container create --name mongodb --network mongonetwork --env MONGO_INITDB_ROOT_USERNAME="test" --env MONGO_INITDB_ROOT_PASSWORD="test" mongo:latest

docker image pull mongo-express:latest

docker container create --name mongodbexpress --network mongonetwork --publish 8081:8081 --env ME_CONFIG_MONGODB_URL="mongodb://test:test@mongodb:27017/" mongo-express:latest

docker container start mongodb
docker container start mongodbexpress

# disconnect network connection 
docker network disconnect networkName containerName
docker network disconnect mongonetwork mongodb

# add network to container
docker network connect networkName containerName
docker network connect mongonetwork mongodb