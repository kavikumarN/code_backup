#include <iostream>
#include<vector>
#include <zmq.hpp>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

namespace db_conn
{
    connection Con ("dbname=postgres user=postgres password=postgres\
                 hostaddr=127.0.0.1 port=5432");
    
}



class user_account
{
    public:
        // unsigned long int account_id,account_type_id,account_creation_date;
        // string account_name,currency_id,email_id,remarks;
        // long double balance;
        // bool account_enabled;
        long int count=0;

    struct account
    {
        unsigned long int account_id,account_type_id;
        std::string account_name,currency_id,email_id,remarks,account_creation_date;
        long double balance;
        bool account_enabled;
    }acc_struct;

    account get_details_by_id()
    {
        user_account acc_obj;
        struct account acc;

        acc.account_id = acc_struct.account_id;
        acc.account_type_id = acc_struct.account_type_id;
        acc.account_name = acc_struct.account_name;
        acc.account_enabled = acc_struct.account_enabled;
        acc.account_creation_date = acc_struct.account_creation_date;
        acc.balance = acc_struct.balance;
        acc.remarks = acc_struct.remarks;
        acc.currency_id = acc_struct.currency_id;
        acc.email_id = acc_struct.email_id;

        return acc;
    }
    
}; 

class user_profile
{
    public:
        // long int profile_id,last_update_time;
        // string firstname,lastname,gender,passport_number,other_id,other_id_type,ssn,date_of_birth,address1,address2,city,state,country,phone_number,nationality,zipcode,email_id;
        // bool agree_for_news_letter;
        long int count=0;

    struct profile
    {
        long int profile_id;
        std::string firstname,lastname,gender,passport_number,other_id,other_id_type,ssn,date_of_birth,address1,address2,city,state,country,phone_number,nationality,zipcode,email_id,last_update_time;
        bool agree_for_news_letter;
    }pro_struct;


};

class user_login
{
    public:
        // unsigned long int user_id,user_type_id,created_time;
        // string username,password,transaction_password,user_type;
        // bool user_enabled;
        long int count=0;

    struct login
    {
        unsigned long int user_id,user_type_id;
        std::string username,password,transaction_password,user_type,created_time;
        bool user_enabled;
    
    }lgn_struct;
    
};

class main_class
{
    public:
        user_login usr_lgn[100],usr_cnt;
        user_profile usr_pro[100],pro_cnt;
        user_account usr_acc[100],acc_cnt;
        
    main_class()
    {
        
        if(db_conn::Con.is_open())
        {
            cout << "Opened database successfully: " << db_conn::Con.dbname() << endl;
        }
        else 
        {
            cout << "Can't open database" << endl;
        }
    }
    void login()
    {
        string word,data,user_name,pwd,socket_id;
        vector<std::string> login_vector;
        std::stringstream data_ss;
        std::stringstream reply_ss;
        
        zmq::context_t context (1);
        zmq::socket_t socket (context, ZMQ_REP);
        zmq::message_t request;

        socket.bind ("tcp://*:5556");
        cout<<"Login Socket Listening at port : 5556"<<endl;
        while (true) {
            
            //  Wait for next request from client
            socket.recv (&request);
            data = (char *) request.data();
            cout<<data<<endl;
            data_ss.str("");
            data_ss<<data;

            while (getline(data_ss, word, ',')) {

				login_vector.push_back(word);
			}
            data_ss.clear();
            socket_id = login_vector[0];
            user_name = login_vector[1];
            pwd = login_vector[2]; 
            login_vector.clear();
            try{

                //string login_func = "SELECT cout(*) from user_login where usernmae = '"+user_name+"' AND password = '"+pwd+"'"; //select_user();
                  string login_func = "select exists(select 1 from user_login where username = '"+user_name+"' and password  = '"+pwd+"')";
                /* Create a non-transactional object. */
                        
                nontransaction N(db_conn::Con);
                result A( N.exec( login_func ));
                reply_ss.str("");
                /* List down all the records */
                for (result::const_iterator c = A.begin(); c != A.end(); ++c) 
                {
                    cout<<c[0].as<bool>()<<endl;
                    if(c[0].as<bool>() == true )
                    {
                        cout<<"login sucess"<<endl;
                        reply_ss<<socket_id<<","<<true;
                        break;
                    }
                    else
                    {
                        cout<<"login failed"<<endl;
                        reply_ss<<socket_id<<","<<false;
                        break;
                    }
                    
                }
            }
                catch (const std::exception &e)
            {
                cerr << "ERROR :: " <<e.what() << std::endl;
            }
            cout<<reply_ss.str().c_str()<<endl;
            zmq::message_t reply ((void*)reply_ss.str().c_str(), reply_ss.str().size());
            socket.send (reply);
            
        }
    }
    void onStart()
    {    
        //usr_acc[1].get_details_by_id();
        try
        {
                string select_user = "SELECT * from user_login"; //select_user();
                        
                /* Create a non-transactional object. */
                        
                nontransaction N(db_conn::Con);
                result A( N.exec( select_user ));

                /* List down all the records */
                for (result::const_iterator c = A.begin(); c != A.end(); ++c) 
                {

                    usr_lgn[c[0].as<int>()].lgn_struct.user_id = c[0].as<long int>();
                    usr_lgn[c[0].as<int>()].lgn_struct.username = c[1].as<string>();
                    usr_lgn[c[0].as<int>()].lgn_struct.password = c[2].as<string>();
                    usr_lgn[c[0].as<int>()].lgn_struct.transaction_password = c[3].as<string>();
                    usr_lgn[c[0].as<int>()].lgn_struct.user_enabled = c[4].as<bool>();
                    usr_lgn[c[0].as<int>()].lgn_struct.created_time = c[5].as<string>();
                    usr_lgn[c[0].as<int>()].lgn_struct.user_type_id = c[6].as<long int>();
                    
                    cout<< usr_lgn[c[0].as<int>()].lgn_struct.user_id <<endl;
                    cout<< usr_lgn[c[0].as<int>()].lgn_struct.username <<endl;
                    cout<< usr_lgn[c[0].as<int>()].lgn_struct.password <<endl;
                    cout<<usr_lgn[c[0].as<int>()].lgn_struct.transaction_password <<endl;
                    cout<< usr_lgn[c[0].as<int>()].lgn_struct.user_enabled <<endl;
                    cout<< usr_lgn[c[0].as<int>()].lgn_struct.created_time <<endl;
                    cout<< usr_lgn[c[0].as<int>()].lgn_struct.user_type_id <<endl;

                    usr_cnt.count++;
                }

                string select_profile = "SELECT * from select_profile()";
                        

                result B( N.exec( select_profile ));

                /* List down all the records */
                for (result::const_iterator c = B.begin(); c != B.end(); ++c) 
                {
                
                    usr_pro[c[0].as<int>()].pro_struct.profile_id = c[0].as<long int>();
                    usr_pro[c[0].as<int>()].pro_struct.firstname = c[1].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.lastname = c[2].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.gender = c[3].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.passport_number = c[4].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.other_id = c[5].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.other_id_type = c[6].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.ssn = c[0].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.date_of_birth = c[1].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.address1 = c[2].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.address2 = c[3].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.city = c[4].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.state = c[5].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.state = c[5].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.state = c[5].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.state = c[5].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.country = c[6].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.nationality = c[0].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.zipcode = c[1].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.phone_number = c[2].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.agree_for_news_letter = c[3].as<bool>();
                    usr_pro[c[0].as<int>()].pro_struct.email_id = c[4].as<string>();
                    usr_pro[c[0].as<int>()].pro_struct.last_update_time = c[5].as<long int>();

                    pro_cnt.count++;

                }

                string select_account = "SELECT * from select_account()";

                result C( N.exec( select_account ));

                /* List down all the records */
                for (result::const_iterator c = C.begin(); c != C.end(); ++c) 
                {
                    
                    usr_acc[c[0].as<int>()].acc_struct.account_id = c[0].as<long int>();
                    usr_acc[c[0].as<int>()].acc_struct.account_type_id = c[1].as<long int>();
                    usr_acc[c[0].as<int>()].acc_struct.account_name = c[2].as<string>();
                    usr_acc[c[0].as<int>()].acc_struct.account_enabled = c[3].as<bool>();
                    usr_acc[c[0].as<int>()].acc_struct.account_creation_date = c[4].as<long int>();
                    usr_acc[c[0].as<int>()].acc_struct.balance = c[5].as<long double>();
                    usr_acc[c[0].as<int>()].acc_struct.remarks = c[6].as<string>();
                    usr_acc[c[0].as<int>()].acc_struct.currency_id = c[0].as<string>();
                    usr_acc[c[0].as<int>()].acc_struct.email_id = c[0].as<string>();
                    acc_cnt.count++;

                }

                string sha512 = "select sha512('admin')";
                result s(N.exec( sha512 ));
                for (result::const_iterator c = s.begin(); c != s.end(); ++c) 
                {
                    cout<<c[0].as<string>()<<endl;
                }
                sha512 = "select sha512('admin')";
                result t(N.exec( sha512 ));
                for (result::const_iterator c = t.begin(); c != t.end(); ++c) 
                {
                    cout<<c[0].as<string>()<<endl;
                }

                
        }
        catch (const std::exception &e)
        {
            cerr << "ERROR :: " <<e.what() << std::endl;
        }

    }
    
};

int main()
{
    main_class m;
    m.onStart();
    m.login();

    return 0;
}