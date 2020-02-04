#include "uls.h"

char *mx_make_whithout_backround(char *scolor, char* filename) {
	char *str;

	//str = mx_strnew(mx_strlen(filename) + 17);
	str = mx_strjoin("\x1b[", scolor);
	str = mx_strjoin(str, "m");
	str = mx_strjoin(str, filename);
	str = mx_strjoin(str, "\x1b[0m");
	return str;
}
char *mx_make_backround(char *scolor, char *sbackground, char* filename) {
	char *str;
	//str = mx_strnew(mx_strlen(filename) + 19);
	str = mx_strjoin("\x1b[", sbackground);
	str = mx_strjoin(str,",");
	str = mx_strjoin(str, scolor);
	str = mx_strjoin(str, "m");
	str = mx_strjoin(str, filename);
	str = mx_strjoin(str, "\x1b[0m");
	return str;
}

char* make_color_string(int color, int background, char* filename) {
	char *str = NULL;
	char* scolor;
	char *sbackground;
	
	scolor = mx_itoa(color);
	sbackground = mx_itoa(background);
	if (!background) {
		str = mx_make_whithout_backround(scolor, sbackground);
	}
	else {
		str = mx_make_backround(scolor, sbackground, filename);
	}
	return str;
}

void choose_color(char type, char* filename) {
	char *str = NULL;

	type == 'd' ? str = make_color_string(34, 0, filename), mx_print_with_new_line(str):
	type == 'l' ? str = make_color_string(35, 0, filename), mx_print_with_new_line(str):
	type == 's' ? str = make_color_string(32, 0, filename), mx_print_with_new_line(str):
	type == 'p' ? str = make_color_string(33, 0, filename), mx_print_with_new_line(str):
	type == 'b' ? str = make_color_string(34, 46, filename), mx_print_with_new_line(str):
	type == 'c' ? str = make_color_string(34, 43, filename), mx_print_with_new_line(str):
	mx_print_with_new_line(str);
}
