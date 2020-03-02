#include "uls.h"

static int choose_size_of_rows(int len, int colls) {
	int size = 0;
	
	if ((len % colls) == 0)
		size = len / colls;
	else
		size = (len / colls) + 1;
	return size;
}

static void mx_to_clls_prnt(t_ls_colls *c, int colls, char **s, int spaces)
{
	for (int i = 0; i < c->r; i++) {
		int z = i;
		int j = 0;
		while (j < colls) {
			if (z >= c->len)
				break;
			c->res[i] = s[z];
			mx_printstr(c->res[i]);
			if (s[z + c->r])
				mx_printspaces(spaces, mx_strlen(s[z]));
			z += c->r;
			j++;
		}
		mx_printchar('\n');
	}
}

void mx_to_colls(int colls, char **s, int spaces, t_ls_colls *c) {
	c->len = mx_len_arr(s);
	c->res = (char**) malloc(c->len * sizeof(char**));
	c->r = choose_size_of_rows(c->len, colls);

	mx_to_clls_prnt(c, colls, s, spaces);
	free(c->res);
	free(c);
}
