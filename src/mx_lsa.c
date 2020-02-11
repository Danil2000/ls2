
#include "uls.h"
	
char **mx_write_to_arr_a(DIR *dir, char **s) {
	struct dirent *entry;
	int i =0;

	while ((entry = readdir(dir)) != NULL) {
		s[i] = mx_strdup(entry->d_name);
		i++;
	}
	s[i] = NULL;
	return s;
}

void mx_lsa(DIR *dir, char **argv) {
	DIR *dir1;
	int size_dir = 0;
	char **s = NULL;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir, 1); //количество папок и файлов в дирректории
	//mx_printint(size_dir);
	if (!argv[2]) {
		dir1 = opendir(".");
	}
	else{
		dir1 = opendir(argv[2]);
	}
	s = malloc(sizeof(char *) * (size_dir + 1));
	s = mx_write_to_arr_a(dir1, s);
	hres = mx_count_for_print(s);//длина максимального файла 
	//mx_printint(hres);
	count = mx_uls_len_name(hres);// кол-во название плюс пробелы
	//mx_printint(count);
	mx_get_width(s, count, 0);
	mx_del_strarr(&s);
	closedir(dir1);
}
