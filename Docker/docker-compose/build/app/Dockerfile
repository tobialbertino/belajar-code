# FROM golang:1.18-alpine

# ENV APP_PORT=8080

# RUN mkdir app
# COPY main.go app

# EXPOSE ${APP_PORT}

# CMD go run app/main.go

FROM golang:1.18-alpine as builder
WORKDIR /app/
COPY main.go /app/
RUN go build -o /app/main /app/main.go

FROM alpine:3
WORKDIR /app/
COPY --from=builder /app/main /app/
EXPOSE ${APP_PORT}
CMD /app/main