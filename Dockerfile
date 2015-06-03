FROM debian:latest

MAINTAINER Carlos Martin Sanchez "carlosvin@gmail.com"

RUN apt-get update
RUN apt-get install -y g++ libzmq3-dev meson git
RUN apt-get clean

#Install event bus

RUN git clone https://github.com/carlosvin/eventbus.git
RUN mkdir /eventbus/bin
WORKDIR /eventbus/bin
RUN meson ../src .
RUN ninja

ENV port_pub 50001
ENV port_req 50005

EXPOSE $port_pub
EXPOSE $port_req

ENTRYPOINT ./eventbus $port_sub $port_req
