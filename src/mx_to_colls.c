#include "uls.h"

// bool mx_is_need_colls(char **s, int colls) {
// 	int res = mx_len_arr(s);
// 	if (res > colls) {
// 		return 1;
// 	}
// 	return 0;
// }

// int mx_len_arr(char **s) {
// 	int i = 0;

// 	while (s[i]) {
// 		i++;
// 	}
// 	return i;
// }

//используем в ф-ии mx_get_width и потом загоняем все в ф-ю с флагами
void mx_to_colls(int colls, char **s, int spaces) {
	char **res = NULL;
	int len = 0;
	int r = 0;
	
	len = mx_len_arr(s);
	res = (char**) malloc(len * sizeof(char**));
	if ((len % colls) == 0) {
		r = len / colls;
	}
	else
		r = (len / colls) + 1;

	// mx_printstr("Строки r: ");
	// mx_printint(r);
	// mx_printchar('\n');

	// mx_printstr("К-во файлов len: ");
	// mx_printint(len);
	// mx_printchar('\n');

	// mx_printstr("К-во колонок colls: ");
	// mx_printint(colls);
	// mx_printchar('\n');

	for (int i = 0; i < r; i++) {
		int z = i;
		int j = 0;

		while (j < colls) {
			if (z >= len)
				break;
			res[i] = s[z];
			//mx_printint(z);
			mx_printstr(res[i]);
			mx_printspaces(spaces, mx_strlen(s[z]));
			z += r;
			j++;
			
		}
		mx_printchar('\n');
		
	}
	//res[len] = NULL;
	//return res;
}
