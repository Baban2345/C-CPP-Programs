#include<stdio.h>
int main()
{
    int userInput,lastDigit,sumTotal=0;
    int choice=0;
    while(choice!=1)
    {
        printf("Enter Input Number:");
    scanf("%d",&userInput);
    while(userInput!=0)
    {
        lastDigit=userInput%10;
        sumTotal+=lastDigit*lastDigit*lastDigit;
        userInput/=10;
        
    }
    if(userInput==sumTotal)
    {
        printf("Given No is armStrong\n");
    }
    else
    printf("Not a Armstrong\n");
    
    }
    
    
    return 0;
}