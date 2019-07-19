    #include <iostream>
    #include <vector>
    #include <unistd.h>
    #include <string>
    #include <future>
    #include <mutex>
    #include <log4cxx/logger.h>
    #include <log4cxx/basicconfigurator.h>
    #include <log4cxx/helpers/exception.h>
    #include <log4cxx/helpers/stringhelper.h>
    #include <log4cxx/xml/domconfigurator.h>
    #include <log4cxx/helpers/exception.h>
    #include <log4cxx/ndc.h>
    #include <log4cxx/level.h>

    using namespace std;
    using namespace log4cxx;
using namespace log4cxx::helpers;

    namespace logger
{
    int result = EXIT_SUCCESS;
    enum {LOG4CXX_POLL_INTERVAL = 60, };
} 
    void function_usdeur (void)
     {    for(;;){
             std::vector<std::string> ohlcs;
                   
            std::istringstream f("abc,fghj,dehb,dkjbabc,fghj,dehb,dkjb,aaa,cxc");
            std::string s;

                while (std::getline(f, s, ',')) {
                    auto oo=1;
              std::cout << s <<oo<< std::endl;
              oo++;
              ohlcs.push_back(s);
                         const char* LOG4CXX_PROPERTY_FILE ="config2.xml";

                   log4cxx::xml::DOMConfigurator::configureAndWatch(LOG4CXX_PROPERTY_FILE,logger::LOG4CXX_POLL_INTERVAL);
                
                   LoggerPtr rootLogger = Logger::getLogger("");
                
                   NDC::push("trivial context");
                      
                   rootLogger->error(s);
                   rootLogger->info(s);
      sleep(1);
                }
              

     }
     }

    void function_usdjpy (void) {         
      
      for (;;) {
             std::vector<std::string> ohlcs;
                   
            std::istringstream f("abc,fghj,dehb,dkjbabc,fghj,dehb,dkjb,aaa,cxc");
            std::string s;

                while (std::getline(f, s, ',')) {
                    auto oo=1;
              std::cout << s <<oo<< std::endl;
              oo++;
              ohlcs.push_back(s);

           const char* LOG4CXX_PROPERTY_FILE ="config1.xml";

                   log4cxx::xml::DOMConfigurator::configureAndWatch(LOG4CXX_PROPERTY_FILE,logger::LOG4CXX_POLL_INTERVAL);
                
                   LoggerPtr rootLogger = Logger::getLogger("");
                
                   NDC::push("trivial context");
                      
                  rootLogger->error(s);
                   rootLogger->info(s);
                   sleep(1);

        }
    }
    }
    int main ()
    { 
          

 
        #pragma omp parallel
        {      
       
            #pragma omp task
            function_usdeur(s);
            #pragma omp task
            function_usdjpy(s);
                
        }
        return 0;
    }

    // g++ delimiter.cpp -fopenmp  -lapr-1 -laprutil-1 -llog4cxx -o delim
