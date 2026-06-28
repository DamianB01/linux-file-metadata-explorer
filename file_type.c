#include "file_type.h"

const char *get_file_type(mode_t mode)
{
    if (S_ISREG(mode))  return "Plik zwykły";
    if (S_ISLNK(mode))  return "Link symboliczny";
    if (S_ISFIFO(mode)) return "Potok nazwany (FIFO)";
    if (S_ISCHR(mode))  return "Urządzenie znakowe";
    if (S_ISBLK(mode))  return "Urządzenie blokowe";
    if (S_ISDIR(mode))  return "Katalog";
    if (S_ISSOCK(mode)) return "Gniazdo";
    return "Nieznany";
}