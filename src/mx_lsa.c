#include "uls.h"

void mx_lsa(DIR *dir, char **argv) {
	mx_printchar('.');
	mx_printspaces(16,1);
	mx_printstr("..");
	mx_printspaces(16,2);
	mx_ls_A(dir, argv);
}
