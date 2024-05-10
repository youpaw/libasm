//
// Created by Darth Butterwell on 7/24/21.
//
#include <stdio.h>
#include "test.h"

char *string_test_cases[] = {
		"",				// Empty string
		"hello",			// Basic string
		"hello1\0world",	// String with embedded null character
		"hello2\0\0world",	// String with multiple embedded null characters
		"\0",				// String consisting of only null character
		NULL				// End marker for test cases array
};

int main() {
	printf("\n--- Test strlen START ---\n");
	if (test_strlen())
		printf("--- Test strlen FAILED ---\n");
	else
		printf("--- Test strlen SUCCESS ---\n");

	printf("\n--- Test strcpy START ---\n");
	if (test_strcpy())
		printf("--- Test strcpy FAILED ---\n");
	else
		printf("--- Test strcpy SUCCESS ---\n");

	printf("\n--- Test strcmp START ---\n");
	if (test_strcmp())
		printf("--- Test strcmp FAILED ---\n");
	else
		printf("--- Test strcmp SUCCESS ---\n");

	printf("\n--- Test strdup START ---\n");
	if (test_strdup())
		printf("--- Test strdup FAILED ---\n");
	else
		printf("--- Test strdup SUCCESS ---\n");

	printf("\n--- Test io START ---\n");
	if (test_io())
		printf("--- Test io FAILED ---\n");
	else
		printf("--- Test io SUCCESS ---\n");
	return 0;
}
