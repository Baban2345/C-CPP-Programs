#include<iostream>
using namespace std;

class Student{
private:
string studentName;
int rollNo;
char grade;
public:
float marksPercentage;
    void setStudentName(string sname)
    {
        int snameSize=sizeof(sname);
        if(snameSize = 0){
            cout<<"name should not be empty"<<endl;
        }
        else
        {
            studentName=sname;
        }
    }
    void setRollNo(int rNo)
    {
        rollNo=rNo;
    }
    void setGrade(char sGrade)
    {
        if(sGrade == 'A' || sGrade == 'B' || sGrade == 'C'|| sGrade == 'D')
        {
            grade=sGrade;
        }
        else
        {
            grade='-';
        }
    }
    string getName()
    {
        return studentName;
    }
    int getRollNo()
    {
        return rollNo;
    }
    char getGrade()
    {
        return grade;
    }
};
int main()
{
    Student s1;
    string sname;
    int roll;
    char grade;
    
    cout<<"enter student Name: "<<endl;
    cin>>sname;
    s1.setStudentName(sname);
    cout<<"enter rollNo: "<<endl;
    cin>>roll;
    cout<<"enter grade: "<<endl;
    cin>>grade;
   s1.marksPercentage=9.5;
    s1.setRollNo(roll);
    s1.setGrade(grade);
    
    
    cout<<"Student Name is : "<<s1.getName()<<endl;
    cout<<"Student Roll No is : "<<s1.getRollNo()<<endl;
    cout<<"Student Marks Percentage is: "<<s1.marksPercentage<<endl;
    cout<<"Student Grade is   :"<<s1.getGrade()<<endl;
    return 0;
}