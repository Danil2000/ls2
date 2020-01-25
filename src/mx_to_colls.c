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

void mx_to_colls(int colls, char **s) {
	char **res = NULL;
	int i;
	int j = 0;
	int len = 0;
	int r = 0;
	int z;
	//int count = 0;

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

	for (i = 0; i < r; i++) {
		z = i;

		while (s[z] != NULL)
		{
			//int z = 0;
			res[i] = s[z];
			z += r;
			j++;
			//mx_printint(i);
			mx_printstr(res[i]);
			mx_printstr("		");
			//mx_printint(z);
		}
		// for (j = i; j <= colls; j += r) {
		// 	res[i] = s[j];
		// 	count ++;
		// 	//mx_printint(j);
		// 	//mx_printstr(res[i]);
		// 	mx_printint(count);
		// 	//mx_printchar('\n');
		// 	// if (count > len)
		// 	// 	break;
		// }
		//mx_printstr(res[i]);
		//mx_printchar('\n');
		//mx_printint(j);
		mx_printchar('\n');
		
	}
	//res[z] = NULL;
	// //mx_printchar('\n');
	// mx_printstr(res[3]);
	//mx_printint(i);
	//return res;
}
