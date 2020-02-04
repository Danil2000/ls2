#include "uls.h"
// считает правильно
static int size_of_args(char **argv) {
	int size = 0;

	if (argv[1][0] == '-') { //если есть флаг отнимает флаг и uls
		size = mx_len_arr(argv) - 2;
	}
	else {
		size = mx_len_arr(argv) - 1; //если нет флага отнимает только uls
	}
	//mx_printint(size);
	return size;
}

static char **check_dirs(char **s, char** argv, int size) {
	//int i = 0;
	DIR** dir;

	dir = (DIR**)malloc(sizeof(dir));
	//mx_printint(size);
	s = (char**)malloc((size+1)*sizeof(char**));
	for (int i = 1 ; i <= size; i++) {
		if (mx_is_dir(argv[i])) {//выводит название папки
			s[i] = argv[i];
			
			//mx_printstr(mx_strjoin((s[i]), ":"));
			//mx_printchar('\n');
			// dir[2] = opendir(s[2]);
			// mx_ls_wf(dir[2], argv);
		}
		else {
			mx_printstr(s[i]); //выводит название файла
			mx_printspaces(mx_strlen(s[i]), size);
		}
	}
	//s[mx_len_arr(s)] = NULL;
	//mx_bubble_sort(s, mx_len_arr(s));
	//mx_printint(mx_len_arr(s));
	//mx_printstr(s[1]);
	return s;
}

static void mx_print_few_dir(char **s) {
	int i = 1;
	

	//dir = (DIR *)malloc(sizeof(dir));
	//mx_printint(size);
	//mx_printstr(s[1]);
	//s = (char **)malloc((size + 1) * sizeof(char **));
	//dir = opendir(s[i]);
	//mx_ls_wf(dir, argv);
	while (s[i]) {
		//mx_printint(i);
		DIR *dir;
		//mx_printstr(s[i]);
		//mx_printstr(":");
		mx_printchar('\n');
		dir = opendir(s[i]);
		//closedir(dir);
		mx_ls_wf(dir, s);
		i++;
	}
}

DIR **mx_few_dirs(char** argv) {
	int size = 0;
	DIR **ls;
	char **s = NULL;
	//int i = 1;

	ls = (DIR**)malloc(sizeof(ls));
	size = size_of_args(argv);
	s = check_dirs(s, argv, size);
	mx_print_few_dir(s);
	// while (s[i]) {
	// 	mx_printstr(s[i]);
	// 	mx_printchar('\n');
	// 	//mx_ls_wf(ls[i], argv);
	// 	i++;
	// }
	// int j = 0;
	// while(ls[j]) {
	// 	mx_ls_wf(ls[j], argv);
	// 	mx_printstr("jf");
	// 	j++;
	// }
	return ls;
}
