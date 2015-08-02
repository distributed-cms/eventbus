FROM debian:latest

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"

RUN apt-get update
RUN apt-get install -y g++ libzmq3-dev meson git
RUN apt-get clean

#Install event bus

RUN git clone https://github.com/distributed-cms/eventbus.git
RUN mkdir /eventbus/bin
WORKDIR /eventbus/bin
RUN meson ../src .
RUN ninja

EXPOSE 5001
EXPOSE 5002

#ENTRYPOINT ./eventbus $PUB_PORT $REQ_PORT
ENTRYPOINT ./eventbus 5001 5002
