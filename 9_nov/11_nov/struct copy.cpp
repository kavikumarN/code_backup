#include<iostream>
#include<map>
#include <string>
using namespace std;
map<string, string> object_capsule; 
 int sessionid=0;

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
            string phone_number;
            nationality = nationality_constr;
            zipcode = zipcode;
            email_id = email_id_constr;
            agree_for_news_letter = agree_for_news_letter_constr;

    }
    
     ~user_profile();

};

// int map_loader()
//     {
//          object_capsule.insert(pair<string, string> ("testkey","testvalue"));
//         // auto end = object_capsule.rend;
//          auto itr = object_capsule.find("testkey");
//           //  cout <<object_capsule.max_size<<endl;
//             cout<<itr->first;
         
//     }

int struct_loader(user_profile &ref)
    {   
        sessionid++;  

        //  object_capsule.insert(pair<string,user_profile> (to_string(sessionid),&ref));

        //       auto itr = object_capsule.find(sessionid);

             cout<<"function--->"<<&ref;
             cout<<"profile id:"<<ref.profile_id<<endl;
    }

int main()
{
            user_profile *demo_profile1;
            demo_profile1 = new user_profile(2001,4254245234252,"steven", "Spielberg","Male","IND12345566773","12345564","UIDAI","123456789456","02-may-1994","no 234, 1st avenue,"," MG road"," bengaluru","karnataka", "india", "+919025247848", "INDIAN", "560041","msg4kavi@gmail.com", true );
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

// g++ mapping.cpp -o omapping