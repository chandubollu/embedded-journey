#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
printf("enter size of array\n");
scanf("%d",&n);
/* we are not able to allocate memory at run time
int A[n] it is invalid
by using calloc we can allocate memory at run time*/
int *A=(int*)calloc(n,sizeof(int));//dynamically allocated array
for(int i=0;i<n;i++)
{
A[i]=i+1;
}
int* B=(int*)realloc(A,2*n*sizeof(int));
printf("prev block address =%p,new address=%p\n",A,B);
//free(A);
for(int i=0;i<2*n;i++)
{
printf("%d\n",B[i]);
}
}
/*if we want to modify the size of a memory block.
lets say we have a memory block to store n elements in an array
may be we want to double the size of array or
may be we want to reduce the size of array to half.
in such cases we use realloc()*/

