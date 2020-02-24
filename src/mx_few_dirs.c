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

static char **check_files(char **s_file, char **argv) {
	int i = 1;
	int j = 0;

	s_file = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **)); //выделяем память под все переменные
	while (argv[i]) {
		if (!mx_is_dir(argv[i])) { //проверяем если папка, то записываем в переменную
			s_file[j] = argv[i];
			j++;
		}
		i++;
	}
	s_file[j] = NULL;
	mx_bubble_sort(s_file, count_all_dir(s_file));
	return s_file; //возвращаем только массив файлов
}

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
	}
	s_dir[j] = NULL;
	mx_bubble_sort(s_dir, count_all_dir(s_dir));
	return s_dir; //возвращаем только массив папок
}

// static char **mx_wrong_files(char **s_file) {
// 	int i = 1;
// 	int j = 0;
// 	int count_fl = 0;
// 	char **wr_fls = NULL;

// 	while (s_file[i]) {
// 		if (mx_check_files(s_file[i]) == 0) {
// 			count_fl++;
// 		}
// 	}

// 	wr_fls = (char **)malloc((count_fl + 1) * sizeof(char **));
// 	while (s_file[i]) {
// 		if (mx_check_files(s_file[i]) == 0) {
// 			wr_fls[j] = s_file[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	wr_fls[j] = NULL;
// 	mx_bubble_sort(wr_fls, count_all_dir(wr_fls));
// 	return wr_fls; //возвращаем массив неверных файлов и папок
// }

//печатаем название папки и ее содержимое
static void mx_print_few_dir(char **s_dir, char **s_file, char **argv) {
	int i = 0;
	int hres = 0;
	int count = 0;
	DIR *dir1;
	
	//mx_print_err_few(s_file);
	if (!isatty(1)) {
		while(s_file[i]) {
			mx_check_files(s_file[i]);
			if (errno == 2)
			{
				i++;
			}
			else{
				mx_print_with_new_line(s_file[i]);
				i++;
			}
		}
	}
	else {
		while (s_file[i]) {
			mx_check_files(s_file[i]);
			i++;
		}
		hres = mx_count_for_print(s_file);
		count = mx_uls_len_name(hres);
		mx_get_width(s_file, count, 0);
		if (count < 15823877)
			mx_printchar('\n'); //выводит пустую строчку после файла
		//mx_wrong_files(s_file);
	}
	i = 0;
	while (s_dir[i] != NULL) {
		DIR *dir;
		//mx_printint(i);
		//mx_check_dir(dir, s_dir[i]);
		mx_printstr(s_dir[i]); // название папки
		mx_printstr(":");
		mx_printchar('\n');
		if (!(dir = opendir(s_dir[i]))) {
			mx_check_dir(dir, argv);
		};
		if (!isatty(1)) {
			dir1 = opendir(s_dir[i]);
			mx_ls_flag_one(dir1, argv, s_dir[i]);
			i++;
		}
		else {
			mx_ls_wf(dir, s_dir[i]);
			if (s_dir[i + 1] != NULL)
				mx_printchar('\n');
			i++;
		}
	}
}

void mx_few_dirs(char** argv) {
	char **s = NULL;
	char **f = NULL;
	s = check_dirs(s, argv);
	f = check_files(f, argv);
	mx_print_few_dir(s, f, argv);
}
