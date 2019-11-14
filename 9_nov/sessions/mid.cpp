
#include <zmq.hpp>
#include <string>
#include <iostream>

int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    socket.connect ("tcp://localhost:5555");

   
        zmq::message_t request (5);
        memcpy (request.data (), "2", 5);
        socket.send (request);

        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << (char*)reply.data()<<std::endl;
    
    return 0;
}