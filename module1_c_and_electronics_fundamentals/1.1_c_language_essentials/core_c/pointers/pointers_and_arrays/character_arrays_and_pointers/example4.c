//arrays and pointers are different types that are used in similar manner.
#include<stdio.h>
int main()
{
char c1[6]="hello";//character array
char* c2;//pointer to character
c2=c1;//returns the address of  first element of character array

//that is c2 points to first element of array
printf("%c\n",c2[1]);//e
c2[0]='A';//Aello
//c2[i] is *(c2+i)
//c1[i] or *(c1+i)
// we cannot do c1=c2 ,c1=c1+1 they are invalid
//we can do with pointer c2++;
printf("%s",c1);
}

