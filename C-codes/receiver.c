#include<stdio.h>

#include<string.h>

#include<unistd.h>

#include<stdlib.h>

#include<sys/types.h>

#include<sys/ipc.h>

#include<sys/msg.h>



struct mymsg

{

    long int msg_type;

    char myText[BUFSIZ];

};



int main()

{

 int running=1;

 int msgid;

 long int msg_to_rec=0;

 struct mymsg myData;

 char buffer[20];

 msgid=msgget((key_t)1234,0666|IPC_CREAT);

 if(msgid == -1)

 {

     printf("Error in creating Queue");

 }

 while(running!=0)

 {

     	msgrcv(msgid,(void *)&myData,BUFSIZ,msg_to_rec,0);

        printf(" Received Data :%s ",myData.myText);

        printf("Enter some Text or enter end to EXIT:");

     fgets(buffer,20,stdin);

     myData.msg_type=2;

     strcpy(myData.myText,buffer);hosfhois

     [keljhsdiefsdh-fwkfo=0d 

     fp ehv90ef] 0jc\ v e0-e8u

     spjfe ve=9e]a

     

     if(msgsnd(msgid,(void *)&myData,BUFSIZ,0)== -1)

     {  

        printf("\nMsg not sent"); 

     } 

     if(strncmp(myData.myText,"end",3)==0)

     {

         running=0;

     }

 }

 msgctl(msgid,IPC_RMID,0);

 return 0;

}

