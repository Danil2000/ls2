#include "uls.h"

void mx_printspaces(int count, int len) {
	count -= len;
    for (int i = 0; i < count; i += 8)
        mx_printchar('\t');
}
