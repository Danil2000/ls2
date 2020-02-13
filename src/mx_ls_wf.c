#include "uls.h"

char** mx_write_to_arr(DIR *dir, char **s) {
	int i = 0;
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		char *help_v = NULL;
	
		if (entry->d_name[0] != '.') //если первый символ названия файла не равен . (т.е. не скрытый файл)
		{
			help_v = mx_strdup(entry->d_name);
			s[i] = mx_strdup(help_v);
			mx_strdel(&help_v);
			//s[i] = mx_strdup(entry->d_name);
			i++;
		}
	}
	s[i] = NULL;
	closedir(dir);
	//free(entry);
	return s; //массив с названиями файлов
}

void mx_ls_wf(DIR *dir, char *argv) {
	DIR *dir1;
	int size_dir = 0;
	char **s = NULL;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir, 0);
	dir1 = opendir(argv);
	s = (char**)malloc(sizeof(char **) * (size_dir + 1));
	s = mx_write_to_arr(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);
	mx_get_width(s, count, 0);
	mx_del_strarr(&s);
}
