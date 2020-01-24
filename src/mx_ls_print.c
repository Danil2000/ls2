#include "uls.h"

void mx_ls_print(char **s, int count, int size) {
	int i = 0;
	mx_bubble_sort(s, size);
	while (s[i]) {
		mx_printstr(s[i]);
		mx_printspaces(count, mx_strlen(s[i]));
		i++;
	}
	mx_printchar('\n');
}
