// Standard libraries to run an access test on windows
#ifdef WIN32
#include <io.h>
#define R_OK 4
#define access
#endif

// Header function file
# include "aspirin.h"

void test_string_count() {

	if (access(string_count, R_OK) == 4) {                       // R_OK reads the file, "4" is the read permission 

		printf("%s", "\nThe Test has Passed\n");

	}

	else {

		printf("%s", "\nThe Test has Failed\n");
	}

}

int main() {

	test_string_count();

	return 0;
}