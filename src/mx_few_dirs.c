#include "uls.h"

//считаем количество ТОЛЬКО одних папок (без прог и файлов)
static int count_all_dir(char **argv) {
	int i = 0;
	int cout_dir = 0;

	while (argv[i])
	{
		if (mx_is_dir(argv[i]))
		{
			cout_dir++;
		}
		i++;
	}
	return cout_dir;
}

char **mx_check_files_1(char **s_file, char **argv) {
	int i = 0;
	int j = 0;

	s_file = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **));
	while (argv[i])
	{
		if (mx_is_dir(argv[i]) == 0)
		{ //проверяем если не папка, то файл
			s_file[j] = mx_strdup(argv[i]);
			j++;
		}
		i++;
	}
	s_file[j] = NULL;
	mx_bubble_sort(s_file, count_all_dir(s_file));
	return s_file; //массив файлов
}

char **mx_check_dirs(char **s_dir, char **argv) {
	int i = 0;
	int j = 0;

	s_dir = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **));
	while (argv[i])
	{
		if (mx_is_dir(argv[i]))
		{ //проверяем если папка
			s_dir[j] = mx_strdup(argv[i]);
			j++;
		}
		i++;
	}
	s_dir[j] = NULL;
	mx_bubble_sort(s_dir, count_all_dir(s_dir));
	return s_dir; //массив папок
}

char **mx_chk(char **argv, char **ss) {
	int i = 0;
	int j = 0;
	int size = 0;

	ss = malloc(sizeof(char *) * (mx_len_arr(argv) + 1));
	if (argv[1][0] == '-')
		i = 2;
	else
		i = 1;
	size = mx_len_arr(argv);
	while (argv[i])
	{
		mx_check_files(argv[i], argv);
		if (errno != 2)
		{
			ss[j] = mx_strdup(argv[i]);
			j++;
		}
		i++;
	}
	ss[j] = NULL;
	return ss;
}

void mx_few_dirs(char **argv) {
	char **f = NULL;
	char **ss = NULL;
	char **s = NULL;

	ss = mx_chk(argv, ss); //вывод ошибок и папок
	s = mx_check_dirs(s, ss);
	f = mx_check_files_1(f, ss);
	mx_bubble_sort(ss, mx_len_arr(ss));
	mx_print_few_dir(s, f, argv);
	mx_del_strarr(&f);
	mx_del_strarr(&ss);
	mx_del_strarr(&s);
}
