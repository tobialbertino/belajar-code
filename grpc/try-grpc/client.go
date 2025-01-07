package main

import (
	"context"
	"log"
	"time"

	"google.golang.org/grpc"
	pb "try-grpc/example/proto"
)

func main() {
	conn, err := grpc.Dial("localhost:50051", grpc.WithInsecure())
	if err != nil {
		log.Fatalf("Could not connect: %v", err)
	}
	defer conn.Close()

	client := pb.NewGreetingServiceClient(conn)

	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	res, err := client.SayHello(ctx, &pb.HelloRequest{Name: "World"})
	if err != nil {
		log.Fatalf("Error while calling SayHello: %v", err)
	}

	log.Printf("Response from server: %v", res.GetMessage())
}
