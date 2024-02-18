#include<iostream>
using namespace std;

int main()
{
    int marks,subjects,avg;
    cout<<"Enter Total  No of Marks\n";
    cin>>marks;
    cout<<"enter total No of Subjects\n";
    cin>>subjects;
try{  
    if(subjects == 0)
    {
        throw 0;
    }
    else
    {
        avg=marks/subjects;
        cout<<"Avg Marks are :\n"<< avg;
    }
    }
  catch(int &ex)
  {
    std::cerr<<"Can't divide by 0 \n";
  }
  
  cout<<" thanks \n Bye";

    return 0;
}