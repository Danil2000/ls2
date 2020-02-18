#include "uls.h"

static char *choose(char **argv) {
	if (!argv[1])
		return ".";
	else {
		if (argv[1][0] != '-')
			return argv[1];
		else
			return argv[1];	
	}
	return NULL;
}


void mx_ls_atty(char **argv) {
	DIR *dir = NULL;
	char **s = NULL;
	int size_dir = 0;
	DIR *dir1 = NULL;
	char *c;

	c = choose(argv);
	dir = opendir(c);
	dir1 = opendir(c);
	size_dir = mx_dir_size(dir, 0);
	s = malloc((sizeof(char *) * size_dir) + 1);
	s = mx_write_to_arr(dir1,s);
	mx_print_flag_one(s, size_dir);
	mx_del_strarr(&s);
}
