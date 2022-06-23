FROM golang:1.18-alpine

RUN mkdir /app/
COPY main.go /app/

EXPOSE 8080/tcp

ENTRYPOINT [ "go", "run" ]

CMD ["/app/main.go"]