#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
printf("enter size of array\n");
scanf("%d",&n);
/* we are not able to allocate memory at run time
int A[n] it is invalid
by using malloc we can allocate memory at run time*/
int *A=(int*)malloc(n*sizeof(int));//dynamically allocated array
for(int i=0;i<n;i++)
{
A[i]=i+1;
}
for(int i=0;i<n;i++)
{
printf("%d",A[i]);
}
}
