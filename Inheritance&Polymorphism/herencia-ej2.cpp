#include <iostream>

class User{
    std::string user_id;
    std::string password;
    bool loginStatus;

    public:
    bool verify_login(){
        return loginStatus;
    };

    std::string get_user_id(){
        return user_id;
    }
};

class Customer : public User{
    std::string customer_name;
    std::string address;

    public:
    std::string get_customer_name(){ return customer_name; };
    std::string get_address(){ return address; };

    private:
    double get_next_bill_amount(){
        return 1.0;
    };
};

class Admin : public User{
    std::string admin_name;
    std::string email;

    public:
    void updateCatalog(){};
    void updateEmail(){};
};




int main(){
    Customer cust1;
    cust1.get_user_id();

    Admin admin;
    std::cout << admin.verify_login() << std::endl;
}






