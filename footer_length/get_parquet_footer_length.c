#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./parquet_footer_size FILE\n");
        exit(-1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(-1);
    }
    // 4 byte footer length + 4 byte magic number
    uint32_t len;
    if (lseek(fd, -8, SEEK_END) == -1) {
        perror("lseek");
        exit(-1);
    }
    if (read(fd, &len, 4) == -1) {
        perror("read");
        exit(-1);
    }
    printf("%" PRIu32 "\n", len);
    (void) close(fd);
}
