#include "uls.h"

//считаем количество ТОЛЬКО одних папок (без прог и файлов)
static int count_all_dir(char **argv) {
	int i = 0;
	int cout_dir = 0;

	while (argv[i]) {
		if (mx_is_dir(argv[i]))	{ //проверяем если папка
			cout_dir++;
		}
		i++;
	}
	return cout_dir;
}

char **check_files(char **s_file, char **argv) {
	int i = 0;
	int j = 0;

	s_file = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **));
	while (argv[i]) {
		if (mx_is_dir(argv[i]) == 0) { //проверяем если не папка, то файл
			s_file[j] = argv[i];
			j++;
		}
		i++;
	}
	s_file[j] = NULL;
	mx_bubble_sort(s_file, count_all_dir(s_file));
	return s_file; //массив файлов
}

static char **check_dirs(char **s_dir, char** argv) {
	int i = 0;
	int j = 0;

	s_dir = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **));
	while (argv[i]) {
		if (mx_is_dir(argv[i])) {//проверяем если папка
			s_dir[j] = argv[i];
			j++;
		}
		i++;
	}
	s_dir[j] = NULL;
	mx_bubble_sort(s_dir, count_all_dir(s_dir));
	return s_dir; //массив папок
}

static char** chk(char **argv, char **ss) {
	int i =1;
	int j = 0;
	int size  = 0;

	size = mx_len_arr(argv);
	ss = malloc(sizeof(char *) * (mx_len_arr(argv) + 1));
	while (argv[i]) {
		mx_check_files(argv[i]);
		if (errno != 2) {
			ss[j]= argv[i];
			j++;
		}
		i++;
	}
	ss[j] = NULL;
	return ss;
}

void mx_few_dirs(char** argv) {
	char **f = NULL;
	char **ss = NULL;
	char **s = NULL;

	ss = chk(argv, ss);//вывод ошибок и папок
	s = check_dirs(s, ss);
	f = check_files(f, ss);
	mx_bubble_sort(ss, mx_len_arr(ss));
	mx_print_few_dir(s, f, argv);
}
