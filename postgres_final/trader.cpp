#include<iostream>
#include<map>
#include<iterator> 
#include<string>
class trader
{
    private :      
        int no_of_org,profile_count=0,account_count=0,login_count=0,org_count=0; 

        struct login
        {
            std::string id,user_name,password,email;
            long int created_time,login_count=0;

        }lgn[];

        struct account
        {
            std::string id,account_number,holder_name,email,branch,state,country;
            //std::map<long int,std::string>transaction_history;
            long long int balance,equity,account_count=0,profile_count=0;
            std::string account_holders_id[];
            struct login lgn[];
        }acc[];

       

        struct profile
        {
            std::string id,user_name,first_name,last_name,email,branch,state,country;
            long int phone_number,country_code,profile_count=0,account_count=0,login_count=0;
            struct account acc[];
            //struct login lgn[];

        }pro[];

        struct organization
        {
            std::string id,name,type,parent,branch,state,country;
            struct profile pro[];
            long long int account_count=0,profile_count=0,login_count=0;
        }org[];

    public:
        int add_org()
        {
          int i;
          //struct organization org[10];
          std::cout<<"enter the number of organization : "<<std::endl;
          std::cin>>no_of_org;
          for(i=org_count;i<no_of_org+org_count;i++)
          {
              std::cout<<"Name of the organization : "<<std::endl;
              std::cin>>org[i].name;
              std::cout<<"Type of the organization : "<<std::endl;
              std::cin>>org[i].type;
              std::cout<<"Parent of the organization : "<<std::endl;
              std::cin>>org[i].parent;
              std::cout<<"Branch of the organization : "<<std::endl;
              std::cin>>org[i].branch;
              std::cout<<"state of the organization : "<<std::endl;
              std::cin>>org[i].state;
              std::cout<<"state of the organization : "<<std::endl;
              std::cin>>org[i].state;
              org_count++;
          }
          no_of_org+=org_count;
          if(org_count==no_of_org)
          {
              return 1;
          }
          else
          {
              return 0;
          }
          
        }
        int add(std::string user_name,std::string password,std::string first_name,std::string last_name,long long int balance,std::string email,std::string branch,std::string state,std::string country,long int phone,long int country_code)
        {
            
            //ADD PROFILE BY BRANCH
            for(int i=0;i<no_of_org;i++)
            {
                if(country.compare(org[i].country)==0 )
                {
                    if(state.compare(org[i].state) == 0)
                    {
                        if(branch.compare(org[i].branch) == 0)
                        {
                            this->org[i].pro[profile_count].id = "PROFILE_000"+std::to_string(profile_count);
                            this->org[i].pro[profile_count].user_name = user_name;
                            this->org[i].pro[profile_count].first_name = first_name;
                            this->org[i].pro[profile_count].last_name = last_name;
                            this->org[i].pro[profile_count].email = email;
                            this->org[i].pro[profile_count].country_code = country_code;
                            this->org[i].pro[profile_count].phone_number = phone;
                            this->org[i].pro[profile_count].branch = branch;
                            this->org[i].pro[profile_count].state = state;
                            this->org[i].pro[profile_count].country = country;
                            this->org[i].pro[profile_count].profile_count++;
                            this->org[i].pro[profile_count].acc[account_count].id = "ACCOUNT_000"+std::to_string(account_count);
                            this->org[i].pro[profile_count].acc[account_count].account_number = "ACNT000"+std::to_string(account_count);
                            this->org[i].pro[profile_count].acc[account_count].holder_name = first_name+" "+last_name;
                            this->org[i].pro[profile_count].acc[account_count].email = email;
                            this->org[i].pro[profile_count].acc[account_count].branch = branch;
                            this->org[i].pro[profile_count].acc[account_count].state = state;
                            this->org[i].pro[profile_count].acc[account_count].country = country;
                            this->org[i].pro[profile_count].acc[account_count].balance = balance;
                            this->org[i].pro[profile_count].acc[account_count].account_holders_id[this->org[i].pro[profile_count].acc[account_count].profile_count] = this->org[i].pro[profile_count].id;
                            //this->org[i].pro[profile_count].acc[account_count].account_count++;
                            this->org[i].pro[profile_count].acc[account_count].profile_count++;
                            this->org[i].pro[profile_count].acc[account_count].lgn[login_count].id =                     
                            profile_count++;
                            account_count++;
                        }
                    }
                }   
            }  
        }
};

