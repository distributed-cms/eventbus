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

ENV PUB_PORT 5001
ENV REQ_PORT 5002

EXPOSE $PUB_PORT
EXPOSE $REQ_PORT

ENTRYPOINT ./eventbus $PUB_PORT $REQ_PORT
