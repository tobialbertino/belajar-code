FROM golang:1.18-alpine
ENV APP_PORT=8080

RUN mkdir app
COPY main.go app 

EXPOSE ${APP_PORT}/tcp

CMD go run app/main.go