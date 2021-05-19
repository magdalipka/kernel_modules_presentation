#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

const char* path = "/dev/messenger_server";

int main(int argc, char** argv) {

    char* text;

    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error opening fd.\n");
        exit(EXIT_FAILURE);
    }

    ssize_t read_count = read(fd, text, SIZE);

    if (read_count == -1) {
        fprintf(stderr, "Error writing to fd.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%s", text);

    if (close(fd) == -1) {
        fprintf(stderr, "Error closingfd.\n");
        exit(EXIT_FAILURE);
    }
}