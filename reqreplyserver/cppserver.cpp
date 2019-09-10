#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <zmq.hpp> 
#include <string>
#include <time.h>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>

#define sleep(n)    Sleep(n)
#endif

zmq::context_t context (1);
zmq::socket_t socket (context, ZMQ_REP);
std::string freader()
{
std::stringstream a;
FILE *fp;
char str1[60];

fp = fopen("default.csv", "r");
if(NULL == fp)
    {
        std::cout << "\nError in opening file."<<std::endl;
        return 0;
    }

    while(EOF != fscanf(fp, "%s", str1))
            a << str1 <<std::endl;

fclose(fp);
        std::string s = a.str(); 
        a=std::stringstream();
    return s;
}

int sockcomm(std::string replystr) {

    socket.bind ("tcp://*:5555");

    while (true) {
        
        std::stringstream ss ;
        ss << replystr;
        zmq::message_t request;
    
        socket.recv (&request);
        
        ///   gettimeofday(&tp, NULL);
     //   long int mr = tp.tv_sec * 1000 + tp.tv_usec / 1000;
       std::cout << (char*)request.data()<<std::endl;

        //  Send reply back to client

        zmq::message_t reply((char*)ss.str().c_str(), ss.str().size()+1);

        ss=std::stringstream(); // clear stream
        
        socket.send (reply);
     
    return 0;
}
}

int main() {
sockcomm(freader());
    return 0;
}
