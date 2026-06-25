 Types, Sizes, and Signedness in C

*Type defines what kind of data a variable stores (`char`, `int`, `float`, `double`).
* Size defines how much memory a data type occupies.
* Use sizeof() to find the size of a data type or variable.
* Signed types store both positive and negative values.
* Unsigned types store only positive values and provide a larger positive range.
* In Embedded C, avoid plain `int` because its size may vary across platforms.
* Prefer fixed-width types from `stdint.h`:

  *uint8_t → 8-bit unsigned
  *uint16_t → 16-bit unsigned
  * uint32_t → 32-bit unsigned
  *int8_t, int16_t, int32_t → signed versions
* Fixed-width types make memory usage predictable and portable across microcontrollers.
*One-line takeaway:
Type = What data is stored
Size = How much memory it uses
Signedness = Whether it can store negative values

data types are classified into 3 categories.they are
primary data types(built-in data types)-->int,float,char,double,void
derived data types-->arrrays,pointers,structures,unions
user defined data types-->typedef,enum
we have size modifiers (short,long)
we have sign modifiers(signed,unsigned)
Common Integer Types
Type-->Typical Size
char-->1 byte
signed char-->1 byte
unsigned char-->1 byte
short int-->2 bytes
unsigned short int-->2 bytes
int-->4 bytes
unsigned int-->4 bytes
long int-->8 bytes
unsigned long int-->8 bytes
long long int-->8 bytes
unsigned long long int-->8 bytes
float:
Single-precision floating-point type
Typically 4 bytes
About 6–7 decimal digits of precision
ex:float temperature = 36.5;
float pi = 3.14159;
double:
Double-precision floating-point type
Typically 8 bytes
About 15–16 decimal digits of precision
ex:double pi = 3.141592653589793;
ranges:
For an n-bit signed data type:
Minimum = -(2^(n-1))
Maximum = (2^(n-1)) - 1
For an n-bit unsigned data type:
Minimum = 0
Maximum = (2^n) - 1

Signedness Conversion 
In C, implicit type conversion happens when two values of different data
types are used together.the compiler automatically converts one type to
another so that both operands have a compatible type.

Conversions commonly occur during:
Comparisons (<, >, ==, !=)
Arithmetic operations (+, -, *, /)
Assignments (=)
Function calls
Return statements
ex:
#include <stdio.h>

int main()
{
    int a = -10;
    unsigned int b = 10;

    if (a < b)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
output:false
-10 → 4294967286
4294967286 < 10


### Why `int` is Dangerous in Embedded Systems — Summary
Why int is Dangerous in Embedded Systems
* The size of `int` is **not fixed** and can vary between processors.
* An `int` may be **2 bytes** on some microcontrollers and **4 bytes** on others.
* This can cause:

  * Portability issues
  * Memory waste
  * Communication/protocol bugs
  * Incorrect hardware register access
* Embedded systems often have limited RAM, so every byte matters.
* Hardware registers and communication packets usually require exact data sizes.

### Solution

Use fixed-width types from `stdint.h`:

uint8_t   // 8-bit unsigned
uint16_t  // 16-bit unsigned
uint32_t  // 32-bit unsigned

int8_t    // 8-bit signed
int16_t   // 16-bit signed
int32_t   // 32-bit signed


 One-Line Interview Answer
int is dangerous in embedded systems because its size is implementation-dependent.
 Fixed-width types from stdint.h provide predictable memory usage and portable code.

