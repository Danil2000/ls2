#include "uls.h"

//считаем количество ТОЛЬКО одних папок (не учитываем название проги и название файлов)
static int count_all_dir(char **argv) {
	int i = 0;
	int cout_dir = 0;

	while (argv[i]) {
		if (mx_is_dir(argv[i]))	{ //проверяем если папка, то записываем в переменную
			cout_dir++;
		}
		i++;
	}
	return cout_dir;
}

// берет аргумент из терминала (все, включая название проги и флаги) char** argv
// отсекает все, что не папки (название программы и флаги)
// и передает в массив s_dir только название папок
static char **check_dirs(char **s_dir, char** argv) {
	int i = 0;
	int j = 0;

	s_dir = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **)); //выделяем память под все переменные
	while (argv[i]) {
		if (mx_is_dir(argv[i])) {//проверяем если папка, то записываем в переменную
			s_dir[j] = argv[i];
			j++;
		}
		i++;
		//s_dir[j] = NULL;
	}
	s_dir[j] = NULL;
	mx_bubble_sort(s_dir, count_all_dir(s_dir));
	return s_dir; //возвращаем только массив папок
}

static void is_flags(char **argv, char *fname, DIR *dir) {
	if (argv[1][0] != '-')
		mx_ls_wf(dir, fname);

}

//печатаем название папки и ее содержимое
static void mx_print_few_dir(char **s_dir, char **argv) {
	int i = 0;
	//DIR *dir;
	//char *arr;
	
	while (s_dir[i] != NULL) {
		DIR *dir;
		mx_printstr(s_dir[i]);
		mx_printstr(":");
		mx_printchar('\n');
		dir = opendir(s_dir[i]);
		is_flags(argv, s_dir[i], dir);
		if (s_dir[i + 1] != NULL)
			mx_printchar('\n');
		i++;
	}
	//closedir(dir);
}


void mx_few_dirs(char** argv) {
	char **s = NULL;
	s = check_dirs(s, argv);

	mx_print_few_dir(s, argv);
}
