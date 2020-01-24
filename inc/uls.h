#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include "libmx.h"
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

DIR *dir;

void mx_check(int argc, char **argv);
void mx_check_dir(DIR *dir, char **argv);
void mx_ls_wf(DIR *dir, char** argv);
void mx_ls_A(DIR *dir);
void mx_lsa(DIR *dir);
void mx_ls_d(char **argv);
void mx_ls_wd();
void mx_ls_F(DIR* dir);
int mx_dir_size(DIR *dir);
bool mx_is_dir(char *fname);
void mx_ls_R(char *fn);
int mx_count_for_print(char **s);
int mx_uls_len_name(int a);
void mx_ls_print(char **s, int count, int size);
void mx_printspaces(int count, int len);
void mx_to_colls(int colls, char **s);
int mx_len_arr(char **s);
bool mx_check_flags(char argv);
