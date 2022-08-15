// This program reads molfile data, an input which contains the structural relationship information between atoms
// Calculations are performed in C, on the structural relationship of atoms
// The output is the molecular formula e.g. in this case "C9H8O4" (ASPIRIN)
// Note: inputs (if user wants to change) are shown with double commented lines like this: ////////////
//                                                                                           input
//                                                                                        ///////////


// Library used for finding digit in the string
# include "ctype.h"

// Standard libraries
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Header function file
# include "aspirin.h"


int main()
{

	// To communicate between the file and program
	// we must declare a pointer of type FILE
	FILE *fPtr;


	// Declaring the char variable string array
	// Here we are specifying the buffer size for our fgets function ahead
	char buffer_size[100];


	// Opening our input molfile in read mode
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	fPtr = fopen("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", "r");
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// If the file doesn't exist we should get an error meassage otherwise proceed
	// error checking is useful as it contantly looks for mistakes
	if (fPtr == NULL)
	{
		printf("\nThe file is missing or corrupted");
	}
	else
	{
		printf("\nBelow presents the Data in the input MolFile:\n");

		// integers for counting the rows of the file and number of bond(s)
		int cnt = 1;
		int bond_size;

		// for keeping the string literals
		char * str_c;
		char * str_o;
		char * str_n;

		// arrays being zero based in C, hence setting top = -1
		// setting stack capacity to 20
		int top = -1, stack[20];
		int top_o = -1, stack_o[20];
		int top_n = -1, stack_n[20];

		//array declaration of 20 rows and 3 columns involving the bond block in Mol File
		int arr[20][3];


		// Reading from the file with the help of fgets() method
		while (fgets(buffer_size, 100, fPtr) != NULL)
		{
			// printing the data, line by line, with specified buffer size limit
			// Here s represents string of characters
			printf("%s", buffer_size);

			if (cnt == 4)
			{
				char *str1 = buffer_size;
				while (*str1)
				{
					if (isdigit(*str1)) {                              // "isdigit", checks whether the character is numeric or not.
						bond_size = strtol(str1, &str1, 10);           // "strtol", converts a string to long integer, ignores whitespaces and stops when a non integer character comes.
						break;
					}
					else {
						str1++;
					}
				}

				//printf( "%d" , bond_size ) ;
			}
			str_c = strstr(buffer_size, " C ");                      // "strstr", returns the substring from the first match till the last character.
			str_o = strstr(buffer_size, " O ");                      //  -----------------------------------------------------------------------
			str_n = strstr(buffer_size, " N ");                      //  -----------------------------------------------------------------------

			if (str_c != NULL)
			{
				top = top + 1;
				stack[top] = cnt - 4;                                // Holds the integers involved in Carbon connections

			}

			if (str_o != NULL)
			{

				top_o = top_o + 1;
				stack_o[top_o] = cnt - 4;                            // Holds the integers involved in Oxygen connections

			}

			if (str_n != NULL)
			{
				top_n = top_n + 1;
				stack_n[top_n] = cnt - 4;                            // Holds the integers involved in Nitrogen connections

			}


			if (cnt >= bond_size + 5) {
				char *str = buffer_size;
				char *p = str;
				int k = 0;
				while (*p) {
					if (isdigit(*p)) {
						int val = strtol(p, &p, 10);

						if (val != 0) {
							arr[cnt - (bond_size + 5)][k] = val;
							k++;
						}
					}
					else {
						p++;
					}
				}
			}
			cnt += 1;
		}

		}

		// Closing the stream(file)
		fclose(fPtr);

		// integers used for iterating over Carbon, Oxygen and Nitrogen stacks
		int carb, oxy, nitro;

		// integers used for storing all the Carbon, Oxygen and Nitrogen bond connections
		int c_joined = 0;
		int o_joined = 0;
		int n_joined = 0;


		// finding C
		//Finding Carbon positions
		if (top != -1) {

			for (carb = top; carb >= 0;--carb)
			{
				for (int q = 0; q < bond_size; q++)
				{
					if (arr[q][0] == stack[carb] || arr[q][1] == stack[carb]) {

						c_joined = c_joined + arr[q][2];
					}
				}
			}

		}


		// Finding O
		// Finding Oxygen positions
		if (top_o != -1) {

			for (oxy = top_o; oxy >= 0;--oxy)
			{
				for (int z = 0; z < bond_size; z++)
				{
					if (arr[z][0] == stack_o[oxy] || arr[z][1] == stack_o[oxy]) {

						o_joined = o_joined + arr[z][2];
					}
				}

			}

		}


		// finding N
		//Finding Nitrogen positions
		if (top_n != -1) {

			for (nitro = top_n; nitro >= 0;--nitro)
			{
				for (int m = 0; m < bond_size; m++)
				{
					if (arr[m][0] == stack_n[nitro] || arr[m][1] == stack_n[nitro]) {

						n_joined = n_joined + arr[m][2];
					}
				}
			}

		}

	// Creating variable strings that I am looking for
	// after looking into data I will pick the desired string and remember the count
	char carbon_character[] = " C";
	char oxygen_character[] = " O";
	char nitrogen_character[] = " N";

	// initializing the count from zero
	int Carbon = 0;
	int Oxygen = 0;
	int Nitrogen = 0;
	int Hydrogen = 0;

	// storing the desired string count to a variable
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Carbon = string_count("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", carbon_character);
	Oxygen = string_count("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", oxygen_character);
	Nitrogen = string_count("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", nitrogen_character);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// storing the difference of Carbon and Oxygen connections with hydrogen into seperate integers
	// and then adding them
	int c_h, o_h, n_h;
	c_h = (Carbon * 4) - c_joined;
	o_h = (Oxygen * 2) - o_joined;
	n_h = (Nitrogen * 3) - n_joined;
	Hydrogen = c_h + o_h + n_h;

	// print chemical formula with atoms
	printf("Formula  ==>  ");

	if (c_h > 0) {

		printf("C%d", Carbon);                        // prints Carbon atoms if condition is satisfied
	}

	if (n_h > 0) {

		printf("N%d", Nitrogen);                      // prints Nitrogen atoms if condition is satisfied
	}

	printf("H%d", Hydrogen);                          // prints Hydrogen atoms if condition is satisfied

	if (o_h > 0) {

		printf("O%d", Oxygen);                        // prints Oxygen atoms if condition is satisfied
	}

	printf("\n");

	}
	return 0;
}