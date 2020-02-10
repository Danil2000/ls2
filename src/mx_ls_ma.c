#include "uls.h"

char **mx_choose_write(DIR *dir, char **argv, char **s) {
	if (!(mx_strcmp(argv[2], "-m")))
		s = mx_write_to_arr(dir, s);
	else if (!(mx_strcmp(argv[2], "-ma")))
		s = mx_write_to_arr_a(dir, s);
	return s;
}


void mx_ls_ma(DIR* dir, char **argv) {
	DIR *dir1;
	char **s = NULL;
	int size_dir = 0;
	int winsize = 0;

	size_dir = mx_dir_size(dir);
	if (!argv[2]) {
		dir1 = opendir(".");
	}
	else{
		dir1 = opendir(argv[2]);
	}
	s = malloc(sizeof(char *) * size_dir + 1);
	s = mx_choose_write(dir, argv, s);
	winsize = mx_size_win();
	mx_bubble_sort(s, size_dir);
	mx_print_m(s, winsize);
}