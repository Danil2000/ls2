#include "uls.h"

static void ls_l_dop(char **yy, int c){
    struct stat u;
    struct passwd *t = NULL;
    //struct group *i = NULL;
    char *times = NULL;
    mode_t var;
    int b = 0;
    ssize_t xat = 0;
    acl_t acl;

    for(b = 0; b < c; b++){
   //if(mx_strncmp(e->d_name ,".", 1) != 0) {
      //int res1 = 0;
     stat(yy[b], &u);
     //if(res1 < 0) res1 = lstat(yy[b], &u);;
    //int type;
    switch(u.st_mode & S_IFMT){ 
    case S_IFREG:
       mx_printstr("-");
      break;
    case S_IFDIR:
      mx_printstr("d");
      break;
    case S_IFCHR:
      mx_printstr("c");
      break;
    case S_IFBLK:
      mx_printstr("b");
      break;
    case S_IFLNK:
      mx_printstr("l");
      break;
    case S_IFIFO:
      mx_printstr("p");
      break;
    case S_IFSOCK:
      mx_printstr("s");
      break;
  }
  //mode_t var;
  var = (u.st_mode & ~S_IFMT);
  //(var & S_IRWXU) ? mx_printstr("s") : mx_printstr("-");
  (var & S_IRUSR) ? mx_printstr("r") : mx_printstr("-");
  (var & S_IWUSR) ? mx_printstr("w") : mx_printstr("-");
  (var & S_IXUSR) ? mx_printstr("x") : mx_printstr("-");
  //(var & S_IRWXG) ? mx_printstr("s") : mx_printstr("-");
  (var & S_IRGRP) ? mx_printstr("r") : mx_printstr("-");
  (var & S_IWGRP) ? mx_printstr("w") : mx_printstr("-");
  (var & S_IXGRP) ? mx_printstr("x") : mx_printstr("-");
  //(var & S_IRWXO) ? mx_printstr("s") : mx_printstr("-");
  (var & S_IROTH) ? mx_printstr("r") : mx_printstr("-");
  (var & S_IWOTH) ? mx_printstr("w") : mx_printstr("-");
  (var & S_IXOTH) ? mx_printstr("x") : mx_printstr("-");
  acl = acl_get_file(yy[b], 0x0000010);
  xat = listxattr(yy[b], NULL, 0, 0x0001);
  if(xat > 0)
    mx_printstr("@");
  else if(acl != NULL && ((u.st_mode & 0170000) != 0120000))
    mx_printstr("+");
  else 
    mx_printstr(" ");
      
       mx_printint(u.st_nlink); //исправить
       t = getpwuid(u.st_uid);
       mx_printstr(t->pw_name);
       //i = getgrgid(u.st_gid);
      // printf("%s ", i->gr_name);
 
       mx_printint(u.st_size);
       //times = ctime(&u.st_birthtime);
       times = ctime(&u.st_ctime);
        char *times_t = mx_memchr(times, ' ',mx_strlen(times));
        times_t = &times_t[1];
        char *times_t2 = mx_memrchr(times_t,':',mx_strlen(times_t));
        times_t2[0]='\0';
       //times = ctime(&rawtime);
       mx_printstr(times_t);// time of changing not time of creating
       //free(times);
       mx_printstr(yy[b]);
       //closedir(r);
     }
 }
 static void ls_l_make_yy(DIR *r){
  struct dirent *e = NULL;
  int c = 0;
  char **yy = NULL; 
  t_list *temp = NULL;
  t_list *consis = NULL;
  int a = -1;
  int b = 0;

    e = readdir(r);
    while (e != NULL) {
      mx_push_back(&consis, (void*)e);
      e = readdir(r);
    }
    c = mx_list_size(consis);
    yy = (char**)malloc (sizeof(char**) * c);
    temp = consis;
    for(b = 0; b < c; b++){
      if((((struct dirent *)(consis->data))->d_name)[0] != '.'){
        a++;
        yy[a] = mx_strnew(mx_strlen(((struct dirent *)(consis->data))->d_name));
        yy[a] = mx_strcat(yy[a], ((struct dirent *)(consis->data))->d_name);
      }
      consis = consis -> next;
    }   
    c = a + 1 ;
    mx_bubble_sort(yy, c);
    ls_l_dop(yy, c);
}

void mx_ls_l2(char **argv, int argc) {
    DIR *r = NULL;
    char **yy = NULL;
    int t = 0;
    int fd = 0;

    yy = (char **)malloc(sizeof(char*) *(argc + 1));

    if(argv == NULL) {
      r = opendir(".");
      ls_l_make_yy(r);
    }  
    else {
      for(t = 2; t < argc; t++){
        if((fd = open(argv[t], O_RDONLY)) >= 0)
          yy[0] = argv[t];
          yy[1] = NULL;
          ls_l_dop(yy, 2);
        }
      for(t = 2; t < argc; t++){
        r = opendir(argv[t]);
        ls_l_make_yy(r);
      }
    }
}
