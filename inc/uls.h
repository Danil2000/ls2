#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include "libmx.h"
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

DIR *dir;

typedef struct s_ls {
    int size_dir;
    int hres;
    int count;
    char **s;
} t_ls;
typedef struct s_ls_colls {
  char **res;
	int len;
	int r;
} t_ls_colls;
void mx_check(int argc, char **argv);
void mx_check_dir(DIR *dir, char **argv);
void mx_ls_wf(DIR *dir, char** argv);
void mx_ls_A(DIR *dir, char **argv);
void mx_lsa(DIR *dir, char **argv);
void mx_ls_d(char **argv);
void mx_ls_wd();
int mx_dir_size(DIR *dir);
bool mx_is_dir(char *fname);
void mx_ls_R(char *fn);
int mx_count_for_print(char **s);
int mx_uls_len_name(int a);
void mx_ls_print(char **s, int count, int size);
void mx_printspaces(int count, int len);
void mx_to_colls(int colls, char **s, int spaces, t_ls_colls *c);
int mx_len_arr(char **s);
bool mx_check_flags(char argv);
void mx_get_width(char **s, int spaces, int sf);
char **mx_write_to_arr(DIR *dir, char **s);
int mx_len_arr(char **s);
char **mx_write_to_arr_A(DIR *dir,char **s);
void mx_ls_flag_one(DIR *dir, char **argv);
void mx_ls_a_one(DIR *dir, char **argv);
void mx_ls_A_one(DIR *dir);
char **mx_write_to_arr_a(DIR *dir,char **s);
void mx_ls_G(char *filename);
char *mx_make_whithout_backround(char *scolor, char* filename);
char *mx_make_backround(char *scolor, char *sbackground, char* filename);
char* make_color_string(int color, int background, char* filename);
void choose_color(char type, char* filename);
void mx_ls_f(DIR *dir, char **argv);
DIR **mx_few_dirs(char **argv);
