//
//  Binds PUB socket to tcp://*:5556
//
//  Carlos Martin Sanchez <carlosvin@gmail.com>
//
#include "zmq.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <tuple>

using namespace std;

constexpr unsigned BASE_PORT = 55550;
const string BASE_URL = "tcp://*:";

int get_port(int argc, char ** argv, int port_position)
{
	return argc > port_position ? atoi(argv[port_position]) : BASE_PORT +  port_position;
}

string get_url(unsigned port)
{
	return BASE_URL + to_string(port);
}

int main (int argc, char ** argv)
{

	const string publisher_endpoint = get_url(get_port(argc, argv, 1));
	const string request_endpoint = get_url(get_port(argc, argv, 2));

	//  Prepare our context
	zmq::context_t context (1);

	// Prepare publisher
	zmq::socket_t publisher (context, ZMQ_PUB);
	publisher.bind(publisher_endpoint.c_str());
	cout << "Publisher endpoint\t" << publisher_endpoint << endl;

    	// prepare servers listener
    	zmq::socket_t server_listener (context, ZMQ_REP);
    	server_listener.bind (request_endpoint.c_str());
	cout << "Requests endpoint\t" << request_endpoint << endl;

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
