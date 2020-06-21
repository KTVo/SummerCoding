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
		printf("str[%d] = '%c' -> &str[%d] = %p <- Adds 0x%p\n", i, str[i], i, &str[i], (&str[i+1]-&str[i]));
		
		i++;
	}

	printf("str[%d] = '%c' -> &str[%d] = %p\n", 10, str[10], 10, &str[10]);


	printf("\nKey: &str == &str[0], the address of the array == the addr of the 1st index b/c its where the array beings.\n");

	printf("\n");
}


//Multiple Indirection/Dereferences with INT
//Multiple indirection are derefences that requires multiple steps to 
//obtain the data
void vid13()
{
	printf("\nMultiple Indirection/Dereferences with INT\n");
	printf("\n\tThe code shows how a pointer can also have pointers, where eventually you can");
	printf("\n\tde-reference it layer by layer to obtain the value within the final address.\n\n");

	const int LENGTH = 3;
	int data[LENGTH];	//Array of ints
	int* ptr;	        //pointer to an int
	int** pptr;	        //pointer to a pointer

	for (int i = 0; i < LENGTH; i++)
		data[i] = 100-i;


	ptr = data;	//Pointer is pointing to the head of the array

	pptr = &ptr;	//Pointer is pointing to another pointer

	for (int i = 0; i < LENGTH; i++)
	{
		printf("data[%d] = %d\n", i, data[i]);
		printf("&data[%d] = %p\n", i, &data[i]);
		printf("*ptr = %d\n", *ptr);
		printf("*pptr = %p\n", *pptr);
		printf("&ptr = %p, pptr = %p\n", &ptr, pptr);
		printf("**pptr = %d <- same value as *ptr\n\n\n", **pptr);
	


		ptr++;	//Increments pointer
			    //How does incrementing the pointer also increments (pptr) the pointer pointing to that pointer?
				//Even if pptr = &ptr; is out side of the for-loop

	}


}

//Me having found with "double pointers" (**pptr)
//Having ** when making a pointer pointing to another pointer
//*** means there will be 3 layers of dereferencing 
void myTest13()
{
	int num = 100;

	int* ptr;
	int	** pptr;
	ptr = &num;
	pptr = &ptr;

	printf("num = %d\n", num);
	printf("*ptr = %d\n", *ptr);
	printf("**ptr = %d\n", **pptr);
}


void vid14()
{
	int wordLength = 40;
	char *words[wordLength] = { "zero", "one", "two" };
	char* ptr,
		** pptr;

	for (int i = 0; i < numWords; i++)
		printf("%s\n", words[i]);
}