#include "uls.h"

bool mx_check_flags(char argv) {
    char *all_flags;
    int i = 0;
    int count = 0;

    all_flags = "@1AaBbCcdeFfGgHhikLlmnOoPpqRrSsTtuUvWwx\0";
    while (all_flags[i]) {
        if (argv != all_flags[i]) {
            count++;
    i++;
    }
    if (count != mx_strlen(all_flags))
        return 1;
    else
        return 0;
    }
    return 0;
}
