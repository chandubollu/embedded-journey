/*sometimes we may want a function just to read a string and not write anything
in this case we change our argument to const character pointer.*/
#include<stdio.h>
void print(const char *c)//const keyword
{
while(*c !='\0')
{
printf("%c",*c);
c++;
}
printf("\n");
}

int main()
{
char* c="Hello";
print(c);
}
