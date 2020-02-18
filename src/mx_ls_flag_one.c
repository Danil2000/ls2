#include "uls.h"

static DIR* check(DIR *dir1, char **argv) {
	if (!argv[2]) {
		if(isatty(1) == 0 && argv[1]) {
			dir1 = opendir(argv[1]);
		}
		else {
			dir1 = opendir(".");
		}
	}
	else {
		dir1 = opendir(argv[2]);
	}
	return dir1;
}

void mx_ls_flag_one(DIR *dir, char **argv) {
	char **s = NULL;
	int size = 0;
	DIR *dir1 = NULL;

	size = mx_dir_size(dir, 1);
	dir1 = check(dir1, argv);
	s =  malloc((sizeof(char *) * size) + 1);
	s = mx_write_to_arr(dir1, s);
	mx_bubble_sort(s, mx_len_arr(s));
	mx_print_flag_one(s, size);
}
