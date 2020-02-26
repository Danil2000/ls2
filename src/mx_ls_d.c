#include "uls.h"

void mx_ls_d(char **argv) {
	if (!mx_strcmp(argv[2], "./"))
		mx_printstr("./\n");
	else
		mx_print_with_new_line(argv[2]);
}
