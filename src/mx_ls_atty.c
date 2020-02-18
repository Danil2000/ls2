#include "uls.h"

void mx_ls_atty(char **argv) {
	DIR *dir;
	char **s = NULL;
	int size_dir = 0;
	DIR *dir1 = NULL;

	if (!argv[1]) {
		dir = opendir(".");
		dir1 = opendir(argv[1]);
		//exit(1);
	}
	else {
		if (argv[1][0] != '-') {
			dir = opendir(argv[1]);
			dir1 = opendir(argv[1]);
		}
		else {
			dir = opendir(argv[2]);
			dir1 = opendir(argv[2]);
		}
	}
	size_dir = mx_dir_size(dir, 0);
	s = malloc((sizeof(char *) * size_dir) + 1);
	s = mx_write_to_arr(dir1,s);
	// mx_printstr(s[0]);
	mx_print_flag_one(s, size_dir);
	// mx_ls_flag_one(dir1, argv);
}
