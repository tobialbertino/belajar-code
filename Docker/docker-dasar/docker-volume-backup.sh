docker container stop mongovolume

docker container create --name nginxbackup --mount "type=bind,source=/mnt/c/Users/TOBI/Documents/Github-belajar-code/belajar-code/Docker/docker-dasar/backup,destination=/backup" --mount "type=volume,source=mongodata,destination=/data" nginx:latest

docker container start nginxbackup

docker container exec -i -t nginxbackup /bin/bash

# archive data to backup 
tar cvf /backup/backup.tar.gz /data

docker container stop nginxbackup 

docker container rm nginxbackup

docker container start mongovolume

# In 1 task 
docker container stop mongovolume

docker container run --rm --name ubuntubackup --mount "type=bind,source=/mnt/c/Users/TOBI/Documents/Github-belajar-code/belajar-code/Docker/docker-dasar/backup,destination=/backup" --mount "type=volume,source=mongodata,destination=/data" ubuntu:latest tar cvf /backup/backup-lagi.tar.gz /data


# helper pwd
C:/Users/TOBI/Documents/Github-belajar-code/belajar-code/Docker/docker-dasar/backup
/mnt/c/Users/TOBI/Documents/Github-belajar-code/belajar-code/Docker/docker-dasar/backup