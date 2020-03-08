#include "uls.h"

void mx_choose_flag(char *arg, char **args, DIR *dir) {
	if (!mx_strcmp(arg, "-R"))
		mx_ls_R(args[2], args);
	if (!mx_strcmp(arg, "-a"))
		mx_lsa(dir, args[2], args);
	if (!mx_strcmp(arg, "-A"))
		mx_ls_A(dir, args);
	if (!mx_strcmp(arg, "-1"))
		mx_ls_flag_one(dir, args, args[2]);
	if (!mx_strcmp(arg, "-m"))
		mx_ls_m(dir, args);
	if (!mx_strcmp(arg, "-f"))
		mx_ls_f(dir, args);
	if (!mx_strcmp(arg, "-p"))
		mx_ls_p(dir, args);
	if (!mx_strcmp(arg, "-l"))
		mx_ls_l(dir, args);
}

void mx_choose_combination(char *arg, char **args, DIR *dir) {
	if (!mx_strcmp(arg, "-a1") || !mx_strcmp(arg, "-1a"))
		mx_ls_a_one(dir, args);
	if (!mx_strcmp(arg, "-A1") || !mx_strcmp(arg, "-1A"))
		mx_ls_A_one(dir, args);
	if (!mx_strcmp(arg, "-fa") || !mx_strcmp(arg, "-af"))
		mx_ls_f(dir, args);
	if (!mx_strcmp(arg, "-fA") || !mx_strcmp(arg, "-Af"))
		mx_ls_f(dir, args);
	if (!mx_strcmp(arg, "-aA") || !mx_strcmp(arg, "-Aa"))
		mx_lsa(dir, args[2], args);
	if (!mx_strcmp(arg, "-lm"))
		mx_ls_m(dir, args);
	if (!mx_strcmp(arg, "-ma"))
		mx_ls_ma(dir, args);
	if (!mx_strcmp(arg, "-Ra"))
		mx_ls_R(arg, args);
}
