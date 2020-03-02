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

static void l_print(char **f_name, char **s) {
	int count = 0;
	char **arr_print = NULL;

	count = mx_len_arr(f_name);
	arr_print = (char**)malloc(sizeof(char*) * (count + 1));
	arr_print[count] = NULL;
	mx_printstr("total ");
	mx_printint(mx_total(f_name, count));
	mx_printstr("\n");
	mx_add_permissions(arr_print, count, f_name);
	mx_count_link(arr_print, count, f_name);
	mx_owner_names(arr_print, count, f_name);
	mx_add_group_name(arr_print, count, f_name);
	mx_get_file_size(arr_print, count, f_name);
	mx_add_time(arr_print, count, f_name);
	mx_add_name(arr_print, count, s, f_name);
	mx_print_strarr(arr_print, "\n");
	mx_del_strarr(&arr_print);
}

void mx_ls_l(DIR *dir, char **argv) {
	char **s = NULL;
	char **l_files = NULL;
	int s_dir = 0;
	DIR *dir1;
	int len_files = 0;

	if (!argv[2])
		dir1 = opendir(".");
	else
		dir1 = opendir(argv[2]);
	s_dir = mx_dir_size(dir, 0);
	s = malloc(sizeof(char *) * (s_dir + 1));
	s = mx_write_to_arr(dir1, s);
	if (!argv[2])
		l_files = files_with_adsres(s, ".");
	else
		l_files = files_with_adsres(s, argv[2]);
	len_files = mx_len_arr(l_files);
	mx_bubble_sort(l_files, len_files);
	mx_bubble_sort(s, mx_len_arr(s));
	l_print(l_files, s);
	mx_del_strarr(&l_files);
	mx_del_strarr(&s);
	closedir(dir1);
}
