#include "uls.h"


static char **files_with_adsres(char **s, char *address) {
	int count = 0;
	char **chnged_files = NULL;
	char *help_v;
	int i;

	count = mx_len_arr(s);
	chnged_files = (char**)malloc(sizeof(char*) * (count + 1));
	chnged_files[count] = NULL;
	for(i = 0; i < count; i++) {
		help_v = mx_strjoin(address, "/");
		chnged_files[i] = mx_strjoin(help_v, s[i]);
		mx_strdel(&help_v);
	}
	return chnged_files;
}

static void l_print(char **f_name /*char **s*/) {
	int count = 0;
	char **arr_print = NULL;

	count = mx_len_arr(f_name);
	arr_print = (char**)malloc(sizeof(char*) * (count + 1));
	arr_print[count] = NULL;
	mx_printstr("total ");
	mx_printint(mx_total(f_name, count));
	mx_printstr("\n");
	mx_permissions(arr_print, count, f_name);
	mx_count_link(arr_print, count, f_name);
	mx_print_strarr(arr_print, "\n");
	
}
void mx_ls_l(DIR *dir, char **argv) {
	char **s = NULL;
	char **l_files;
	int s_dir = 0;
	DIR *dir1;

	dir1 = opendir(argv[2]);
	s_dir = mx_dir_size(dir, 0);
	s = malloc(sizeof(char *) * (s_dir + 1));
	s = mx_write_to_arr(dir1, s);
	l_files = files_with_adsres(s, argv[2]);
	l_print(l_files);
}
