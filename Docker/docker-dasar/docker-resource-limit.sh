# set limit resource --memory --cpu
docker container create --name containerName --memory 100m --cpus 1.5 --publish portHsot:portContainer image:tag

# example 
docker container create --name smallnginx --memory 100m --cpus 1.5 --publish 8081:80 nginx:latest