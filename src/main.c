#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* children;
    int size;
    // void* class;
} Tag;

typedef struct {
    char* source;
    size_t src_len;
    size_t cur;
    size_t bol;
    size_t row;
} Parser;

Tag parse_next_tag(Parser parser) {
    
}

size_t mystd_readfile(FILE* fd, char** buffer) {
    if (fd != NULL) {
        if (fseek(fd, 0L, SEEK_END) == 0) {
            size_t bufsize = ftell(fd);
            if (bufsize == -1) {
                fprintf(stderr, "File is not compelete\n");
                exit(-1);
            }
            if ((*buffer = malloc(sizeof(char) * (bufsize + 1))) < 0) {
                fprintf(stderr, "LOL, Buy some more ram!\n");
                exit(-1);
            }
            if (fseek(fd, 0L, SEEK_SET) != 0) {
                fprintf(stderr, "Can not seek to the fd begining!\n");
                exit(-1);
            }
            size_t newlen = fread(*buffer, sizeof(char), bufsize, fd);
            if (ferror(fd) != 0) {
                fprintf(stderr, "Error Reading fd\n");
            } else {
                *(*buffer + newlen + 1) = '\0';
            }
            return bufsize;
        }
        fclose(fd);
    } else {
        perror("fopen");
        errno = 0;
        exit(-1);
    }
    return -1;
}

int main(void) {
    FILE* file = fopen("./index.html", "rb");
    char* buffer = NULL;
    mystd_readfile(file, &buffer);
    printf("%s\n",buffer);
    free(buffer);
    return 0;
}

