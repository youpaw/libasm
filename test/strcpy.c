//
// Created by youpaw on 13/04/24.
//
#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libasm.h"

static int test_comparison(const char *src) {
	char dest_ft[100]; // Destination buffer for ft_strcpy
	char dest_std[100]; // Destination buffer for strcpy

	// Copy using ft_strcpy
	ft_strcpy(dest_ft, src);

	// Copy using strcpy
	strcpy(dest_std, src);

	// Compare the results
	if (strcmp(dest_ft, dest_std) != 0) {
		printf("Test failed: Result of ft_strcpy doesn't match strcpy for input \"%s\"\n", src);
		return 1;
	} else
		printf("Test passed: Result of ft_strcpy matches strcpy for input \"%s\"\n", src);
	return 0;
}

int test_strcpy() {
	int ret = 0;

	// Run tests
	for (int i = 0; string_test_cases[i] != NULL; ++i) {
		ret += test_comparison(string_test_cases[i]);
	}
	return ret;
}
