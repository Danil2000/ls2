#include "uls.h"

void mx_print_flag_one(char **s, int size) {
	int i = 0;
	size = 0;

	mx_bubble_sort(s, size);
	while (s[i]) {
		mx_printstr(s[i]);
		mx_printchar('\n');
		i++;
	}

}

void mx_ls_a_one(DIR *dir, char **argv) {
	char **s = NULL;
	int size = 0;
	DIR *dir1;

	dir1 = opendir(argv[2]);
	size = mx_dir_size(dir);
	//mx_printint(size);
	s =  malloc((sizeof(char *) * size) + 1);
	s = mx_write_to_arr_a(dir1, s);
	mx_print_flag_one(s, size);
	free(s);
	//closedir(dir1);
}