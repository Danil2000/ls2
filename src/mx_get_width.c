#include "uls.h"

int mx_size_win() {
	int size = 0;
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	size = w.ws_col;
	return size;
}

//вывод колонок
void mx_get_width(char **s, int spaces, int isf) {
	t_ls_colls *c = NULL;
	int size = 0;
	int count  = 0;

	c = malloc(sizeof(t_ls_colls));
	size = mx_size_win();
	if (!isf) {
		mx_bubble_sort(s, mx_len_arr(s)); //сортируем название файлов в папке
	}
	count = mx_count_for_print(s);
	size = (size / mx_uls_len_name(count));

	mx_to_colls(size, s, spaces, c);
}
