#pragma once

void vid6()
{
	int num1,
		num2,
		* ptr;
	
	num1 = 100;
	ptr = &num1;
	num2 = *ptr;	//Right here is an example of indirection/dereferencing
	                //It's when you use a point to access the values within the address its pointing to
	                //Instead of using the original variable of that address itself

	printf("\nnum1 = %d\n&num1 = %p\n*ptr = %d\nptr = %p <- equals to the value addr of num1\n&ptr = %p <- the address of the pointer itself\nnum2 = %d\n", num1, &num1, *ptr, ptr, &ptr, num2);
}

//Shows similarities with arrays and pointers
void vid8()
{

	printf("Code belows demonstrates the similarities between a pointer an and array.\nAn array is just a continuous block of memory");
	printf("used to store one value after another.\n\nInternally, each address for an index gets the size of the data type of for that array\n");
	printf("where the size can vary between compilers. For example, an int can = 4 bytes or 8 bytes.\nNow how an array is like a pointer is");
	printf("from the array's starting address is the same as the\naddress of the first variable and then it goes up by 1 hex interms of");
	printf("the address-value for a new index.\n");

	char str[] = "Hello World";

	printf("\n");

	int i = 0;

	while(str[i+1] != '\0')
	{
		printf("str[%d] = '%c' -> &str[%d] = %p <- Adds 0x%p\n", i, str[i], i, &str[i], &str[i+1]-&str[i]);
		
		i++;
	}

	printf("str[%d] = '%c' -> &str[%d] = %p\n", 10, str[10], 10, &str[10]);


	printf("\nKey: &str == &str[0], the address of the array == the addr of the 1st index b/c its where the array beings.\n");

	printf("\n");
}