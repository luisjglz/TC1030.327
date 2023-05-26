#include "Admin.h"
using namespace std;

void updateByValue(Admin);
void updateByRef(Admin &);

int main(){
    Admin admin;
    cout << "Admin private_data: " << endl;
    cout << admin.getMyData() << endl;

    //Pass by value (copy)
    //Original admin retains its data.
    updateByValue(admin); //only updates a copy.
    cout << admin.getMyData() << endl; // we still get "1234"


    //Pass by reference (no copy)
    //We change the original admin data.
    updateByRef(admin); //we update the original object.
    cout << admin.getMyData() << endl; // we now get "5678"



    return 0;
}

void updateByValue(Admin a){
    a.setData("5678");
}

void updateByRef(Admin & a){
    a.setData("5678");
}