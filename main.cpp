#include <iostream>
#include <conio.h>
#include <string>


using namespace std;
class Account {
private:
    string user, pass;
    int counter = 1;
    void Check_User(); // username should be between 10-18
    void Check_pass(); //

public:
    Account(string, string);
    void getUser();
    void getPass();
    void select();
    void check_new_old_Pass();

};
Account :: Account (string u, string p){
    user = u;
    pass = p;
    Check_User();
 }
void Account :: getUser(){

     string u;
     cout<< "Enter your Username: "<< endl;
     cin >> u;
     user = u;
     Check_User();
}
void Account :: getPass() {
     string p;
     cout<< "Enter your Password: "<< endl ;
     cin >> p;
     pass = p;
     Check_pass();
}
void Account :: Check_User(){
    int ulength = user.length();
    char first = user.at(0);
    if (ulength < 10 || ulength > 18){

        cout << "Username lenght should be between 10 - 18 character. ";
        getUser();
     }
    else if (first >= '0' && first <= '9'){
            cout<<"username is not valid. Enter new Username which is not started with a number";
            getUser();
    }
    else {
        Check_pass();
    }

}
void Account :: Check_pass(){
    int alphabet_counter = 0;
    int number_counter = 0;
    int plength = pass.length();
    for (int i=0; i < plength; i++ ){
        if (pass.at(i)>= 'a'&& pass.at(i)<= 'z' || pass.at(i)>= 'A'&& pass.at(i)<= 'Z' ){
            alphabet_counter++;
        }
        else if (pass.at(i)>= '0'&& pass.at(i)<= '9'){
            number_counter++;
        }
    }
    if (alphabet_counter >= plength || number_counter >= plength){
        cout << "password must be combination of numbers and alphabets. ";
        getPass();
    }
    else if (plength < 8 || plength >32){
        cout << "your password should be between 8-32 character. ";
        getPass();

    }
    else if (user == pass){
        cout <<" username and password cannot be the same. The security of your pass word is low.!!!";
        getPass();
    }
    else {
        select();
    }
 }
 void Account :: select(){
     char s;
     cout << "Do you want to change your Password (Enter Y/N):";
     cin >> s;
     if (s == 'Y' || s == 'y'){
        check_new_old_Pass();
     }
     else{
        cout<<"Congratulation Dr. Hashemi. Your account is created."<<endl;
        cout<<"Your Username:" << user << "   <<<<>>>>    Your Password :" << pass <<endl;
        cin.ignore();
        cin.get();
     }

 }
void Account :: check_new_old_Pass(){
        string oldpassword;
        cout<<"Enter your old password: "<<endl;
        cin>> oldpassword;
        if (oldpassword == pass){
            getPass();
        }
        else {

            if (counter == 3){
                cout << " Your account is blocked !!";
                cin.ignore();
                cin.get();
                exit(1);
            }
             counter++;
             check_new_old_Pass();
        }

}

int main()
{
    string username, password;
    cout << "***********************************************************************************************"<<endl;
    cout << "Welcome dear Dr. Hashemi. This is a sample C++ project for creating a new account."<<endl;
    cout << "your user should be between 10-18 and your pass must be a combination of numbers and alphabets."<<endl;
    cout << "In other cases you will get an error. "<<endl;
    cout << "You can change your pass and you need to enter Y or N."<<endl;
    cout << "If you enter your pass wrong 3 times in a row, your account will be blocked."<<endl;
    cout << "***********************************************************************************************"<<endl;
    cout << "Plz Enter your Username: " << endl;
    cin >> username;
    cout << "Plz Enter your Password: " << endl;
    cin >> password;

    Account acc(username,password);
    _getch();

    return 0;
}
