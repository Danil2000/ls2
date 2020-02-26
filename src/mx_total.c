#include "uls.h"

int mx_total(char **s, int count) {
	struct stat file;
	int i = 0;
	int sum = 0;

	while(i < count)
	{	
		lstat(s[i], &file);
		sum += file.st_blocks;
		i++;
	}
	return sum;
}

