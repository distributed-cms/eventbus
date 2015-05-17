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
  cout << "Creating publisher" << endl;
  zmq::socket_t publisher (context, ZMQ_PUB);
  publisher.bind("tcp://*:55552");
  //publisher.bind("ipc://eventsource.ipc");

  //  Process 2 updates
  for (int i = 0; i < 2; i++)
  {
    zmq::message_t message {"Bla"};
    publisher.send(&message);
    cout << "sending" << endl;
  }

  cout << "exit" << endl;
  return 0;
}
