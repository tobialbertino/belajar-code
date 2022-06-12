# add env docker container 
docker container create --name contohmongo --publish 27017:27017 --env MONGO_INITDB_ROOT_USERNAME="test" --env MONGO_INITDB_ROOT_PASSWORD="test" mongo:latest