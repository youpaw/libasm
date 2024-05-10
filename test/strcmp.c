//
// Created by youpaw on 13/04/24.
//
#include <stdio.h>
#include <string.h>
#include "libasm.h"

int test_strcmp() {
	int ret = 0;

	// Test case 1: Equal strings
	const char *str1 = "hello";
	const char *str2 = "hello";
	if (ft_strcmp(str1, str2) != strcmp(str1, str2)) {
		printf("Test case 1 failed\n");
		ret++;
	} else
		printf("Test case 1 passed\n");

	// Test case 2: Different lengths
	const char *str3 = "hello";
	const char *str4 = "hell";
	if (ft_strcmp(str3, str4) != strcmp(str3, str4)) {
		printf("Test case 2 failed\n");
		ret++;
	} else
		printf("Test case 2 passed\n");

	// Test case 3: Different strings
	const char *str5 = "hello";
	const char *str6 = "world";
	if (ft_strcmp(str5, str6) != strcmp(str5, str6)) {
		printf("Test case 3 failed\n");
		ret++;
	} else
		printf("Test case 3 passed\n");

	// Test case 4: Empty string vs non-empty string
	const char *str7 = "";
	const char *str8 = "hello";
	if (ft_strcmp(str7, str8) != strcmp(str7, str8)) {
		printf("Test case 4 failed\n");
		ret++;
	} else
		printf("Test case 4 passed\n");

	// Test case 5: Non-empty string vs empty string
	const char *str9 = "hello";
	const char *str10 = "";
	if (ft_strcmp(str9, str10) != strcmp(str9, str10)) {
		printf("Test case 5 failed\n");
		ret++;
	} else
		printf("Test case 5 passed\n");

	// Test case 6: Two empty strings
	const char *str11 = "";
	const char *str12 = "";
	if (ft_strcmp(str11, str12) != strcmp(str11, str12)) {
		printf("Test case 6 failed\n");
		ret++;
	} else
		printf("Test case 6 passed\n");

	return ret;
}
