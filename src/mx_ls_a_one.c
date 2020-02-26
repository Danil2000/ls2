#include "uls.h"

void mx_print_flag_one(char **s, int size) {
	int i = 0;
	size = 0;

	mx_bubble_sort(s, size);
	while (s[i]) {
		mx_print_with_new_line(s[i]);
		i++;
	}
}

void mx_ls_a_one(DIR *dir, char **argv) {
	char **s = NULL;
	int size = 0;
	DIR *dir1;

	if (!argv[2])
		dir1 = opendir(".");
	else
		dir1 = opendir(argv[2]);
	size = mx_dir_size(dir, 1);
	s =  malloc((sizeof(char *) * size) + 1);
	s = mx_write_to_arr_a(dir1, s);
	mx_print_flag_one(s, size);
}
