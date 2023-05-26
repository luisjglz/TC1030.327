#include <iostream>
class User{
    public:
    std::string getData(){
        Admin a;
        return a.private_data;
    }
};