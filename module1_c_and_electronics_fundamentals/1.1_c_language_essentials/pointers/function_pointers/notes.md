function pointers
as the name suggests ,it is used to store address of functions.so far we used pointers as variables 
that would store address of other variables.
basically pointers are variables that would store address of other variables.
basically pointers are data types that can be used to store the address of some data
stored in computers memory or in other words to point to or refer to some data.and it does not always have
 to be a variable, data could be stored as constant also.
and we use pointers not just to store the address,we can dereference and get the value at whatever address the 
pointer is pointing to.
now we are saying that we have pointers that can store address of functions or in other words can point
  to functions .we can  use a pointer to function to dereferenceand execute the function.
what coulde be the address of the function ?
what are the use caese in which we may want to have them?
the memory that is allocated to an application or a program can typically divided into four segments.
heap,stack,static/global,code(text)
basically, a function is a set of instructions to perform a sub task 
in memory a function will be one contiguous block with some instructions,the address of a function what we 
also call entry point of a function will be the address of the first instruction in the function.
a function call in the machine lenguage will basically be an instruction to jump to entry poit of some function
to jump to first instruction in a function.
function pointer basically mean that function pointers store the starting address or entry point of the block
of memory containingg all the instructions in a function.

