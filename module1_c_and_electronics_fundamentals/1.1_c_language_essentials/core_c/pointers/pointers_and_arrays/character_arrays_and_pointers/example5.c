//arrays are always passed to function by reference
#include<stdio.h>
void print(char *c)//
{int i=0;
while(c[i]!='\0')//we can use *(c+i)==c[i]
{
printf("%c",c[i]);
i++;
}
printf("\n");
}

int main()
{
char c[20]="hello";
print(c);
}
