//
// Created by youpaw on 13/04/24.
//
#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libasm.h"

static int test_comparison(const char *test_string) {
	size_t ft_len = ft_strlen(test_string);
	size_t libc_len = strlen(test_string);

	if (ft_len != libc_len) {
		printf("Test failed: Lengths don't match for string: \"%s\"\n", test_string);
		printf("ft_strlen: %zu, strlen: %zu\n", ft_len, libc_len);
		return 1;
	} else
		printf("Test passed: Lengths match for string: \"%s\"\n", test_string);
	return 0;
}


int test_strlen() {
	int ret = 0;

	// Run tests
	for (int i = 0; string_test_cases[i] != NULL; ++i) {
		ret += test_comparison(string_test_cases[i]);
	}
	return ret;
}
