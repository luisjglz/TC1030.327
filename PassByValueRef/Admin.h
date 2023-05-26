#include <iostream>
class Admin{
    std::string private_data;
    public:
        Admin(){
            private_data = "1234";
        }
        std::string getMyData(){
            return private_data;
        }
        void setData(std::string d){
            private_data = d;
        }
        friend class User;
};