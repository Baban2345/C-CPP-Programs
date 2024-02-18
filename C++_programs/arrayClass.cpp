#include<iostream>
#include<array>
using namespace std;

int main()
{
   array<int,10> task{};
   for(int i=0;i<task.size();i++) // 4
   {
      task[i]=i*2;
   }
   for(int eachTask:task)
   {
      cout<<eachTask<<endl;
   }
   cout<<"Printed successfully..................."<<endl;
}