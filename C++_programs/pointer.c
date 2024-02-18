#include<stdio.h>

int main()
{
    int a = 5, *p = &a;
    int **q=&p;
    printf ("p is: %p\n*p is: %d\nvalue of &p is:%p\n **q is:%d\n", p, *p,&p,**q  );
    printf("address of a is: %p",&a);
    return 0;
}