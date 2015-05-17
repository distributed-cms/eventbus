//
//  Weather update client in C++
//  Connects SUB socket to tcp://localhost:5556
//  Collects weather updates and finds avg temp in zipcode
//
//  Olivier Chamoux <olivier.chamoux@fr.thalesgroup.com>
//
#include "zmq.hpp"
#include <iostream>
#include <sstream>

using namespace std;

int main (int argc, char *argv[])
{
  zmq::context_t context (1);

  //  Socket to talk to server
  cout << "Subscribed" << endl;
  zmq::socket_t subscriber (context, ZMQ_SUB);
  subscriber.connect("tcp://localhost:55551");

  //  Subscribe to messages containing hello
  const char *filter = "hello ";
  subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen (filter));

  //  Process 2 updates
  for (int i = 0; i < 2; i++)
  {
    zmq::message_t update;
    subscriber.recv(&update);

    string received_data {static_cast<char*>(update.data())};
  }

  cout << "exit" << endl;
  return 0;
}
