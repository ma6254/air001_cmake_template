#ifndef AIR001_CMAKE_MAIN_H
#define AIR001_CMAKE_MAIN_H
#include <sys/stat.h>

int _close(int file) { return -1; }
int _lseek(int file, int ptr, int dir) { return 0; }
int _read(int file, char *ptr, int len) { return 0; }
int _write(int file, char *ptr, int len) { return len; }
void *_sbrk(ptrdiff_t incr) { return (void *)-1; }


#endif //AIR001_CMAKE_MAIN_H
