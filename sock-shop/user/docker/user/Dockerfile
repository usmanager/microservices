FROM golang:1.14.6-alpine AS build

# Build user binary
COPY . /go/src/github.com/usmanager/microservices/sock-shop/user
WORKDIR /go/src/github.com/usmanager/microservices/sock-shop/user
RUN go build -o user && \
mkdir /app && \
mv /go/src/github.com/usmanager/microservices/sock-shop/user/user /app/user

# Build final image
FROM usmanager/registration-client AS registration-client
FROM alpine:3.12.0
ENV HATEAOS user
ENV USER_DATABASE mongodb
ENV MONGO_HOST user-db:27017
RUN mkdir /app
WORKDIR /app
COPY --from=build /app/user user
COPY --from=registration-client /app/registration-client .
COPY scripts/docker-init.sh docker-init.sh
RUN ["chmod", "+x", "docker-init.sh"]
ENTRYPOINT ["./docker-init.sh"]
ENV LATITUDE 0
ENV LONGITUDE 0
# registration-server, external-port, internal-port, hostname, registration-client-port, latitude, longitude, db
CMD 127.0.0.1:8761 8080 80 127.0.0.1 1906 $LATITUDE $LONGITUDE user-db:27017