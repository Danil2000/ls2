#include "uls.h"

//считаем количество ТОЛЬКО одних папок (не учитываем название проги и название файлов)
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

static char **check_files(char **s_file, char **argv) {
	int i = 1;
	int j = 0;

	s_file = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **)); //выделяем память под все переменные
	while (argv[i]) {
		if (!mx_is_dir(argv[i])) { //проверяем если папка
			s_file[j] = argv[i];
			j++;
		}
		i++;
	}
	s_file[j] = NULL;
	mx_bubble_sort(s_file, count_all_dir(s_file));
	return s_file; //возвращаем только массив файлов
}

// static char **check_dirs(char **s_dir, char** argv) {
// 	int i = 0;
// 	int j = 0;

// 	s_dir = (char **)malloc((count_all_dir(argv) + 1) * sizeof(char **)); //выделяем память под все переменные
// 	while (argv[i]) {
// 		if (mx_is_dir(argv[i])) {//проверяем если папка
// 			s_dir[j] = argv[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	s_dir[j] = NULL;
// 	mx_bubble_sort(s_dir, count_all_dir(s_dir));
// 	return s_dir; //возвращаем только массив папок
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
				//mx_print_with_new_line(s_file[i]);
				i++;
			}
		}
	}
	else {
		while (s_file[i]) {
			mx_check_files(s_file[i]);
			i++;
		}
		// if (errno == 2) {

		// }
		hres = mx_count_for_print(s_file);
		count = mx_uls_len_name(hres);
		mx_get_width(s_file, count, 0);
		if (count < 15823877)
			mx_printchar('\n'); //выводит пустую строчку после файла
	}
	i = 0;
	while (s_dir[i] != NULL) {
		DIR *dir;
		//mx_printint(hres);
		//mx_printstr(s_file[0]);
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
static char** chk(char **argv, char **ss) {
	int i =1;
	int j = 0;
	int size  = 0;

	size = mx_len_arr(argv);
	ss = malloc(sizeof(char *) * (mx_len_arr(argv) + 1));
	while(argv[i])
	{
		mx_check_files(argv[i]);
		if (errno != 2)
		{
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

	ss = chk(argv, ss);
	// mx_print_strarr(ss, "\n");
	//s = check_dirs(s, argv);
	f = check_files(f, argv);
	mx_bubble_sort(ss, mx_len_arr(ss));
	mx_bubble_sort(f, mx_len_arr(f));
	mx_print_few_dir(ss, f, argv);
}
