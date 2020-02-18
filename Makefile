NAME = uls

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g -fsanitize=address
SRCD	=	src
INCD	=	inc
OBJD	=	obj
LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc
LMBX = libmx.a
INC = uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC =	mx_check_flags.c\
		mx_check.c\
		mx_colors.c\
		mx_count_for_print.c\
		mx_dir_size.c\
		mx_few_dirs.c\
		mx_get_mode.c\
		mx_get_width.c\
		mx_ls_a_one.c\
		mx_ls_A.c\
		mx_ls_d.c\
		mx_ls_f.c\
		mx_ls_flag_one.c\
		mx_ls_G.c\
		mx_ls_l.c\
		mx_ls_m.c\
		mx_ls_ma.c\
		mx_ls_one_A.c\
		mx_ls_p.c\
		mx_ls_print.c\
		mx_ls_R.c\
		mx_ls_wd.c\
		mx_ls_wf.c\
		mx_lsa.c\
		mx_print_spaces.c\
		mx_print_with_new_line.c\
		mx_to_colls.c\
		mx_uls.c\
		mx_l2.c\
		mx_ls_atty.c\
		mx_is_dir.c

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
	@rm -rf $(OBJD)
	
uninstall:
	@make -sC $(LMXD) $@

reinstall: uninstall clean install
