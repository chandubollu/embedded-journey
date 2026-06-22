while returning pointers from functions,we need to be careful about the scope,we must be
sure that the address is not reused to store something else or the data is not cleared from 
that address.in most cases we will be returning pointers to memory that is allocaed on the
heap,or memory that is in the global section .
#include<stdio.h>
#include<stdlib.h>
int *Add(int *a,int *b)//called function - returns pointer pointing to integer
//a and b are pointer to integers local to function add
{
int c=(*a)+(*b);
return &c;}
int main()
{int a=2,b=4;
//call by reference
int *ptr=Add(&a,&b);//ptr storing the address of c 
printf("sum=%d\n",*ptr);//printing the value in c
}
but it not possible.it is error.due to above reason
