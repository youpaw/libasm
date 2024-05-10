//
// Created by youpaw on 20/04/24.
//
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "libasm.h"

int test_io() {
	int ret = 0;
	int pipefd[2];
	ssize_t rc;
	if (pipe(pipefd) == -1) {
		perror("pipe initialisation failed");
		return -1;
	}

	// Test case 1: Basic writing
	const char *buffer = "Hello, world!";
	rc = ft_write(pipefd[1], buffer, strlen(buffer));
	if (rc == strlen(buffer)) {
		printf("Test case 1 passed: Basic writing\n");
	} else {
		printf("Test case 1 failed: Basic writing incorrect\n");
		ret += 1;
	}

	// Test case 2: Basic reading
	char read_buffer[20];
	rc = ft_read(pipefd[0], read_buffer, strlen(buffer));
	if (rc == strlen(buffer) && strncmp(buffer, read_buffer, strlen(buffer)) == 0) {
		printf("Test case 2 passed: Basic reading\n");
	} else {
		printf("Test case 2 failed: Basic reading incorrect\n");
		ret += 1;
	}



	// Test case 3: Trying to write to a closed file descriptor
	close(pipefd[1]);
	rc = ft_write(pipefd[1], buffer, strlen(buffer));
	if (rc == -1 && errno == EBADF) {
		printf("Test case 3 passed: ft_write: Correctly handled error for closed file descriptor\n");
	} else {
		printf("Test case 3 failed: ft_write: Error handling for closed file descriptor is invalid\n");
		ret += 1;
	}

	// Test case 4: Trying to write with an invalid argument
	rc = ft_write(STDOUT_FILENO, NULL, 10);
	if (rc == -1 && errno == EFAULT) {
		printf("Test case 4 passed: ft_write: Correctly handled error for bad address\n");
	} else {
		printf("Test case 4 failed: ft_write: Error handling for bad address is invalid\n");
		ret += 1;
	}

	// Test case 5: Trying to read with an invalid argument
	rc = ft_read(pipefd[0], NULL, 10);
	if (rc == 0 && errno == EFAULT) {
		printf("Test case 5 passed: ft_read: Correctly handled error for invalid argument\n");
	} else {
		printf("Test case 5 failed: ft_read: Error handling for bad address is invalid\n");
		ret += 1;
	}

	// Test case 6: Trying to read from a closed file descriptor
	close(pipefd[0]);
	rc = ft_read(pipefd[0], read_buffer, strlen(buffer));
	if (rc == -1 && errno == EBADF) {
		printf("Test case 6 passed: ft_read: Correctly handled error for closed file descriptor\n");
	} else {
		printf("Test case 6 failed: ft_read: Error handling for closed file descriptor is invalid\n");
		ret += 1;
	}

	return ret;
}
