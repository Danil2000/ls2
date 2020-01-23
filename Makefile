NAME = uls

INC = ./inc/mx_uls.h

HEADTMP = ./mx_uls.h

SRC = ./mx_uls.c \
	./mx_check.c \
	./mx_ls_wf.c\
	./mx_ls_A.c\
	./mx_lsa.c\
	./mx_ls_d.c\
	./mx_ls_wd.c\
	./mx_ls_F.c\
	./mx_dir_size.c\
	./mx_ls_R.c\
	./mx_count_for_print.c

SRCS = ./src/mx_uls.c \
	./src/mx_check.c \
	./src/mx_ls_wf.c\
	./src/mx_ls_A.c\
	./src/mx_lsa.c\
	./src/mx_ls_d.c\
	./src/mx_ls_wd.c\
	./src/mx_ls_F.c\
	./src/mx_dir_size.c\
	./src/mx_ls_R.c\
	./src/mx_count_for_print.c

OBJ = ./mx_uls.o \
	./mx_check.o \
	./mx_ls_wf.o \
	./mx_ls_A.o\
	./mx_lsa.o\
	./mx_ls_d.o\
	./mx_ls_wd.o\
	./mx_ls_F.o\
	./mx_dir_size.o\
	./mx_ls_R.o\
	./mx_count_for_print.o

OBJO = ./obj/mx_uls.o \
	./obj/mx_check.o \
	./obj/mx_ls_wf.o\
	./obj/mx_ls_A.o\
	./obj/mx_lsa.o\
	./obj/mx_ls_d.o\
	./obj/mx_ls_wd.o\
	./obj/mx_ls_F.o\
	./obj/mx_dir_size.o\
	./obj/mx_ls_R.o\
	./obj/mx_count_for_print.o


	
CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

all: install uninstall

install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj

clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)

reinstall: clean all