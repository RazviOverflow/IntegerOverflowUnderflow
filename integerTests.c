/*
* RazviOverflow
* https://github.com/RazviOverflow
* The tests are meant to be tried on a 32bit architecture
* computer. Compile it with "gcc [...] -m32"
*/


#include <limits.h>
#include <stdio.h>

void integerToBinary(int, char*);

void main(){
	int aux = 0;
	//It shall never be more than 32 chars, 33 with null trailing byte.
	//This only shows us that it does indeed get truncated to 32 bits.
	char maxINTBinaryRepresentation[40]; 
	char minINTBinaryRepresentation[40];
	char auxCharArray[40];

	integerToBinary(INT_MAX, maxINTBinaryRepresentation);
	integerToBinary(INT_MIN, minINTBinaryRepresentation);

	puts("##### TESTING INTEGER OVER/UNDERFLOW PROPERTIES #####\n");
	

	puts("\nINT (signed) MAX is: ");
	printf("%d",INT_MAX);
	puts("\nINT (signed) MIN is: ");
	printf("%d",INT_MIN);

	puts("\nInsert the num to be summed\n");
	scanf("%d", &aux);
	integerToBinary(aux, auxCharArray);
	printf("%s",auxCharArray);
	puts("\n");

	
	printf("INT_MAX Binary is:\n%s (0x%X)\n", maxINTBinaryRepresentation, INT_MAX);
	printf("INT_MIN Binary is:\n%s (0x%X)\n", minINTBinaryRepresentation, INT_MIN);

	int sum = aux + INT_MAX;
	int subtraction = aux - INT_MIN;

	puts("\nYour number plus INT_MAX is: ");
	printf("%d\n",sum);
	integerToBinary(sum, auxCharArray);
	printf("%s",auxCharArray);

	puts("\nYour number minus INT_MIN is: ");
	printf("%d\n",subtraction);
	integerToBinary(subtraction, auxCharArray);
	printf("%s",auxCharArray);
	puts("\n");


}

void integerToBinary(int x, char *buf)
{
  unsigned char *ptr = (unsigned char *)&x;
  int pos = 0;
  for (int i = sizeof(int) - 1; i >= 0; i--)
    for (int j = CHAR_BIT - 1; j >= 0; j--) //CHAR_BIT is 8. The number of bis in a byte
      buf[pos++] = '0' + !!(ptr[i] & 1U << j);
  buf[pos] = '\0';
}
