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
using namespace std::literals;

int main (int argc, char *argv[])
{
  zmq::context_t context (1);

  //  Socket to talk to server
  zmq::socket_t requester (context, ZMQ_REQ);
  requester.connect ("tcp://localhost:50002");

  for (int i = 0; i < 10; i++)
  {
    string msg_str = "Bla " + to_string(i);
    zmq::message_t request{msg_str.size() + 1};
    memcpy ((void *) request.data(), msg_str.c_str(), msg_str.size());

    requester.send(request);
    cout << "sent " << msg_str << endl;

    //  Get the reply.
    zmq::message_t reply;
    requester.recv (&reply);
    cout << i << ". Reply: " << reply.data() << endl;
  }

  cout << "exit" << endl;
  return 0;
}
