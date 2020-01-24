#include "uls.h"


void mx_get_width(char **s) {
	struct winsize w;
	int res = 0;
	int count = 0;
	//bool is_need_colls;

	int size = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	size = w.ws_col;
	count = mx_count_for_print(s);
	// if ((size % mx_uls_len_name(count)) >= 5)
	// 	res = (size / mx_uls_len_name(count)) - 1;
	// else
	res = (size / mx_uls_len_name(count));
	//is_need_colls = mx_is_need_colls(s, res);
	mx_to_colls(res, s);

	//return res;
}
