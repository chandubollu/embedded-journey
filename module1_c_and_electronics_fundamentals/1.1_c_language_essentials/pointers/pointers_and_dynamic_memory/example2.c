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
free(A);
for(int i=0;i<n;i++)
{
printf("%d",A[i]);
}
}
//in calloc if we not initialize the array then all
// elements are defaultly initialized with zero.
//where malloc initialized with garbage values

/* any memory that is dynamically allocated remains
 allocated for the life time of the program
is executing.unless we are explicitly deallocated and 
for this we have function free()
we have to pass the starting memory block as argument.
free(A)*/
