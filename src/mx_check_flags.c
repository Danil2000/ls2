#include "uls.h"
//если флаг есть - возвращает 1
bool mx_check_flags(char argv) {
    char *all_flags;
    int i = 0;

    all_flags = "@1AaBbCcdeFfGgHhikLlmnOoPpqRrSsTtuUvWwx\0";
    while (all_flags[i]) {
        if (argv == all_flags[i]) {
            return 1; //если флаг есть
        }
        i++;
    }
    return 0;
}
