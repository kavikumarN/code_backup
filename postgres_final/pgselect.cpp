#include<iostream>
#include<pqxx/pqxx> 
#include <regex>
#include <string>

using namespace std;
using namespace pqxx;

std::string sanitize (std::string word) {
    int i = 0;

    while ((i = word.find_first_of ("()", i)) != std::string::npos)
            word.erase (i, 1);
    return word;
}

void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

int main(int argc, char* argv[]) {
   string sql,sql1;
   
   try {
      connection C("dbname = postgres user = postgres password = postgres \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }

      /* Create SQL statement */
      sql = "SELECT my_function()";
      /* Create a non-transactional object. */
      nontransaction N(C);
      
      result R( N.exec( sql ));

      
std::string s;
	const char delim = ',';


      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
         
          s = c[0].as<string>();

             s = sanitize (s);   
        
         std::vector<std::string> out;

   
            tokenize(s, delim, out);
            	for (auto &s: out) {
		               std::cout << s << '\n';
	                }
   
         // cout << "Name = " << c[1].as<string>() << endl;
         // cout << "Balance = " << c[2].as<string>() << endl;
        
      }

      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}

