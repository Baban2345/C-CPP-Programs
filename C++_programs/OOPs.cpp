#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Player{
   
    //attriutes
    string name;
    int health;
    int xp;

    //methods
    public:
     
    void talk(string text)
    
    {

        cout<<name<<" says ..."<<text<<endl;
    }
    bool isDead(){
        if(health ==0){
            return true;
        }
    }

};
class Account{
    public:
    string name;
    double balance;

    bool deposit(double);
    bool withdraw(double);
};
int main()
{
    Player Player1;
    Player Player2;
    Account SBI;
    Account Hdfc;
    //Player1.name="Baban";
    //Player2.name="manik";
    //Player1.health=80;
    //Player2.health=90;
    Player1.talk("This is Player 1");
    Player1.isDead();

    //cout<<"Player-1 Name is :" <<Player1.name<<endl;
    
    return 0;
}

