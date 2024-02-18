#include<iostream> 
#include<vector> 
#include<string> 
using namespace std; 
int main(){ 
	int i; 
	vector<int>newVec; 
	while(1){ 
	cout<<"Enter a number"<<endl; 
	cin>>i; 
	if(i>=0){ 
	newVec.push_back(i);} 
	else{ 
		break;} 


	} 
	for(int c:newVec){ 
		cout<<"double = "<<c*2<<endl; 
		} 
}