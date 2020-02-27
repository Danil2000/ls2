#include "uls.h"

static void add_spaces(char **str, int expected_len) {
    char *tmp;

    while (mx_strlen(*str) < expected_len) {
        tmp = *str;
        *str = mx_strjoin(" ", tmp);
    }
    mx_strdel(&tmp);
}

static char *find_minor(struct stat file) {
    char *minor;
    char *tmp;

    if ((file.st_rdev & 0xffffff) > 256) {
        minor = mx_nbr_to_hex(file.st_rdev & 0xffffff);
        while (mx_strlen(minor) < 8) {
            tmp = minor;
            minor = mx_strjoin("0", tmp);
        }
        tmp = minor;
        minor = mx_strjoin(" 0x", tmp);
    }
    else
        minor = mx_itoa(file.st_rdev & 0xffffff);
    mx_strdel(&tmp);
    return minor;
}

char *mx_file_size(struct stat file) {
    char *file_size;
    char *tmp;
    char *minor;

    if ((file.st_mode & S_IFMT)== S_IFCHR || (file.st_mode & S_IFMT) == S_IFBLK) {
        tmp = mx_itoa((file.st_rdev >> 24) & 0xff);
        file_size = mx_strjoin(tmp, ","); 
        add_spaces(&file_size, 5);
        minor = find_minor(file);
        add_spaces(&minor, 4);
        tmp = file_size;
        file_size = mx_strjoin(tmp, minor);
    }
    else
        file_size = mx_itoa((int)file.st_size);
    //mx_strdel(&tmp);
    //mx_strdel(&minor);
    return file_size;
}

void mx_add_file_size_help(char **mas_for_print, int count_of_row, char **help_arr) {
    int i;
    char *space;
    char *help_v1;
    char *help_v2;

    for (i = 0; i < count_of_row; i++) {
        space = spaces(help_arr, help_arr[i], count_of_row);
        help_v1 = mx_strjoin(space, help_arr[i]);
        help_v2 = mx_strjoin(help_v1, " ");
        help_v1 = mx_strjoin(mas_for_print[i], help_v2);
        mas_for_print[i] = mx_strdup(help_v1);
    }
    mx_strdel(&space);
    mx_strdel(&help_v1);
    mx_strdel(&help_v2);
    return;
}

void mx_get_file_size(char **arr_print, int count, char **files) {
	int i = 0;
	struct stat file;
	char **help_arr = NULL;

	help_arr = (char **)malloc(sizeof(char **) * (count + 1));
	for (i = 0; i < count; i++)
	{
		lstat(files[i], &file);
		help_arr[i] = mx_file_size(file);
	}
	help_arr[count] = NULL;
	mx_add_file_size_help(arr_print, count, help_arr);
    mx_del_strarr(&help_arr);
}
