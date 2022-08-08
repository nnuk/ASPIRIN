# include <stdio.h>
# include <string.h>
# include <stdlib.h>


// function that performs the specific string count
// It reads the file character by character
// stores the specific string count and then returns the count
int string_count(char* Aspirin_file, char* string) {

	// pointer of type File to communicate the file to program
	FILE *fPtr2;

	// initializing the count
	int num_of_atoms = 0;

	// integers to store the string count and string length
	int chemical_count, len;

	// opening the file in read mode
	fPtr2 = fopen(Aspirin_file, "r");

	// checking if file is there or not
	if (fPtr2 == NULL)
	{
		printf("\nThe file is missing or corrupted");
	}
	else  // printing out the Molecular Formula
	{
		//printf("\nBelow presents the Molecular Formula:\n") ;

		len = strlen(string);

		// an infinite loop to find the count.
		// this infinite loop breaks when the program reaches end of the file
		for (;;) {

			int i;

			if (EOF == (chemical_count = fgetc(fPtr2))) break;        // Here EOF represents the End of File

			if ((char)chemical_count != *string) continue;

			for (i = 1;i < len;++i) {
				if (EOF == (chemical_count = fgetc(fPtr2))) goto end;
				if ((char)chemical_count != string[i]) {
					fseek(fPtr2, 1 - i, SEEK_CUR);
					goto next;
				}
			}
			++num_of_atoms;        // adding the count
		next:;
		}
	end:
		fclose(fPtr2);
		printf("\n");
		return num_of_atoms;       // returns the number of atoms for the specified character
	}

}


