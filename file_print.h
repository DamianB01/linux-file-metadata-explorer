#ifndef ZADANIE5_FILE_PRINT_H
#define ZADANIE5_FILE_PRINT_H

#include <sys/stat.h>
#include <time.h>

void print_file_info(const char *path, const struct stat *st, int indent);
void format_time(char *buf, size_t bufsize, time_t t);

#endif //ZADANIE5_FILE_PRINT_H
