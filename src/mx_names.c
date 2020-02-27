#include "uls.h"

char *mx_get_owner_name(struct stat file) {
	char *owner_name;
    struct passwd *owner;

    owner = getpwuid(file.st_uid);
    owner_name = mx_strdup(owner->pw_name);
    return owner_name;
}

void mx_dop_owner_name(char **arr_print, int count, char **dop_arr) {
	int i;
	char *spcs;
	char *help1;
	char *help2;

	for (i = 0; i < count; i++)
	{
		spcs = spaces(dop_arr, dop_arr[i], count);
		help1 = mx_strjoin(dop_arr[i], spcs);
		help2 = mx_strjoin(help1, " ");
		help1 = mx_strjoin(arr_print[i], help2);
		arr_print[i] = mx_strdup(help1);
	}
    mx_strdel(&spcs);
    mx_strdel(&help1);
    mx_strdel(&help2);
	return;
}

void mx_owner_names(char **arr_print, int count, char **files) {
    int i;
    struct stat file;
    char **help_arr;

    help_arr = (char **)malloc(sizeof(char **) * (count + 1));
    for (i = 0; i < count; i++)
    {
        lstat(files[i], &file);
        help_arr[i] = mx_get_owner_name(file);
   	}
   	help_arr[count] = NULL;
   	mx_dop_owner_name(arr_print, count, help_arr);
    mx_del_strarr(&help_arr);
}
