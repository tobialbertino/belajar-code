# list all docker container 
docker container ls -a

# list docker container is running true
docker container ls

# create docker container 
docker container create --name containerName ImageName:tag

# run container 
docker container start containerId/containerName

# stop container 
docker container stop containerId/containerName

# remove container 
docker container rm containerId/containerName