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
	int i = 0;
	DIR** dir;

	dir = (DIR**)malloc(sizeof(dir));
	//mx_printint(size);
	s = (char**)malloc((size+1)*sizeof(char**));
	for (i = 1 ; i <= size; i++) {
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
	s[mx_len_arr(s) - 1] = NULL;
	mx_bubble_sort(s, mx_len_arr(s));
	//mx_printint(mx_len_arr(s));
	//mx_printstr(s[1]);
	return s;
}

DIR **mx_few_dirs(char** argv) {
	int size = 0;
	DIR **ls;
	char **s = NULL;
	int i = 1;

	ls = (DIR**)malloc(sizeof(ls));
	size = size_of_args(argv);
	s = check_dirs(s, argv, size);
	while (s[i])
	{
		mx_printstr(s[i]);
		// ls[i] = opendir(s[i]);
		 i++;
	}
	// int j = 0;
	// while(ls[j]) {
	// 	mx_ls_wf(ls[j], argv);
	// 	mx_printstr("jf");
	// 	j++;
	// }
	
	return ls;
}

//*сделать функцию? которая будет открывать дир? читать его? сортировать? закрывать и печатать
// сделать функцию0, которая будет отсекать название проги и записывать в массив все другие аргументы
// сделать функцию, которая будет искать флаги и сортироватьих, а остальное будет передавать записывать в массив
// сделать функцию, которая будет из оставшегося массива папок и файлов определя]ть папки и записывать их в отдельный массив и файлы и их тоже записывать в отдельный массив
// ну и все
