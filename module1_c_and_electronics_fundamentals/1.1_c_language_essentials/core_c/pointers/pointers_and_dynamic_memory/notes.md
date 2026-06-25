#include<stdio.h>
#include<stdlib.h>
int main()
{
int a;//a goes on stack
int *p;
p=(int*)malloc(sizeof(int));
*p=10;
/*the only way to use memory on hea p is through reference.all the
malloc function does is look for some free space in the heap book set 
or reserved set for you and give back the pointer and  the only way you
 can access this particular block by keeping a pointer variable which will be 
local to function.*/
free(p);
/*anything allocated on the heap is not automatically deallocated when the
 function completes like on the stack and it does nott live for the whole lifetime 
of the application like a global variable,we can control when to free anything
on the heap when to deallocate anything on the heap.*/
p=(int*)malloc(sizeof(int));
*p=20;
 /*if we want to store array on the heap lets say integer array,
then all we do is make a call to the malloc asking for one block of memory
equal to the total size of the array in bytes.*/
p=(int*)malloc(20*sizeof(int));
/* one more thing if malloc is not able to find any free block of memory
is not able to allocate some memory on the heap,it returns null*/
}
