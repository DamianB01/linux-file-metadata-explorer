#include <stdio.h>
#include <string.h>
#include <time.h>
#include "file_print.h"
#include "file_type.h"

void format_time(char *buf, size_t bufsize, time_t t)
{
    struct tm *tm_info = localtime(&t);
    if (tm_info == NULL) {
        snprintf(buf, bufsize, "N/A");
        return;
    }
    strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S", tm_info);
}

static void print_indent(int indent)
{
    for (int i = 0; i < indent; i++)
        putchar(' ');
}

void print_file_info(const char *path, const struct stat *st, int indent)
{
    char atime_buf[32];
    char mtime_buf[32];

    format_time(atime_buf, sizeof(atime_buf), st->st_atime);
    format_time(mtime_buf, sizeof(mtime_buf), st->st_mtime);

    print_indent(indent);
    printf("%s\n", path);

    print_indent(indent + 2);
    printf("Typ: %s\n", get_file_type(st->st_mode));

    print_indent(indent + 2);
    printf("Rozmiar: %lld B\n", (long long)st->st_size);

    print_indent(indent + 2);
    printf("i-węzeł: %llu\n", (unsigned long long)st->st_ino);

    print_indent(indent + 2);
    printf("Czas ostatniego dostępu: %s\n", atime_buf);

    print_indent(indent + 2);
    printf("Czas ostatniej modyfikacji: %s\n", mtime_buf);

    putchar('\n');
}
