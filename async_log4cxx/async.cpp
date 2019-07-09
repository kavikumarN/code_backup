
#include <stdlib.h>
#include <log4cxx/logger.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/ndc.h>
#include <log4cxx/level.h>
#include "zhelpers.hpp"

using namespace log4cxx;
using namespace log4cxx::helpers;

int main()
{
    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);
    publisher.bind("tcp://*:5563");
int result = EXIT_SUCCESS;
enum {LOG4CXX_POLL_INTERVAL = 60, };
const char* LOG4CXX_PROPERTY_FILE ="async.xml";
try
{
// if we do not specify the log4j properties file, we must use
// BasicConfigurator::configure();
// else we pass in the file name with path and watch time
//
log4cxx::xml::DOMConfigurator::configureAndWatch(LOG4CXX_PROPERTY_FILE,LOG4CXX_POLL_INTERVAL);
// a thread will be created that will periodically
// check if the LOG4CXX_PROPERTY_FILE has been created or
// modified. The period is determined by the LOG4CXX_POLL_INTERVAL
// argument in seconds. If a change or file creation is detected, then
// LOG4CXX_PROPERTY_FILE is read to configure log4j.

LoggerPtr rootLogger = Logger::getLogger("PRIMARY");
LoggerPtr subLogger = Logger::getLogger("FALLBACK");

// get the logger setting by name "sd"

NDC::push("trivial context");
// NDC (nested diagnostic context) for multithread logging purpose

while(1==1)
{
rootLogger->debug("debug message");
rootLogger->info("info message");
rootLogger->warn("warn message");
rootLogger->error("error message");
rootLogger->fatal("fatal message");
}
}
catch(Exception&)
{
result = EXIT_FAILURE;
}

return result;
}

// g++ async.cpp  -lapr-1 -laprutil-1 -llog4cxx -o async
