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
        friend class User;
};