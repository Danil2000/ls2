#include "uls.h"

void mx_ls_d(char **argv) {
	if (!mx_strcmp(argv[2], "./"))
		mx_printstr("./\n");
	else {
		if(mx_len_arr(argv) == 2)
			mx_print_with_new_line(".");
		else {
			mx_print_with_new_line(argv[2]);
		}
	}
}
