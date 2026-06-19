//passing array as argument  to function acts as pointer
#include<stdio.h>
int SumofElements(int* A,int size)
{int i,sum=0;
printf("SOE - size of A=%zu,size of A[0]=%zu\n",sizeof(A),sizeof(A[0]));
for(i=0;i<size;i++)
{
sum+=A[i];}
return sum;
}
int main()
{
int A[]={1,2,3,4,5};
int size=sizeof(A)/sizeof(A[0]);
int total = SumofElements(A,size);
printf("sum of elements =%d\n",total);
printf("Main-size of A=%zu,size of A[0]=%zu\n",sizeof(A),sizeof(A[0]));

}
