//
//  Binds PUB socket to tcp://*:5556
//
//  Carlos Martin Sanchez <carlosvin@gmail.com>
//
#include "zmq.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main () {

    //  Prepare our context
    zmq::context_t context (1);

    // Prepare publisher
    zmq::socket_t publisher (context, ZMQ_PUB);
    publisher.bind("tcp://*:55551");
    //publisher.bind("ipc://eventsource.ipc");

    // prepare servers listener
    zmq::socket_t server_listener (context, ZMQ_REP);
    server_listener.bind ("tcp://*:55552");



    const string reply_msg {"OK"};
    while (true) {
        cout << "Listening events...";cout.flush();

        zmq::message_t received_msg;
        server_listener.recv(&received_msg);
	string received_string {static_cast<char *>(received_msg.data())};

	//  Send message to all subscribers
        cout << "Publishing:\t" << received_string;
        publisher.send(received_msg);
	this_thread::sleep_for(1ms);
        cout << ". Published." << endl;

	server_listener.send (reply_msg.c_str(), reply_msg.size());

    }
    return 0;
}
