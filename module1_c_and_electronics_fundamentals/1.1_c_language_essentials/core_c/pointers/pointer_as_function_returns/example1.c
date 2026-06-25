#include<stdio.h>
#include<stdlib.h>
int Add(int a,int b)//called function
{printf("Address of a in Add=%p\n",&a);
int c=a+b;
return c;}
int main()
{int a=2,b=4;
printf("Address of a in main=%p\n",&a);
//call by value
int c=Add(a,b);
//value in a of main is copied to a of Add.
//value of b of main is copied to b of Add.
printf("sum=%d\n",c);
}

//this is call by value

