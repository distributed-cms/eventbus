//
//  Binds PUB socket to tcp://*:5556
//
//  Carlos Martin Sanchez <carlosvin@gmail.com>
//
#include "zmq.hpp"

int main () {

    //  Prepare our context and publisher
    zmq::context_t context (1);
    zmq::socket_t publisher (context, ZMQ_PUB);
    publisher.bind("tcp://*:55551");
    publisher.bind("ipc://eventsource.ipc");

    zmq::socket_t receive (context, ZMQ_REP);
    receive.bind("tcp://*:55552");


    while (true) {
        zmq::message_t received_msg{20};
        if (receive.recv(&received_msg))
        {
            //  Send message to all subscribers
            publisher.send(received_msg);
	}


    }
    return 0;
}
