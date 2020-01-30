#include "uls.h"

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
}
