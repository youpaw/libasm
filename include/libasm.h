//
// Created by Darth Butterwell on 7/24/21.
//

#ifndef LIBASM_H
#define LIBASM_H
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s1);


#endif //LIBASM_H
