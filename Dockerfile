#build

FROM gcc:latest as build 

WORKDIR /magic-project

RUN apt-get update && apt-get install -y libboost-dev libboost-program-options-dev libgtest-dev cmake make libncurses5-dev && cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && cmake --build . && mv lib*.a /usr/lib

COPY . /usr/src/docker

WORKDIR /usr/src/docker/magic-project

RUN gcc -o magic main.c enemyAi.c init.c magic.c nameGenerator.c nextLevel.c stage.c -lncurses

#-------------------------------

FROM ubuntu:latest

RUN groupadd -r sample && useradd -r -g sample sample
USER sample

WORKDIR /usr/src/docker

COPY --from=build /usr/src/docker/magic-project .

#to run docker use
#sudo docker exec -it c6ec49aa958e sh -c "stty rows 50 && stty cols 150 && bash"

CMD ["./magic"]
