//
// Created by Darth Butterwell on 7/24/21.
//
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"

int main(int ac, char **av)
{
//	size_t len;
//	len = ft_strlen("NULL");
////	len = strlen(NULL);
//	printf("%zu\n", len);
//	char dst[10];
//	char *str = ft_strcpy(dst, "abcd");
////	char *str = strcpy(dst, "abcd");
//	printf("%s\n", str);
//	int cmp = ft_strcmp("ab", "aa");
//  int cmp = strcmp("ab", "aa");
//    printf("\nret=%zd\n", write(1, NULL, 2));
//    printf("\nret=%zd\n", ft_write(1, NULL, 2));
//    printf("\nret=%zd\n", read(-1, NULL, 3));
//    printf("\nret=%zd\n", ft_read(0, NULL, 3));
    if (errno)
        perror(strerror(errno));
}
