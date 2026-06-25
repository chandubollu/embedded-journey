## what is constant?
- As the name suggests-somethig that never change.
- once defined cannot be modified later in the code.
### defining constants(2 ways)
1.using #define
2.using const

### using #define
#### syntax: #define NAME value
- sometimes name is also called as MACRO.
-job of preprocessor is replacing header files with their actual content.
-job of preprocessor(not compiler) to replace NAME with value.
##### example1:
```c
#include<stdio.h>
#define PI 3.14159
int main()
{
    printf("%.5f",PI);
    return 0;
}
```
#### TakeAways
1.please don't add semicolon at the end.
##### example2
```c
#include<stdio.h>
#define PI 3.14159;
int main()
{
    printf("%.5f",PI);
    return 0;
}
```
2.choosing capital letters for NAME is good practice.
```c
#include<stdio.h>
#define value 89
int main()
{
    int value = 74;
    printf("%d",value);
    return 0;
}

                    |||
#include<stdio.h>
#define value 89
int main()
{
    int 89 = 74;
    printf("%d",value);
    return 0;
}
```


3.whatever inside double quotes " " won't get replaced.
```c
#include<stdio.h>
#define value 89
int main()
{
    printf("value is %d",value);
    return 0;
}
```
4.we can  use macros like functions.
#### example3:
```c
#include<stdio.h>
#define add(x,y) x+y
int main()
{
    printf("addition of two numbers:%d",add(4,3));
    return 0;
}
```
5.we can write multiple lines using \
#### example4
```c
#include<stdio.h>
#define greater(x,y) if(x>y)\
        printf("%d is greater than %d",x,y);\
        else\
        printf("%d is lesser than %d",x,y);
int main(){
    greater(5,6);
    return 0;
}
```
6.first expansion then evaluation.
####example5
```c
#include<stdio.h>
#define add(x,y) x+y
int main()
{
    printf("result of expression a*b+c is :%d",5*add(4,3));
    return 0;
}
```
- because of 5 * 4+3
not 5*7
7.some predefined macros like __DATE__,__TIME__ can print current date and time.
#### example7
```c
#include<stdio.h>
int main()
{
    printf("Date:%s\n",__DATE__);
    printf("Time:%s\n",__TIME__);
    return 0;
}
```

## using CONST
###### Syntax: const some_data_type some_variable_name
###### example7
```c
#include<stdio.h>
int main()
{
    const int var=67;
    var=57;
    printf("%d",var);
}
```