#include<stdio.h>
int main()
{
int n;
printf("enter size of array\n");
scamf("%d",&n);
/*int  A[n] it gives compilation error because we need to know the
 size of array at the time of initialization.it is invalid to allocate
memory at run time.so we will use malloc to allocate memory at run time.*/
int *A=(int*)malloc(n*sizeof(int));//dynamically allocated array
for(int i=0;i<n;i++)
{
A[i]=i+1;}
for(int i=0;i<n;i++)
{
printf("%d ",A[i]);
}
}
