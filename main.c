#include <stdio.h>
#include "catalog_rec.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        process_path(".", 0);
    }
    else {
        for (int i = 1; i < argc; i++) {
            process_path(argv[i], 0);
        }
    }
    return 0;
}
