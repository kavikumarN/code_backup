#include<iostream>
#include<vector>

using namespace std;

class user_account {
        public:
        unsigned long int account_id,account_type_id,account_creation_date;
        string account_name,currency_id,email_id,remarks;
        long double balance;
        bool account_enabled;

        user_account( unsigned long int account_id_constr,unsigned long int account_type_id_constr,unsigned long int account_creation_date_constr,string account_name_constr,string currency_id_constr,string email_id_constr,string remarks_constr,long double balance_constr, bool account_enabled_constr)
        {
                account_id = account_id_constr;
                account_type_id = account_type_id_constr;
                account_creation_date= account_creation_date_constr;
                account_name = account_name_constr;
                currency_id = currency_id_constr;
                email_id = email_id_constr;
                remarks_constr = remarks_constr;
                balance = balance_constr;
                account_enabled = account_enabled_constr;
        }
};

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

};

class user_login
{
    public:
        unsigned long int user_id,user_type_id,created_time;
        string username,password,transaction_password,user_type;
        bool user_enabled;
        long int count=0;


    user_login(unsigned long int user_id_constr,unsigned long int user_type_id_constr,unsigned long int created_time_constr, string username_constr,string password_constr,string transaction_password_constr,string user_type_constr,bool user_enabled_constr)
    {

    user_id = user_id_constr;
    user_type_id = user_type_id_constr;
    created_time = created_time_constr;
    username = username_constr;
    password = password_constr;
    transaction_password = transaction_password_constr;
    user_type = user_type_constr;
    user_enabled = user_enabled_constr;
    }
};

// class register_new_user  { //: public user_login , public user_profile , public user_account  {
//     public:
//            register_new_user()
//          {  

//             user_account *demo_account1;
//             demo_account1 = new user_account(1001,1,4254245234252,"Steven Spielberg", "AED" , "msg4kavi@gmail.com", "NIL" , 132888.86, true);

//             user_profile *demo_profile1;
//             demo_profile1 = new user_profile(2001,4254245234252,"steven", "Spielberg","Male","IND12345566773","12345564","UIDAI","123456789456","02-may-1994","no 234, 1st avenue,"," MG road"," bengaluru","karnataka", "india", "+919025247848", "INDIAN", "560041","msg4kavi@gmail.com", true );

//             user_login *demo_login1;
//             demo_login1 = new user_login(3001,1,123456789012,"steven spielberg", "password", "password", "root", true);
//         }   

//         int display () {

//         }    
// };

//class  register_new_user
 class register_new_user  : public user_login , public user_profile , public user_account  {

           public:

            register_new_user() {
                user_account *demo_account1;
            demo_account1 = new user_account(1001,1,4254245234252,"Steven Spielberg", "AED" , "msg4kavi@gmail.com", "NIL" , 132888.86, true);

            user_profile *demo_profile1;
            demo_profile1 = new user_profile(2001,4254245234252,"steven", "Spielberg","Male","IND12345566773","12345564","UIDAI","123456789456","02-may-1994","no 234, 1st avenue,"," MG road"," bengaluru","karnataka", "india", "+919025247848", "INDIAN", "560041","msg4kavi@gmail.com", true );

            user_login *demo_login1;
            demo_login1 = new user_login(3001,1,123456789012,"steven spielberg", "password", "password", "root", true);

           cout<< demo_login1->user_id;
            }
            
    };


int main() {

        //set 1


        register_new_user rnu = new register_new_user();
           cout<< rnu.user_type;



        // //set 2

        // register_new_user *r1;
        // r1 = new register_new_user();

        // //cout<< r1.demologin1.user_id;



    return 0;

}