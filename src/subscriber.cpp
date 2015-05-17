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
  // TODO I dont know how ZMQ_IDENTITY works: subscriber.setsockopt(ZMQ_IDENTITY, "dsss", 4);
  subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
  subscriber.connect("tcp://localhost:55551");


  while (true)
  {
    cout << "Listening"; cout.flush();
    zmq::message_t update;
    subscriber.recv(&update);

    string received_data {static_cast<char*>(update.data())};
    cout << ". OK: " << received_data << endl;
  }

  cout << "exit" << endl;
  return 0;
}
