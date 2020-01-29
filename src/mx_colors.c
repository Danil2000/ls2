#include "uls.h"

char *mx_make_whithout_backround(char *scolor, char* filename) {
	char *str;

	str = mx_strjoin("\x1b[", scolor);
	str = mx_strjoin(str, "m");
	str = mx_strjoin(str, filename);
	str = mx_strjoin(str, "\x1b[0m");
	return str;
}
char *mx_make_backround(char *scolor, char *sbackground, char* filename) {
	char *str;

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
		mx_make_whithout_backround(scolor, sbackground);
	}
	else {
		mx_make_backround(scolor, sbackground, filename);
	}
	return str;
}

void choose_color(char type, char* filename) {
	char *str;
	if(type == 'd') {
		str = make_color_string(35, 0, filename);
		mx_print_with_new_line(str);
	}
	else if (type == 'l') {
		str = make_color_string(34, 0, filename);
		mx_print_with_new_line(str);
	}
	else if (type == 's') {
		str = make_color_string(32, 0, filename);
		mx_print_with_new_line(str);
	}
	else if (type == 'p') {
		str = make_color_string(31, 0, filename);
		mx_print_with_new_line(str);
	}
	else if (type == 'b') {
		str = make_color_string(36, 41, filename);
		mx_print_with_new_line(str);
	}
	else {
		mx_print_with_new_line(filename);
	} 
}
