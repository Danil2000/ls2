#ifndef ULS_H
#define ULS_H

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
#include <time.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/ttycom.h>

 #define S_IFMT    0170000//__S_IFMT
 #define S_IFDIR	0040000//__S_IFDIR
 #define S_IFCHR	0020000//__S_IFCHR
 #define S_IFBLK	0060000//__S_IFBLK
 #define S_IFREG	0100000//__S_IFREG
 #define S_IFIFO	0010000//__S_IFIFO
 #define S_IFLNK 	0120000//__S_IFLNK
 #define S_IFSOCK   0140000//__S_IFSOCK

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

typedef enum 			e_lena {
	LENINO,
	LENLINKS,
	LENUSER,
	LENGROUP,
	LENSIZE,
	LENSIZE_OTHER,
	LENNAME
}						t_lena;

typedef struct 			s_lens {
	int					len_filename;
	int					len_links;
	int					len_user;
	int					len_group;
	int					len_size;
	int					len_ino;
	int					chosen;
	int					blocks;
}						t_lens;
typedef struct s_lst {
    void *data;
    struct s_lst *next;
}   t_lst;

void mx_check(int argc, char **argv);
void mx_check_dir(DIR *dir, char **argv);
void mx_ls_wf(DIR *dir, char *argv);
void mx_ls_A(DIR *dir, char **argv);
void mx_lsa(DIR *dir, char **argv);
void mx_ls_d(char **argv);
void mx_ls_wd();
int mx_dir_size(DIR *dir, int is_a);
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
void mx_ls_flag_one(DIR *dir);
void mx_ls_a_one(DIR *dir, char **argv);
void mx_ls_A_one(DIR *dir, char **argv);
char **mx_write_to_arr_a(DIR *dir,char **s);
void mx_ls_G(DIR *dir, int size_dir);
char *mx_make_whithout_backround(char *scolor, char* filename);
char *mx_make_backround(char *scolor, char *sbackground, char* filename);
char* make_color_string(int color, int background, char* filename);
void choose_color(char type, char* filename);
void mx_ls_f(DIR *dir, char **argv);
void mx_few_dirs(char **argv);
void mx_print_flag_one(char **s, int size);
char mx_type_of_file(mode_t mode);
void mx_ls_wf_few(DIR *dir, char **argv, int count);
void mx_ls_m(DIR* dir, char **argv);
void mx_ls_p(DIR *dir, char **argv);
mode_t mx_get_mode(struct stat fst);
void mx_ls_l(DIR *dir, char *dirname);
void mx_dir_type(mode_t mode, char *str);
mode_t* mx_f_m(mode_t *mode);
void mx_take_ogp(mode_t mode, mode_t *modes, char *str);
//char mx_tacl(char *dirname);
void mx_ls_ma(DIR* dir, char **argv);
void mx_print_m(char **s, int winsize);
int mx_size_win();
void mx_choose_flag(char *arg, char **args, DIR *dir, int argc);
void mx_ls_l2(char **argv, int argc);

#endif
