
#include<stdio.h>
void print(char *c)//
{
while(*c !='\0')//we can use *(c+i)==c[i]
{
printf("%c",*c);
c++;
}
printf("\n");
}

int main()
{
char* c="Hello";
/*in previous case we use c[20]="hello"
 which will go into the stack in the character array
 of size 20
in this case
char *c="hello"
the string gets stored as a constant during the compile time and it 
cannot be modified.
*/
print(c);
}
