// C++ program to demonstrate inheritance

#include <iostream>
using namespace std;

// base class
class Animal {
    //private :

    //int a=10;
   public:
      int a=10;
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// derived class
class Dog : public Animal {

   public:
    void bark() {
       
        cout << "I can bark! Woof woof!!" << endl;
        cout<<a;
       eat();
        sleep();
         
          
   
    }
    
  
};
class Cat: protected Dog{
    public:
 
 void display(){
    int b=20;
    eat();
    sleep();
     }

};
int main() {
    // Create object of the Dog class
    Dog dog1;
    Cat cat1;
    Animal animal1;
    animal1.a=30;
    // Calling members of the base class
 dog1.eat();
 dog1.sleep();
 dog1.bark();
 cat1.display();
//cat1.eat();
    //cat1.sleep();
    // Calling member of the derived class
    dog1.bark();

    return 0;
}