#include "uls.h"

static void mx_ls_prnt_isatty_1(char **s_file, char **s_dir)
{
	int hres = 0;
	int count = 0;

	if (isatty(1))
	{
		hres = mx_count_for_print(s_file);
		count = mx_uls_len_name(hres);
		mx_get_width(s_file, count, 0);
		if (count < 15823877 && mx_len_arr(s_dir) != 0) 
			mx_printchar('\n');
	}
	else{
		mx_print_strarr(s_file, "\n");
		if (mx_len_arr(s_dir) != 0 && mx_len_arr(s_file) != 0)
		{
			mx_printchar('\n');
		}
	}
}

static void mx_ls_prnt_dirname(char **s_dir, int i)
{
	if (i > 0 && !isatty(1))
	{
		mx_printstr("\n");	
	}
	mx_printstr(s_dir[i]);
	mx_printstr(":");
	mx_printchar('\n');
}

static void mx_ls_prnt_ls_wf(DIR *dir, char **s_dir, int i)
{
	if (!mx_is_dir(s_dir[i]))
	{
		mx_printstr(s_dir[i]);
		return;
	}
	mx_ls_wf(dir, s_dir[i]);
	if (s_dir[i + 1] != NULL)
		mx_printchar('\n');
} 

void mx_print_few_dir(char **s_dir, char **s_file, char **argv) {
	int i = 0;
	DIR *dir;
	DIR *dir1;

	mx_bubble_sort(s_file, mx_len_arr(s_file));

	mx_ls_prnt_isatty_1(s_file, s_dir);
	while (s_dir[i] != NULL) {
		mx_ls_prnt_dirname(s_dir, i);
		dir = opendir(s_dir[i]);
		if (!isatty(1)) {
			dir1 = opendir(s_dir[i]);
			mx_ls_flag_one(dir1, argv, s_dir[i]);
		}
		// else if (argv[1][1] == 'l')
		// 	mx_ls_l(dir1, argv);
		else
			mx_ls_prnt_ls_wf(dir, s_dir, i);
		i++;
	}
}
