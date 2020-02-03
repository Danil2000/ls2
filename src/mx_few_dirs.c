#include "uls.h"

static int size_of_args(char **argv) {
	int size = 0;

	if (argv[1][0] == '-') {
		size = mx_len_arr(argv) - 2;
	}
	else {
		size = mx_len_arr(argv) - 1;
	}
	return size;
}

static char **check_dirs(char **s, char** argv, int size) {
	int i = 0;

	mx_printint(size);
	s = (char**)malloc((size+1)*sizeof(char**));
	for (i = 1 ; i < size; i++)
	{
		if (mx_is_dir(argv[i])) {
			s[i] = argv[i];
			mx_printstr(s[i]);
		}
		else {
			mx_printstr(s[i]);
			mx_printspaces(mx_strlen(s[i]), size);
		}
	}
	return s;
}

DIR **mx_few_dirs(char** argv, char flag) {
	int size = 0;
	DIR **ls;
	char **s = NULL;

	ls = (DIR**)malloc(sizeof(ls));
	size = size_of_args(argv);
	check_dirs(s, argv, size);
	if (flag == 'a')
	{
		ls[0] = opendir(argv[1]);
	}
	return ls;
}
