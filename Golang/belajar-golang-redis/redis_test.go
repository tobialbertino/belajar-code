package belajar_golang_redis

import (
	"context"
	"github.com/redis/go-redis/v9"
	"github.com/stretchr/testify/assert"
	"testing"
	"time"
)

var client = redis.NewClient(&redis.Options{
	Addr: "localhost:6379",
	DB:   0,
})

func TestConnection(t *testing.T) {
	assert.NotNil(t, client)

	//err := client.Close()
	//assert.Nil(t, err)
}

var ctx = context.Background()

func TestPing(t *testing.T) {
	result, err := client.Ping(ctx).Result()
	assert.Nil(t, err)
	assert.Equal(t, "PONG", result)
}

func TestString(t *testing.T) {
	client.SetEx(ctx, "name", "Eko Kurniawan", 3*time.Second)

	result, err := client.Get(ctx, "name").Result()
	assert.Nil(t, err)
	assert.Equal(t, "Eko Kurniawan", result)

	time.Sleep(5 * time.Second)

	result, err = client.Get(ctx, "name").Result()
	assert.NotNil(t, err)
}

func TestList(t *testing.T) {
	client.RPush(ctx, "names", "M")
	client.RPush(ctx, "names", "Khoiru")
	client.RPush(ctx, "names", "Tobi")

	assert.Equal(t, "M", client.LPop(ctx, "names").Val())
	assert.Equal(t, "Khoiru", client.LPop(ctx, "names").Val())
	assert.Equal(t, "Tobi", client.LPop(ctx, "names").Val())

	client.Del(ctx, "names")
}

func TestSet(t *testing.T) {
	client.SAdd(ctx, "students", "Khoiru")
	client.SAdd(ctx, "students", "Khoiru")
	client.SAdd(ctx, "students", "TObi")
	client.SAdd(ctx, "students", "TObi")
	client.SAdd(ctx, "students", "Albertino")
	client.SAdd(ctx, "students", "Albertino")

	assert.Equal(t, int64(3), client.SCard(ctx, "students").Val())
	assert.Equal(t, []string{"Khoiru", "TObi", "Albertino"}, client.SMembers(ctx, "students").Val())
}

func TestSortedSet(t *testing.T) {
	client.ZAdd(ctx, "scores", redis.Z{Score: 100, Member: "Eko"})
	client.ZAdd(ctx, "scores", redis.Z{Score: 85, Member: "Budi"})
	client.ZAdd(ctx, "scores", redis.Z{Score: 95, Member: "Joko"})

	assert.Equal(t, []string{"Budi", "Joko", "Eko"}, client.ZRange(ctx, "scores", 0, -1).Val())

	assert.Equal(t, "Eko", client.ZPopMax(ctx, "scores").Val()[0].Member)
	assert.Equal(t, "Joko", client.ZPopMax(ctx, "scores").Val()[0].Member)
	assert.Equal(t, "Budi", client.ZPopMax(ctx, "scores").Val()[0].Member)
}
