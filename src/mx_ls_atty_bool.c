#include "uls.h"

//вывод некоторых флагов
char **mx_ls_chs_sm_flg(DIR *dir, char **s, char **argv)
{
    if ((argv[1][1] == 'a') || (argv[1][1] == 'f'))
        mx_write_to_arr_a(dir, s);
    if (argv[1][1] == 'A')
        mx_write_to_arr_A(dir, s);
    if (argv[1][1] == 'p')
        mx_write_p(dir, s);
    return s;
}

bool mx_ls_is_flg_A(char **argv)
{
    if (argv[1][1] == 'A')
        return 1;
    else
        return 0;
}


bool mx_ls_is_flg_aAf(char **argv) {
	if ((argv[1][1] == 'a') || (argv[1][1] == 'f')
    || (argv[1][1] == 'A'))
		return 1;
	else
		return 0;
}
