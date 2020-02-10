#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	int i = 0;

	while(arr[i])
		i ++;
	for (int j = 0; i > j; j++)
	{
		mx_printstr(arr[j]);			
		mx_printstr(delim);
	}

	mx_printchar('\n');
}
