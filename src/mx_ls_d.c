#include "mx_uls.h"

void mx_ls_d(char **argv) {
	if (!mx_strcmp(argv[2], "./"))
	{
		mx_printstr("./\n");
	}
	else {
		mx_printstr(argv[2]);
		mx_printchar('\n');
	}
}
