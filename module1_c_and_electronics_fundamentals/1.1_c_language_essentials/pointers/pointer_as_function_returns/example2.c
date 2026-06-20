#include<stdio.h>
#include<stdlib.h>
int Add(int *a,int *b)//called function
//a and b are pointer to integers local to function add
{printf("Address of a in Add=%p\n",&a);
printf("value in a of Add(address of a of main)=%p\n",a);
printf("value in a of Add(address of a of Add)=%d\n",*a);
int c=(*a)+(*b);
return c;}
int main()
{int a=2,b=4;
printf("Address of a in main=%p\n",&a);
//call by reference
int c=Add(&a,&b);//a and b are intregers local to main 
printf("sum=%d\n",c);
}

//this is call by reference
