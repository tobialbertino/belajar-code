# FROM INSTRUCTION 
docker build -t tobialbertino/from from

docker image ls

# RUN INSTRUCTION 
docker build -t tobialbertino/run run

docker build -t tobialbertino/run run --progress=plain --no-cache
# filer images by name 
docker images | grep tobi

# CMD INSTRUCTION 
docker build -t tobialbertino/command command

docker image inspect tobialbertino/command

docker container create --name command tobialbertino/command 
docker container start command
docker container logs command

# LABEL INSTRUCTION
docker build -t tobialbertino/label label

docker image inspect tobialbertino/label

# ADD INSTRUCTION 
docker build -t tobialbertino/add add

docker container create --name add tobialbertino/add 
docker container start add
docker container logs add

# COPY INSTRUCTION 
docker build -t tobialbertino/copy copy

docker container create --name copy tobialbertino/copy 
docker container start copy
docker container logs copy

# .dockerignore INSTRUCTION 
docker build -t tobialbertino/ignore ignore

docker container create --name ignore tobialbertino/ignore 
docker container start ignore
docker container logs ignore

# EXPOSE INSTRUCTION 
docker build -t tobialbertino/expose expose

docker image inspect tobialbertino/expose

docker container create --name expose -p 8080:8080 tobialbertino/expose 
docker container start expose
docker container logs expose
docker container stop expose

# ENV INSTRUCTION 
docker build -t tobialbertino/env env

docker image inspect tobialbertino/env

docker container create --name env --env APP_PORT=9090 -p 9090:9090 tobialbertino/env 
docker container start env
docker container logs env
docker container stop env
docker container rm env

# VOLUME INSTRUCTION 
docker build -t tobialbertino/volume volume

docker image inspect tobialbertino/volume

docker container create --name volume --env APP_PORT=9090 -p 9090:9090 tobialbertino/volume 
docker container start volume
docker container logs volume
docker container stop volume

docker container inspect volume
docker volume ls

# WORKDIR INSTRUCTION 
docker build -t tobialbertino/workdir workdir

docker image inspect tobialbertino/workdir

docker container create --name workdir -p 8080:8080 tobialbertino/workdir 
docker container start workdir
docker container exec -i -t workdir /bin/sh
docker container logs workdir
docker container stop workdir

docker container inspect workdir

# USER INSTRUCTION 
docker build -t tobialbertino/user user

docker container create --name user -p 8080:8080 tobialbertino/user 
docker container start user
docker container exec -i -t user /bin/sh
docker container stop user

# ARG INSTRUCTION 
docker build -t tobialbertino/arg arg --build-arg app=helloworld

docker container create --name arg -p 8080:8080 tobialbertino/arg 
docker container start arg
docker container exec -i -t arg /bin/sh
docker container logs arg
docker container stop arg

# HEATHCHECK INSTRUCTION 
docker build -t tobialbertino/health health

docker container create --name health -p 8080:8080 tobialbertino/health 
docker container start health
docker container ls
docker container inspect health
docker container stop health

# ENTRYPOINT INSTRUCTION 
docker build -t tobialbertino/entrypoint entrypoint

docker container create --name entrypoint -p 8080:8080 tobialbertino/entrypoint 
docker container start entrypoint
docker container ls
docker container inspect entrypoint
docker container stop entrypoint

# MULTI STAGE BUILD INSTRUCTION 
docker build -t tobialbertino/multi multi

docker container create --name multi -p 8080:8080 tobialbertino/multi 
docker container start multi
docker container ls
docker container inspect multi
docker container stop multi

# PUSH DOCKER HUB 
docker push usernameImage

# PUSH DOCKER IMAGE DIGITAL OCEAN 
docker tag tobialbertino/multi registry.digitalocean.com/tobialbertino/multi
docker --config /Users/tobi/.docker-digital-ocean/ push tobialbertino/multi