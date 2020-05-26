#build

FROM gcc:latest as build 

WORKDIR /magic-project

RUN apt-get update && apt-get install -y libboost-dev libboost-program-options-dev cmake make libncurses5-dev 

COPY . /usr/src/docker
WORKDIR /usr/src/docker/magic-project

RUN cmake CMakeLists.txt
RUN make

#-------------------------------

FROM ubuntu:latest

RUN groupadd -r sample && useradd -r -g sample sample
USER sample

WORKDIR /usr/src/docker

COPY --from=build /usr/src/docker/magic-project .

#to run docker use
#sudo docker exec -it c6ec49aa958e sh -c "stty rows 50 && stty cols 150 && bash"

CMD ["./magic"]
