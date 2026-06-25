##### volatile
- the volatile keyword is used to inform the compiler that the value of a variable may change unexpextedly and independently of the normal program flow.
- it serves as a hint to the compiler to avoid certain optimizations that could lead to incorrect behavior when accessing or modifying that variable.
##### syntax:
volatile int data;
int volatile data;