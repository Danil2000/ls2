#include "uls.h"

//вывод колонок
void mx_get_width(char **s, int spaces, int isf) {
	struct winsize w;
	t_ls_colls *c = NULL;
	int res = 0;
	int count = 0;

	c = malloc(sizeof(t_ls_colls));
	int size = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	size = w.ws_col;  //не работает в дебаггере
	count = mx_count_for_print(s); //вроде как к-во символов с пробелами в каждом столбце
	res = (size / mx_uls_len_name(count));
	if (!isf) {
		mx_bubble_sort(s, mx_len_arr(s)); //сортируем название файлов в папке
	}
	// !!!!!!!!!!
	//res = 2; //!!!!! удалить это после дебаггинга!!!!!
	//mx_printint(res);
	//mx_printstr("\n");
	mx_to_colls(res, s, spaces, c);
}
