#include <iostream>
using namespace std;

int main(){

    /*********************/
    /*                   */
    /*     USING CIN     */
    /*                   */
    /*********************/

    string full_name = "";
    cout << "Insert your full name: " << endl;
    cin >> full_name;

    //print content of 'full_name'
    cout << full_name << endl;



    /*********************/
    /*                   */
    /*   USING GetLine   */
    /*   cin.ignore();   */
    /*                   */
    /*********************/

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    string full_name_ok = "";
    cout << "Insert your full name: " << endl;
    getline(cin, full_name_ok);

    //print content of 'full_name_ok'
    cout << full_name_ok << endl;


    return 0;
}