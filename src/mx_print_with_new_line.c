#include "libmx.h"

void mx_print_with_new_line(char *str) {
	mx_printstr(str);
	mx_printchar('\n');
}
