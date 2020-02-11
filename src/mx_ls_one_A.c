#include "uls.h"

void mx_ls_A_one(DIR *dir, char **argv) {
	char **s = NULL;
	int size = 0;
	DIR *dir1;

	if (!argv[2]) {
		dir1 = opendir(".");
	}
	else{
		dir1 = opendir(argv[2]);
	}
	size = mx_dir_size(dir, 1) - 2;
	s =  malloc((sizeof(char *) * size) + 1);
	s = mx_write_to_arr_A(dir1, s);
	mx_print_flag_one(s, size);
	//free(s);
}
