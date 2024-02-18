#include<iostream>
#include<string>

using namespace std;

int main()
{
    string adjective1,adjective2,adjective3,girlName,boyName,occupation1,occupation2,placeName,hobby,clothing,mensName;
    cout<<"Enter a adjective : "<<endl;
    getline(cin,adjective1);
    cout<<"Enter girl's Name : "<<endl;
    getline(cin,girlName);
    cout<<"Enter  another adjective : "<<endl;
    getline(cin,adjective2);
    cout<<"Enter an Occupation : "<<endl;
    getline(cin,occupation1);
    cout<<"Please Enter the name of a Place : "<<endl;
    getline(cin,placeName);
    cout<<"Please enter the Name of an Item of clothing in plural : "<<endl;
    getline(cin,clothing);
    cout<<"Please Enter a hobby : "<<endl;
    getline(cin,hobby);
    cout<<"Enter  another adjective : "<<endl;
    getline(cin,adjective3);
    cout<<"Enter another Occupation : "<<endl;
    getline(cin,occupation2);
    cout<<"Please Enter a Boy's Name : "<<endl;
    getline(cin,boyName);
    cout<<"Please Enter a Man's Name : "<<endl;
    cin>>mensName;

    cout<< "Once there was a "<<adjective1<<" girl named "<<girlName<<" who was a "<<adjective2<<" "
        <<occupation1<<" in the kingdom of "<<placeName<<" . She loved to wear "<<clothing<<" and "
        <<hobby<<" . She wanted to marry the "<<adjective3<<" "<<occupation2<<" named "<<boyName
        <<" but her father,king "<<mensName<<" forbid her to seeing him."<<endl;
    return 0;
}