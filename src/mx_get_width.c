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
	size = w.ws_col;
	count = mx_count_for_print(s); //длина максимального имени файла
	res = (size / mx_uls_len_name(count));
	if (!isf) {
		mx_bubble_sort(s, mx_len_arr(s));
	}
	mx_to_colls(res, s, spaces, c);
}
