/*
 * Name: Kevin Vo
 * Filename: ptr_code.ccp
 * Date: June 20, 2020
 * Description: A follow-along tutorial for concepts and applications of pointers in C.
 */

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

//Compiler with Visual Studios does not accept char *words[5] = { "zero", "one", "two" };
//Needs to be char words[numWords][wordLength]; however will not with with example **ptr
//On the other hand, Netbeans with Cygwin works flawlessly for the following code.
/*
void vid14()
{
	const int wordLength = 5;	//This includes '\0' in "zero\0"
	const int numWords = 3;	//Number of words in the array words[][]
	char *words[wordLength] = { "zero", "one", "two" };
	char* ptr,
		** pptr;

	

	for (int i = 0; i < numWords; i++)
	{
		pptr = words + i;	//pptr acts as a temp for the addresses of the array

		ptr = *pptr;	//dereference pptr by one layer to be stored by ptr
		               //*pptr = the adress of (words + i)  instead of string value

	    //while-loop *ptr to print out each char individual with space in between
		while (*ptr != 0)
		{
			printf("%c ", *ptr);
			ptr++;
		}
		
	}
}
*/


void vid15(int argc, char** argv)
{
	printf("\nThis section illustrates how **argv being a double pointer is a multi-indirection/dereference.\nSo, it can be dereferences 2x to get the value of the commandline arguments.\n");
	printf("\n");

	for (int i = 0; i < argc; i++)
	{
		printf("*(argv + % d) = %s\n", i, *(argv + i));
	}

	printf("\n");
}

//Shows what generic/void pointers do
//Generic pointers is similar to how templates are as 
//you will have to declare its data type as you use it
void vid16()
{

	printf("\nGeneric Pointers are similar to how templates work in the way that it is meant to point to any data type.\n");
	printf("Then, when needed to retrieve the value, derefence with the data type like so: *(int*) <generic_ptr_name>\n\n");

	printf("You'd use generic pointers when you have a prog. with lots of data types and do not want a big mess with all the\n");
	printf("different tyes of pointers.\n\n");
	
	void* generic_ptr;

	const int sz = 10;
	int num[sz];
	char character[sz];

	//Assign ints to array
	for (int i = 0; i < sz; i++)
		num[i] = 100 - i;

	//Assign ints to array
	for (int i = 0; i < sz; i++)
		character[i] = 64 + i;

	//char strArr[sz][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" }; //Will not work with Visual Studio's compiler

	printf("\n***************************************************\n");
	printf("*    Using same Generic Pointer with INT now      *");
	printf("\n***************************************************\n");


	generic_ptr = num;	//Assign generic pointer to address of int array

	for (int i = 0; i < sz; i++)
	{
		printf("*(int*) (generic_ptr + %i) = %d\n", i, *(int*)generic_ptr);

		generic_ptr = (int*)generic_ptr + 1;	//increments
											    //Has to be done this way *(int*)generic_ptr++; will not work
	}

	printf("\n***************************************************\n");
	printf("*    Using same Generic Pointer with CHAR now     *\n");
	printf("***************************************************\n");

	generic_ptr = character;	//Assign generic pointer to address of character array

	for (int i = 0; i < sz; i++)
	{
		printf("\n*(char*)generic_ptr = %c", *(char*)generic_ptr);

		generic_ptr = (char*)generic_ptr + 1;	//increments
											    //Has to be done this way *(char*)generic_ptr++; will not work
	}

	
	printf("\n");

	//Will not work with Visual Studio's compiler, but works on Netbeans + Cygwin
	/*

	printf("\n***************************************************\n");
	printf("*    Using same Generic Pointer with String now     *\n");
	printf("***************************************************\n");

	generic_ptr = strArr;

	for (int i = 0; i < sz; i++)
	{
		printf("\n*(char**)generic_ptr = %s", *(char**)generic_ptr);	//note that char** represents char* strArr[]; which means a pointer-to-a-pointer-to-a-char

		generic_ptr = (char**)generic_ptr + 1;
	}

	printf("\n");
	*/




	printf("\nKey: Only increment this way: <generic_ptr_name> = (int*) <generic_ptr_name> + 1;\n");

	printf("\nKey: note that if point to an array of strings, char** represents char* strArr[]; which means a pointer-to-a-pointer-to-a-char\n\n");
	
}


//Demonstrates memmory allocation
//Creating usable memory space during runtime

//allocates then concatinates parameter string with the string allocated

char* strAllocation(const char* inStr)
{
	char* s;	//creating char ptr to point to the soon-to-be allocated memory for a string

	const int maxStrLen = 100;

	s = (char*)malloc(maxStrLen);

	s[0] = 0;	//This assigns the allocated memory to NULL to create an empty string
	
	//strcat_s(s, size_to_allocate, "SOME STRING VALUE") was used to prevent overloads that comes from strcat(s, "SOME STRING VALUE");

	
	//added tr
	char addStr[] = "Hello ";

	strcat_s(s, sizeof(s) + sizeof(addStr), addStr); //attaches the string "Kevin" to the allocated memeory 
						//for the empty string

	strcat_s(s, sizeof(s) + 20, inStr);
	strcat_s(s, sizeof(s) + 20, "\n");




	return s;
}
void vid17()
{
	void* generic_ptr = strAllocation("Kevin");

	printf("\n%s", (char*)generic_ptr);

	free(generic_ptr);

	generic_ptr = strAllocation("world");

	printf("\n%s", generic_ptr);

	free(generic_ptr);

	printf("\n\nKey: <datatype>* s = (<datatype *>)malloc(<size>)\n");
	printf("\nmalloc(size) allocates memory from heap. Portion of memory reserved for dyn. allocation.\n");

	printf("\n\n----------------------\n");
	printf("\n| Static compile time |\n");
	printf("\n----------------------\n");
	printf("\n|                     |\n");
	printf("\n|                     |\n");
	printf("\n----------------------\n");
	printf("\n| Heap - runtime     |\n");
	printf("\n----------------------\n");
	printf("\n|                    |\n");
	printf("\n|       Data         |\n");
	printf("\n----------------------\n");
	printf("\n|                    |\n");
	printf("\n|       Code         |\n");
	printf("\n----------------------\n\n");
}

//Code below will demonstrate how to use malloc efficiently
//by using sizeof("hello"); you can allocate just the right
//amount of memory to now overflow or waste/have unused memory

//#define _CRT_SECURE_NO_WARNINGS on line 4 in C_Ptr_Pract.cpp demands that compiler igonores this error/warning (situational)
//This definition must be recognized first at the beginning

void vid18_ignore_error()
{
	char* s;
	int strSZ = sizeof("Hello World\n");	//calculate the number of bytes needed to allocate for this string

	printf("sizeof(\"Hello World\\n\") = %d", strSZ);

	s = (char*)malloc(strSZ);	//Allocate memory based on the calculate number of bytes
								//assigning address to the string s

	if (s == NULL)
		printf("\nFailed to allocate memory.\n");
	else
	{
		strncpy(s, "Hello World\n", strSZ);	//strncpy provided an 'error' because it was deprecated/obsolete
											//use strncpy_s(source, size, str_val, size) is one solution
											//or use #define _CRT_SECURE_NO_WARNINGS at the beginning for 
											//compiler to ignore

		printf("\ns = %s\n", s);

		free(s);
	}
}

void vid18_fix()
{
	char* s; 
	int strSZ = sizeof("Hello World\n");	//calculate the number of bytes needed to allocate for this string

	printf("sizeof(\"Hello World\\n\") = %d", strSZ);	

	s = (char*)malloc(strSZ);	//Allocate memory based on the calculate number of bytes
								//assigning address to the string s

	if (s == NULL)
		printf("\nFailed to allocate memory.\n");
	else
	{
		strncpy_s(s, strSZ, "Hello World\n", strSZ);

		printf("\ns = %s\n", s);

		free(s);
	}
}

void vid19()
{
	printf("\nThis section shows the difference between malloc and calloc\n\n");

	printf("\n(<datatype>*)malloc(size) - allocates memory as is, could be junk in there that can be overwritten.\n");
	printf("\n(<datatype>*)calloc(size, sizeof(<datatype>) - allocates then assigns 0s immediately.\n\n");

	char* s;

	const int sz_to_allocate = 5;	//the size to allocate in bytes

	printf("\nShowing malloc:\n-----------------\n");

	s = (char*)malloc(sz_to_allocate);

	for (int i = 0; i < sz_to_allocate; i++)
		printf("%d\n", *(s + i));

	free(s);

	printf("\nShowing calloc:\n----------------\n");

	s = (char*)calloc(sz_to_allocate, sizeof(char));

	if (s == NULL)	//checks if calloc is not successful. If not, ptr s will point to nothing a.k.a. NULL
	{
		printf("\nCalloc failed.\n");
		exit(0);
	}

	for (int i = 0; i < sz_to_allocate; i++)
		printf("%d\n", s[i]);

	printf("\n\n");

	free(s);


}


//Use realloc to change the size of allocated memory
void vid22()
{

	printf("\nThis uses realloc(source, new_size) to resized already allocated memory with either malloc or calloc.\n\n");
	printf("After realloc(source, newsize), you must:\n\tcopy it with strncpy_s(s,sz, old_val, sz)\n\tthen concatenate with strcat(s, newSz, new_val)\n\n");
	char* s;
	int sz;
	int new_sz;

	sz = sizeof("Hello World.\n");

	s = (char*)malloc(sz);	//allocates memory with size of the new value and new value's datatype
							//malloc does not clear, luckily we used 100% of the allocated memory
							//to avoid junk from old other data.

	strncpy_s(s, sz, "Hello World.", sz);	//copy string "Hello World." into the allocated memory

	printf("%s\n\n", s);

	new_sz = sz + sizeof(" Goodbye World.");	//obtain new size to concatenate later

	realloc(s, new_sz); //resizing already allocated memory

	strncpy_s(s, sz, "Hello World.", sz);

	strcat_s(s, new_sz, " Goodbye World.");

	printf("%s\n\n", s);

	free(s);

}

//Pointer Arithmetic
//How to move up in addresses with pointers
void vid23()
{
	const int sz = 10;
	int n[sz];
	char c[sz];
	
	void* ptr;

	ptr = &n;

	/*

		bool			= 1 byte
		char			= 1 byte
		ptr				= 4 bytes
		short int		= 4 bytes
		int				= 4 bytes
		long int		= 4 bytes
		float			= 4 bytes
		long long int   = 8 bytes
		double			= 8 bytes

	*/

	printf("\nbool = %d bytes\nchar = %d bytes\nptr = %d bytes\nshort = %d bytes\n"
		   "int = %d bytes\nlong = %d bytes\nlong long = %d bytes\nfloat = %d bytes\n"
		   "double = %d bytes\n\n", 
		   sizeof(bool), sizeof(char), sizeof(ptr), sizeof(short int), sizeof(int), sizeof(long int), 
		   sizeof(long long int), sizeof(float), sizeof(double));

	for (int i = 0; i < sz; i++)
		n[i] = 100 - i;

	for (int i = 0; i < sz; i++)
		c[i] = 64 + i;

	printf("\n\n---- int ----\n");
	for (int i = 0; i < sz; i++)
	{
		
		printf("\n*ptr = %d, ptr = %p -> size of pointer = %d --> size of var = %d bytes.", *(int*)ptr, (int*)ptr, sizeof(ptr), sizeof(n));

		ptr = (int*)ptr + 1;

	}

	printf("\n\n---- char ----\n");

	ptr = &c;

	for (int i = 0; i < sz; i++)
	{
		printf("\n*ptr = %c, ptr = %p -> size of pointer = %d --> size of var = %d bytes.", *(char*)ptr, (char*)ptr, sizeof(ptr), sizeof(c));

		ptr = (char*)ptr + 1;

	}

	printf("\n\nKey: Notice how a pointer variable always = 4 bytes where the variable size itself varies.\n");
	printf("\nThis is because an address on similar systems will always = 4 bytes.\n\n");

	printf("1 byte = 8 bits -> [0, 2^8 - 1] = [0, %d]\n4 bytes = 32 bits -> [0, 2^32 - 1] = [0, %llu]\n\n", 
		(int)pow(2, 8) - 1, (unsigned long long int)pow(2, 32) - 1);
	
}

/* I the structure below is ordered in terms of byte size, the struct would only take
 **/
typedef struct
{
	int int1;
	int int2;
	long long int ll1;
	double double1;
	
} structObjOrd;

const int numOfInstances = 1;

void vid25_ordered()
{
	printf("\n\n"
		"****************************************************************\n"
		"*          Pointer & Address Size of Structure (Ordered)       *\n"
		"* ------------------------------------------------------------ *\n"
		"****************************************************************\n\n");

	structObjOrd* ptr_obj1, * ptr_obj2;


	ptr_obj1 = (structObjOrd*)calloc(numOfInstances, sizeof(structObjOrd));

	int min, max;

	for (int i = 0; i < numOfInstances; i++)
	{
		ptr_obj1[i].int1 = i;
		ptr_obj1[i].int2 = i * 20;
		ptr_obj1[i].ll1 = 4294968296 + i;
		ptr_obj1[i].double1 = 10000000000.0 + i;

	}
	
	printf("\n\nend-start addr = %p - %p\n\n", &(ptr_obj1[0].double1), &(ptr_obj1[0].int1));

	void* generic_ptr;

	printf("\nSize of the structure:"
		   "\n\t\tint1 = %d bytes\n"
		   "\n\t\tint2 = %d bytes\n"
		   "\n\t\tll1  = %d bytes\n"
	 	   "\n\t\tdoub = %d bytes\n"
		   "\n\t\t     + ------------\n"
		   "\n\t\tTOTAL= %d bytes\n\n",
		   sizeof(ptr_obj2->int1), sizeof(ptr_obj2->int2), sizeof(ptr_obj2->ll1),
		   sizeof(ptr_obj2->double1), sizeof(structObjOrd));

	ptr_obj2 = ptr_obj1;

	printf("\nptr_obj2 = ptr_obj1\n\n");
	for (int i = 0; i < numOfInstances; i++)
	{
		printf("\n\n--- Values, i = %d ---\n\n", i);

		printf("ptr_obj2[%d]->int1 = %d\nptr_obj2[%d]->int2 = %d\nptr_obj2[%d]->ll1 = %lld\nptr_obj2[%d]->double1 = %f\n",
			   i, ptr_obj2[i].int1, i, ptr_obj2[i].int2, i, ptr_obj2[i].ll1, i, ptr_obj2[i].double1);

		printf("\n\n--- Addresses, i = %d ---\n\n", i);

		printf("&ptr_obj2[%d]->int1 = %p\n&ptr_obj2[%d]->int2 = %p\n&ptr_obj2[%d]->ll1 = %p\n&ptr_obj2[%d]->double1 = %p\n",
			i, &ptr_obj2[i].int1, i, &ptr_obj2[i].int2, i, &ptr_obj2[i].ll1, i, &ptr_obj2[i].double1);
			
	}

	printf("\nSize of the structure obj1: %d bytes\n", sizeof(ptr_obj1));

	printf("\nSize of the structure obj2: %d bytes\n", sizeof(ptr_obj2));
}


typedef struct
{
	int int1;
	double double1;
	int int2;
	long long int ll1;

} structObj_mixed;

void vid25_mixed()
{
	printf("\n\n"
		   "****************************************************************\n"
		   "*          Pointer & Address Size of Structure (Mixed)         *\n"
		   "* ------------------------------------------------------------ *\n"
	       "****************************************************************\n\n");

	structObj_mixed* ptr_obj1, * ptr_obj2;


	ptr_obj1 = (structObj_mixed*)calloc(numOfInstances, sizeof(structObj_mixed));

	int min, max;

	for (int i = 0; i < numOfInstances; i++)
	{
		ptr_obj1[i].int1 = i;
		ptr_obj1[i].int2 = i * 20;
		ptr_obj1[i].ll1 = 4294968296 + i;
		ptr_obj1[i].double1 = 10000000000.0 + i;

	}
	//int x = (&(ptr_obj1[0].double1) - &(ptr_obj1[0].int1));
	printf("\n\nend-start addr = %p - %p\n\n", &(ptr_obj1[0].double1), &(ptr_obj1[0].int1));

	void* generic_ptr;

	printf("\nSize of the structure:"
		"\n\t\tint1 = %d bytes\n"
		"\n\t\tdoub = %d bytes\n"
		"\n\t\tint2 = %d bytes\n"
		"\n\t\tll1  = %d bytes\n"
		"\n\t\t     + ------------\n"
		"\n\t\tTOTAL= %d bytes\n\n",
		sizeof(ptr_obj2->int1), sizeof(ptr_obj2->int2), sizeof(ptr_obj2->ll1),
		sizeof(ptr_obj2->double1), sizeof(structObj_mixed));

	ptr_obj2 = ptr_obj1;

	printf("\nptr_obj2 = ptr_obj1\n\n");
	for (int i = 0; i < numOfInstances; i++)
	{
		printf("\n\n--- Values, i = %d ---\n\n", i);

		printf("ptr_obj2[%d]->int1 = %d\nptr_obj2[%d]->double1 = %f\nptr_obj2[%d]->int2 = %d\nptr_obj2[%d]->ll1 = %lld\n",
			i, ptr_obj2[i].int1, i, ptr_obj2[i].double1, i, ptr_obj2[i].int2, i, ptr_obj2[i].ll1);

		printf("\n\n--- Addresses, i = %d ---\n\n", i);

		printf("&ptr_obj2[%d]->int1 = %p\n&ptr_obj2[%d]->double1 = %p\n&ptr_obj2[%d]->int2 = %p\n&ptr_obj2[%d]->ll1 = %p\n",
			i, &ptr_obj2[i].int1, i, &ptr_obj2[i].double1, i, &ptr_obj2[i].int2, i, &ptr_obj2[i].ll1);

	}

	printf("\nSize of the structure obj1: %d bytes\n", sizeof(ptr_obj1));

	printf("\nSize of the structure obj2: %d bytes\n", sizeof(ptr_obj2));
}


typedef struct {
	int a;           // 4 bytes    
	//double b;        // 8 bytes    
	int c;           // 4 bytes    
	long long int d; // 8 bytes
	double b;		// 8 bytes
} MYSTRUCT;

#define COUNT 4

// a more complicated example

void his_vid25()
{
	MYSTRUCT* p, * q;
	void* v;

	printf("size of MYSTRUCT = %d\n", sizeof(MYSTRUCT));
	// IMPORTANT NOTE: the size of MYSTRUCT is NOT always 24 bytes! It will vary according to the processor architecture
	// ...
	// ... because some processor architectures will require a 'double' (say) to be at an address which is multiple of 8
	// ...
	// ... so it is very important to make no assumptions on the size of a structure: ALWAYS use 'sizeof' or let the
	// compiler use address arithmetic.

	// allocate some memory and clean it out: 'calloc' is quite useful here
	//

	// p = (MYSTRUCT*)calloc(COUNT, 24); // DO NOT DO THIS!
	p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));
	// initialize it to something interesting using a large floating point value for the double and a large value for
	// the 64-bit integer
	// this is so we can see where the compiler has inserted padding space to get the desired alignment for the 8 byte
	// quantities 'b' and 'd'
	for (int i = 0; i < COUNT; i++) {
		p[i].a = i;
		p[i].b = 10000000000.0 + i;
		p[i].c = i * 20;
		p[i].d = 4294967296 + i;
	}

	// first let's see what we've got
	// NOTE: look at the addresses of the 'double' and the 'long long int' - they start (are aligned) on an 8 byte
	// boundary
	q = p;
	printf("[0] values:\na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
	printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n", &q->a, &q->b, &q->c, &q->d);
	q = p + 3; // use address arithmetic to get the address of the fourth element (the array is zero based remember)
	printf("\n[3] values:\na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
	printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n\n", &q->a, &q->b, &q->c, &q->d);

	// finally a more advanced way of looking at what is inside the structure (all 32 bytes of it)
	// IMPORTANT NOTE: address arithmetic will not work with generic pointers unless you use a cast
	// this will not work: 'v = v + 3' (or 'v[3]') because the compiler doesn't know what the thing that 'v' (a generic
	// pointer) is pointing to is ...
	// ... and so it can't use address arithmetic; instead we have to use a cast to tell the compiler what 'v' is
	// pointing at

	v = p + 3; // look at the fourth element of the array of MYSTRUCTs
			   // print out the values as integers - the zeros show you where the padding has been inserted by the compiler
			   // NOTE: that we are using address arithmetic to move along MYSTRUCT as a set of 8 'int' values of 4 bytes each (32
			   // bytes in total)

	printf("Struct at index 3\n");
	for (int i = 0; i < sizeof(MYSTRUCT) / sizeof(int); i++) {
		printf("v[%d]=%d\n", i, ((int*)v)[i]);
	}

	
}

//Debugging with pointers
// This program displays any arguements weere passted to it
void vid29(const int argc, char** argv)
{
	int i;

	//(1) iterate over array of args
	for (int i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);

	printf("\n\n");

	//(2) dereferences each string arguement argv with a pointer
	//starting with **argv
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, *argv);
		argv++;	//put a breakpoint here to figure out how argv incr works
	}
	
}

//We're using a struct for this example to keep the pointers contiguous
//So it's easier to read
struct
{
	int*** ippp;
	int** ipp;
	int* ip;
	int i;
} s;

//Debugging with multiple references
void vid30()
{
	printf("\nPut a breakpoint here, make sure the configuration next to the execute button is set to 32-bit\n"
		"for readability\n\n"
		"Go to Debug->Windows->Memory 1 and search for address &s\n"
		"Which is the object name of our structure for vid30()\n"
		"And notice that\n\n");

	s.ippp = &s.ipp;
	s.ipp = &s.ip;
	s.ip = &s.i;
	s.i = 0x55555555;

	printf("(%p) s.ippp = &s.ipp = %p\n"
		   "(%p) s.ipp  = &s.ip  = %p\n"
		   "(%p) s.ip   = &s.ip  = %p\n"
		   "           &s.i            = %p\n\n",
		   &s.ippp, s.ippp, &s.ipp, s.ipp, 
		   &s.ip, s.ip, &s.i
	      );

	//Put a breakpoint here, make sure the configuration next to the execute button is set to 32-bit

	//for readability
	//Go to Debug->Windows->Memory 1 and search for address &s 
	//Which is the object name of our structure for vid30()
	//And notice that 
	/*
		s.ippp = &s.ipp;
		s.ipp = &s.ip;
		s.ip = &s.i;
		s.i = 0x55555555;
	*/

	//as ippp has a value of ipp's address and so on... like layers
}