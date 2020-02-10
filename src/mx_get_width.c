#include "uls.h"

int mx_size_win(char **s) {
	int size = 0;
	int res = 0;
	int count = 0;
	struct winsize w;

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
