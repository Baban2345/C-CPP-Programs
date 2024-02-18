#include<stdio.h>
#include<stdlib.h>


int isPalindrome(int number);
int userInputData();
int main()
{
    int userInput;
    printf("######Hiii Welcome#######\n");
    printf("\t =====Number is Palindrome or Not =====\n");
    printf("Ener Number : \n");
    scanf("%d",&userInput);
    int revNum=isPalindrome(userInput);
    if (userInput==revNum)
    {
        printf("The given Number is palindrome\n");
    }
    else
    printf("Not a palindrome\n");
    
    return EXIT_SUCCESS;
}

int isPalindrome(int userInput)
{
    int reversedNumber=0,lastDigit;
    while(userInput!=0)
    {
        lastDigit=userInput%10;
        reversedNumber=reversedNumber*10 + lastDigit;
        userInput=userInput/10;
    }

    return reversedNumber;
}