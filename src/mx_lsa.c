#include "uls.h"

char** mx_write_to_arr_a(DIR *dir, char **s) {
	int i = 0;
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		s[i] = mx_strdup(entry->d_name);
		i++;
		//mx_printint(i);
	}
	s[i] = NULL;
	//free(entry);
	return s; //массив с названиями файлов
}


void mx_lsa(DIR *dir, char **argv) {
	DIR *dir1;
	int size_dir = 0;
	char **s = NULL;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir);
	dir1 = opendir(argv[2]);
	s = (char**)malloc(sizeof(char *) * (size_dir + 1));
	s = mx_write_to_arr_a(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);//тут выдает разные значения
	//mx_printint(ls->count);

	//mx_ls_print(ls->s, ls->count, ls->size_dir);
	mx_get_width(s, count, 0);

	free(s);
	//free(ls);
	//mx_printstr(argv[1]);
	closedir(dir1);
}
