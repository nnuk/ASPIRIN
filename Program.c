// This program reads molfile data, an input which contains the structural relationship information between atoms
// Calculations are performed in C, on the structural relationship of atoms
// The output is the molecular formula e.g. in this case "C9H8O4" (ASPIRIN)


# include <stdio.h>
# include <string.h>
# include <stdlib.h>
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
	fPtr = fopen("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", "r");

	// If the file doesn't exist we should get an error meassage otherwise proceed
	// error checking is useful as it contantly looks for mistakes
	if (fPtr == NULL)
	{
		printf("\nThe file is missing or corrupted");
	}
	else
	{
		printf("\nBelow presents the Data in the input MolFile:\n");


		// Reading from the file with the help of fgets() method
		while (fgets(buffer_size, 100, fPtr) != NULL)
		{
			// printing the data, line by line, with specified buffer size limit
			// Here s represents string of characters
			printf("%s", buffer_size);
		}

		// Closing the stream(file)
		fclose(fPtr);

		//printf("\nFile is closed");

	// Creating variable strings that I am looking for
	// after looking into data I will pick the desired string and remember the count
	char carbon_character[] = " C";
	char oxygen_character[] = " O";

	// initializing the count from zero
	int Carbon = 0;
	int Oxygen = 0;

	// storing the desired string count to a variable
	Carbon = string_count("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", carbon_character);
	Oxygen = string_count("C:/Users/nauma/Downloads/sum_formula_challenge/Aspirin.mol", oxygen_character);

	// print chemical formula with atoms
	printf("C%d", Carbon);
	printf("O%d", Oxygen);
	printf("\n");

	}
	return 0;
}