#include "uls.h"

static void mx_print_m(char **s) {
	int i = 0;

	while (s[i]) {
		mx_printstr(s[i]);
		mx_printstr(", ");
		i++;
	}
}

void mx_ls_m(DIR* dir, char **argv) {
	DIR *dir1;
	char **s = NULL;
	int size_dir = 0;

	size_dir = mx_dir_size(dir);
	if (!argv[2]) {
		dir1 = opendir(".");
	}
	else{
		dir1 = opendir(argv[2]);
	}
	s = malloc(sizeof(char *) * size_dir + 1);
	s = mx_write_to_arr(dir, s);
	mx_bubble_sort(s, size_dir);
	mx_print_m(s);
}
