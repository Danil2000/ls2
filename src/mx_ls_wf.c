#include "uls.h"

char** mx_write_to_arr(DIR *dir, char **s) {
	int i = 0;
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.') //если первый символ названия файла не равен . (т.е. не скрытый файл)
		{
			s[i] = entry->d_name;
			i++;
		}
		//mx_printint(i);
	}
	s[i] = NULL;
	//free(entry);
	return s; //массив с названиями файлов
}


void mx_ls_wf(DIR *dir, char *argv) {
	DIR *dir1;
	t_ls *ls = NULL;

	ls = malloc(sizeof(ls));
	ls->size_dir = mx_dir_size(dir);
	dir1 = opendir(argv);
	ls->s = malloc(sizeof(char *) * ls->size_dir + 1);
	ls->s = mx_write_to_arr(dir1, ls->s);
	ls->hres = mx_count_for_print(ls->s);
	ls->count = mx_uls_len_name(ls->hres);//тут выдает разные значения
	//mx_printint(ls->count);

	//mx_ls_print(ls->s, ls->count, ls->size_dir);
	mx_get_width(ls->s, ls->count, 0);

	//free(ls->s);
	//free(ls);
	//mx_printstr(argv[1]);
}
