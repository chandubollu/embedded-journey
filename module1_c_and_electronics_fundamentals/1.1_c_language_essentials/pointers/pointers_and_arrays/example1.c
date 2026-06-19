#include<stdio.h>
int main()
{
int A[]={2,4,5,8,1};
printf("%p\n",A);
printf("%p\n",&A[0]);
printf("%d\n",A[0]);
printf("%d",*A);
}
//A=&A[0]
//A[0]=*A
