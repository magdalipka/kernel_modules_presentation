#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

const char* path = "/dev/messenger_server";

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments! :(\n");
        fprintf(stderr, "%s <Text>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* text = argv[1];

    int fd = open(path, O_WRONLY);

    if (fd == -1) {
        fprintf(stderr, "Error opening fd.\n");
        exit(EXIT_FAILURE);
    }

    ssize_t write_count;

    ssize_t written = write(fd, text, SIZE);

    if (written == -1) {
        fprintf(stderr, "Error writing to fd.\n");
        exit(EXIT_FAILURE);
    }


    if (close(fd) == -1) {
        fprintf(stderr, "Error closingfd.\n");
        exit(EXIT_FAILURE);
    }
}