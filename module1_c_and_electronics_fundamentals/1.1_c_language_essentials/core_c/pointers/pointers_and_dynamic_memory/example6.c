#include<stdio.h>
#include<stdlib.h>
int main()
{
int n;
printf("enter size of array\n");
scanf("%d",&n);
int *A=(int*)malloc(n*sizeof(int));//dynamically allocated array
for(int i=0;i<n;i++)
{
A[i]=i+1;
}
int* B=(int*)realloc(NULL,n*sizeof(int));//equivalent to malloc()
printf("prev block address =%p,new address=%p\n",A,B);
//free(A);
for(int i=0;i<n;i++)
{
printf("%d\n",B[i]);
}
}
