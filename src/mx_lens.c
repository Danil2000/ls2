#include "uls.h"

void mx_print_spaces_l(int len) {
	char *spaces;

	if (len < 1)
		return;
	if (!(spaces = (char *)malloc(sizeof(char) * (len + 1))))
		return;
	mx_memset(spaces, ' ', len);
	spaces[len] = '\0';
	mx_printstr(spaces);
	free(spaces);
}

static void set_m(t_lens *lens, int l, long n, int i) {
	while (n >= 10) {
		n /= 10;
		l++;
	}
	if (i == LENINO)
		return (useful->len_ino - l);
	if (i == LENLINKS)
		return (useful->len_links - l);
	if (i == LENSIZE)
		return (useful->len_size - l);
}

int mx_len_l(t_lens *lens, char *str, long n, int i) {
	int l = 0;

	if ((l = 1) && str) {
		if (i == LENGROUP)
			return lens->len_group - mx_strlen(str);
		if (i == LENUSER)
			return lens->len_user - mx_strlen(str);
		if (i == LENNAME)
			return lens->len_filename - n;
	}
	if (i == LENSIZE_OTHER)
		return lens->len_size - CHRS_SIZE;

}
