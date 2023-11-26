# List Structure
lpush queue "Tobi"
lpush queue "Budi"
lpush queue "Joko"
# Joko
# Budi 
# Tobi
lrange queue 0 10
rpop queue 1 # remove Tobi
rpop queue 1 # remove Budi
rpop queue 1 # remove Joko
lrange queue 0 10


lpush stack "Tobi"
lpush stack "Budi"
lpush stack "Joko"
# Joko
# Budi 
# Tobi
lrange stack 0 10
lpop stack 1 # remove Joko
lpop stack 1 # remove Budi
lpop stack 1 # remove Tobi
lrange stack 0 10

# Sets Structure 
sadd race Eko Budi Joko
sadd race Joko Budi Ruli
scard race
smembers race 
srem race Eko Tobi
sadd race2 Budi Nugraha Joko Morro
sadd race3 Joko Morro Rully Hidayat
sdiff race2 race3 
sinter race2 race3
sunion race2 race3

# Hashes structure 
hset "student:1" name "Tobi Albertino" value 100 address "Tangerang"
hset "student:2" name "ALbertino Tobi" value 100 address "Jakarta"
hgetall "student:1"
hgetall "student:2"
hget "student:2" name
hget "student:2" value
hget "student:2" address
hset "student:2" value 99

hincrby "student:1" value -10
hincrby "student:2" value -5
hincrby "student:2" value 1

# Sorted Set Structure 
zadd rangking 100 Eko
zadd rangking 90 Budi
zadd rangking 95 Joko
zcard rangking
zrange rangking 0 2
zrange rangking 95 100 byscore
zrange rangking 0 -1 withscore # (0 -1) -> all range
zrem rangking eko
zremrangebyscore rangking 0 75

# Stream structure 
xadd application.log * level "info" message "contoh info message"
xadd application.log * level "error" message "contoh error message"
xadd application.log * level "warning" message "contoh warning message"
xread count 10 streams application.log 0 

# consumer group
xgroup create registration member $ mkstream
xgroup createconsumer registration member member-consumer-1
xgroup createconsumer registration member member-consumer-2
xadd registration * userID1
xadd registration * userID2
xadd registration * userID3
xadd registration * userID4

xreadgroup group member member-consumer-1 count 1 block 0 streams registration >
xreadgroup group member member-consumer-2 count 1 block 0 streams registration >

# Geospatial structure 
geoadd seller.location 106.823021 -6.176722 seller1
geoadd seller.location 106.823022 -6.176723 seller2
geopos seller.location seller1
geopos seller.location seller2
geodist seller.location seller1 seller2 km
geodist seller.location seller1 seller2 m
geosearch seller.location fromlonlat 106.823023 -6.176723 byradius 1 km

# HyperLogLog structure 
pfadd visitor joko budi ruli
pfadd visitor eko sinta santi
pfcount visitor
