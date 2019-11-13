#include<iostream>
#include<map>
#include <string>
#include <sys/time.h>
#include <zmq.hpp> 
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>

#define sleep(n)    Sleep(n)
#endif

using namespace std;
int sessionid=0;


zmq::context_t context (1);
zmq::socket_t socket (context, ZMQ_REP);


class user_profile 
{
    public:
        long int profile_id,last_update_time;
        string firstname,lastname,gender,passport_number,other_id,other_id_type,ssn,date_of_birth,address1,address2,city,state,country,phone_number,nationality,zipcode,email_id;
        bool agree_for_news_letter;
        long int count=0;

    user_profile( long int profile_id_constr, long int last_update_time_constr, string firstname_constr, string lastname_constr, string gender_constr, string passport_number_constr,string other_id_constr,string other_id_type_constr,string ssn_constr,string date_of_birth_constr,string address1_constr,string address2_constr,string city_constr,string state_constr,string country_constr,string phone_number_constr,string nationality_constr,string zipcode_constr,string email_id_constr, bool agree_for_news_letter_constr)
    {
            profile_id = profile_id_constr;
            last_update_time = last_update_time_constr;
            firstname = firstname_constr;
            lastname =lastname_constr;
            gender = gender_constr;
            passport_number = passport_number_constr;
            other_id = other_id_constr;
            other_id_type = other_id_constr;
            ssn = ssn_constr;
            date_of_birth = date_of_birth_constr;
            address1 = address1_constr;
            address2 = address2_constr;
            city = city_constr;
            state = state_constr;
            country = country_constr;
            phone_number = phone_number_constr;
            nationality = nationality_constr;
            zipcode = zipcode_constr;
            email_id = email_id_constr;
            agree_for_news_letter = agree_for_news_letter_constr;

    }
    
     ~user_profile();

};
        map<string, user_profile*> object_capsule; 


// int map_loader()
//     {
//          object_capsule.insert(pair<string, string> ("testkey","testvalue"));
//         // auto end = object_capsule.rend;
//          auto itr = object_capsule.find("testkey");
//           //  cout <<object_capsule.max_size<<endl;
//             cout<<itr->first;      
//     }



int session_init()
    {
        std::stringstream ss ;
        ss << replystr;
        zmq::message_t request;
    
        socket.recv (&request);
        
       //  (char*)request.data()<<std::endl;


            auto session_user_id = object_capsule.find((char*)request.data());
            

            session_user_id->second->profile_id;
            session_user_id->second->last_update_time;
            session_user_id->second->firstname;
            session_user_id->second->lastname;
            session_user_id->second->gender;
            session_user_id->second->passport_number;
            session_user_id->second->other_id;
            session_user_id->second->other_id_type;
            session_user_id->second->ssn;
            session_user_id->second->date_of_birth;
            session_user_id->second->address1;
            session_user_id->second->address2;
            session_user_id->second->city;
            session_user_id->second->state;
            session_user_id->second->country;
            session_user_id->second->phone_number;
            session_user_id->second->nationality;
            session_user_id->second->zipcode;
            session_user_id->second->email_id;
            session_user_id->second->agree_for_news_letter;


        //  Send reply back to client


        zmq::message_t reply((char*)ss.str().c_str(), ss.str().size()+1);

        ss=std::stringstream(); // clear stream
        
        socket.send (reply);

    }   

int struct_loader(user_profile &ref)
    {   
        sessionid++;  
        	object_capsule.insert(std::make_pair(std::to_string(sessionid),&ref));

         // object_capsule.insert(pair<string,user_profile> ("sessionid",&ref));
          // object_capsule.insert(std::make_pair("example",&ref));
               auto itr = object_capsule.find(std::to_string(sessionid));
                cout<<"itr--->"<<itr->second<<"\t:\t";
               itr->second->email_id="ankavikumar@gmail.com";
            //  cout<<"function--->"<<&ref;
             cout<<"profile id:"<<ref.email_id<<endl;
    }

int main()
{
                socket.bind ("tcp://*:5555");

            user_profile *demo_profile1;
            demo_profile1 = new user_profile(2001,4254245234252,"steven", "Spielberg","Male","IND12345566773","12345564","UIDAI","123456789456","02-may-1994","no 234, 1st avenue,"," MG road"," bengaluru","karnataka", "india", "+919025247848", "INDIAN", "560041","msg4kavi@gmail.com", true );
            demo_profile1->email_id="updatedemail@email.com";
            struct_loader(*demo_profile1);
            cout<<"\tmain()--->"<<demo_profile1<<endl;

            user_profile *demo_profile2;
            demo_profile2 = new user_profile(2001,4254245234252,"steven", "Spielberg","Male","IND12345566773","12345564","UIDAI","123456789456","02-may-1994","no 234, 1st avenue,"," MG road"," bengaluru","karnataka", "india", "+919025247848", "INDIAN", "560041","msg4kavi@gmail.com", true );
            struct_loader(*demo_profile2);
            cout<<"\tmain()--->"<<demo_profile2<<endl;

            user_profile *demo_profile3;
            demo_profile3 = new user_profile(2001,4254245234252,"steven", "Spielberg","Male","IND12345566773","12345564","UIDAI","123456789456","02-may-1994","no 234, 1st avenue,"," MG road"," bengaluru","karnataka", "india", "+919025247848", "INDIAN", "560041","msg4kavi@gmail.com", true );
            struct_loader(*demo_profile3);  
            cout<<"\tmain()--->"<<demo_profile3<<endl;


return 0;

}

// g++ temp.cpp -o otemp
