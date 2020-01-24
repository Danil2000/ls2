NAME = uls

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g
SRCD	=	src
INCD	=	inc
OBJD	=	obj
LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc
LMBX = libmx.a
INC = uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC =	mx_uls.c\
		mx_check.c\
		mx_ls_wf.c\
		mx_ls_A.c\
		mx_lsa.c\
		mx_ls_d.c\
		mx_ls_wd.c\
		mx_ls_F.c\
		mx_dir_size.c\
		mx_ls_R.c\
		mx_count_for_print.c\
		mx_ls_print.c\
		mx_print_spaces.c\


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install uninstall
	
install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	
$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)

clean: uninstall
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	
uninstall:

	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	
reinstall: uninstall install