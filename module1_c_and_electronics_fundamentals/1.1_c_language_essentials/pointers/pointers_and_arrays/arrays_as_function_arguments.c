#include<stdio.h>
int SumofElements(int A[])
{int i,sum=0;
int size =sizeof(A)/sizeof(A[0]);
printf("SOE - size of A=%d,size of A[0]=%d\n",sizeof(A),sizeof(A[0]));
for(i=0;i<size;i++)
{
sum+=A[i];}
return sum;
}
int main()
{
int A[]={1,2,3,4,5};
int total = SumofElements(A);
printf("sum of elements =%d\n",total);
printf("Main-size of A=%d,size of A[0]=%d\n",sizeof(A),sizeof(A[0]));

}
