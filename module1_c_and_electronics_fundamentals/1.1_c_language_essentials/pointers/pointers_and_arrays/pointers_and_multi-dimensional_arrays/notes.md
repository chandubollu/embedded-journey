int A[5]
int *p=A;
print p;//address of 1 st element of  array
print *p//valua of 1 st element in the array
print *(p+2)//value of 3rd element in the array
print *(A+2)//value of 3rd element in the array
lets see about 2 dimensional array
int B[2][3]
we are creating array of array
we are creating two 1 dimentional arrays of three elements each thai is B[0],B[1]
1 dimensional array of 3 integers is 12 bytes

int *p=B;
will give compilation error because it is not an pointer to  integer 
it is a pointer to  1dimensional array of 3 integers
the type of a pointer matters not when you have to read the address.
it matters when you dereference or when you perform pointer arithmetic
we have to define  apointer to 1d array of three integers
int (*p)[3]=B;
print B//&B[0]
it will give address of B[0]
print *B//B[0]
it gives the value of B[0] that is &B[0][0]
print B+1;//we are pointing to next 1 dimentional array of 3 integers
it gives addresss of B[1] that is &B[1]
print *(B+1) it gives the value of B[1] that is &B[1][0]
print *(B=1)+2 // B[1]+2 or &B[1][2]
print *(*B+1)//B[0][1]
for 2d arrays
B[i][j]=*(B[i]+j)
=*(*(B+i)+j)

3-dimensional array
int c[3][2][2]
it is an array of collection of 2d arrays
c[0],c[1],c[2]
c[0] correspond to 2d array,c[0][0],c[0][1],c[0][2]
c[1] correspond to 2d array,c[1][0],c[1][1],c[1][2]
c[3] correspond to 2d array,c[2][0],c[2][1],c[2][2]
we further breakdown 2d arrays to 1d array
c[0][0][0]  
c[0][0][1]
c[0][0][2]
like this





 


