# list network 
docker network sh

# create network 
docker network create --driver driverName networkName
# examplem
docker network create --driver bridge contohnetwork

# remove network 
# note: make sure not to use the network
docker network rm networkName