//
// Created by youpaw on 13/04/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "test.h"
#include "libasm.h"

static int test_comparison(const char *src) {
	char *ft_dup = ft_strdup(src);
	char *libc_dup = strdup(src);
	int ret = 0;

	/* Compare the results */
	if (strcmp(ft_dup, libc_dup) != 0) {
		printf("Test failed: Result of ft_strcpy doesn't match strcpy for input \"%s\"\n", src);
		ret = 1;
	} else
		printf("Test passed: Result of ft_strcpy matches strcpy for input \"%s\"\n", src);
	free(ft_dup);
	free(libc_dup);
	return ret;
}

int test_strdup() {
	int ret = 0;

	// Run tests
	for (int i = 0; string_test_cases[i] != NULL; ++i) {
		ret += test_comparison(string_test_cases[i]);
	}
	if (ft_strdup(NULL))
		ret++;
	return ret;
}
