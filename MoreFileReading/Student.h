#include <iostream>
class Student{
    //Name,Login ID,SIS ID,Section,Role,Last Activity,Total Activity
    //Mauricio Aguilar Pacheco,A01663667,3884503,3,Student,Jun 5 at 10:47pm,0.589456018518519
    std::string name;
    std::string loginID;
    int sisID;
    int section;
    std::string role;
    std::string lastActivity;
    double totalActivity;

    public:
        //Student():name(""),loginID(""),sisID(0),section(0),role(""),lastActivity(""),totalActivity(0){};
        Student(std::string _n, std::string _id):name(_n),loginID(_id){};
        Student(std::string _name, std::string _loginID, int _sisID, int _section, std::string _role, std::string _lastActivity, double _totalActiviy){
            name = _name;
            loginID = _loginID;
            sisID = _sisID;
            section = _section;
            role = _role;
            lastActivity = _lastActivity;
            totalActivity = _totalActiviy;
        };
        std::string toStr(){
            return name + ", " + loginID + ", " + std::to_string(sisID) + ", " + std::to_string(section) + ", " + role + ", " + lastActivity + ", " + std::to_string(totalActivity);
        }
};