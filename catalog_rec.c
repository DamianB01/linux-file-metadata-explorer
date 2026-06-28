#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include "catalog_rec.h"
#include "file_print.h"

#define PATH_MAX_LEN 4096
#define INDENT_STEP  4

void process_path(const char *path, int indent)
{
    struct stat st;

    if (lstat(path, &st) == -1) {
        fprintf(stderr, "Błąd: nie można odczytać '%s': %s\n", path, strerror(errno));
        return;
    }

    if (S_ISDIR(st.st_mode)) {
        for (int i = 0; i < indent; i++) putchar(' ');
        printf("%s\n", path);
        walk_directory(path, indent + INDENT_STEP);
    } else {
        print_file_info(path, &st, indent);
    }
}

void walk_directory(const char *path, int indent)
{
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Błąd: nie można otworzyć katalogu '%s': %s\n", path, strerror(errno));
        return;
    }

    struct dirent *entry;
    errno = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
        char child[PATH_MAX_LEN];
        int len = snprintf(child, sizeof(child), "%s/%s", path, entry->d_name);
        if (len < 0 || (size_t)len >= sizeof(child)) {
            fprintf(stderr, "Ostrzeżenie: ścieżka za długa, pomijam '%s/%s'\n", path, entry->d_name);
            continue;
        }
        process_path(child, indent);
        errno = 0;
    }
    if (errno != 0) fprintf(stderr, "Błąd podczas odczytu katalogu '%s': %s\n", path, strerror(errno));
    closedir(dir);
}
