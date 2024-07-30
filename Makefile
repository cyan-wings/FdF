##############################################
###LIBS									######
##############################################

LIBFTDIR		=	libft
LIBFTINC		=	-I$(LIBFTDIR)/includes/
LIBFTLD			=	-L$(LIBFTDIR) -lft
LIBFT			=	$(LIBFTDIR)/libft.a

UNAME			:=	$(shell uname)
ifeq ($(UNAME), Linux)
	MLXDIR		=	mlx_linux
	MLXLD		=	-lmlx -L$(MLXDIR) -lXext -lX11 -lm -lz
else
	MLXDIR		=	mlx
	MLXLD		=	-l$(MLXDIR) -framework OpenGL -framework AppKit
endif

MLXINC			=	-I$(MLXDIR)


##############################################
###HEADERS								######
##############################################

HDRDIR			=	includes/
HDRINC			=	-I$(HDRDIR)


##############################################
###SRCS									######
##############################################

SRCDIR			=	srcs/
SRC_M			=	\
					FdF/FdF							\
					FdF/FdF_draw_line				\
					mlx_utils/mlx_plot_pixel		\

SRCS			=	$(addsuffix .c, $(addprefix $(SRCDIR), $(SRC_M)))


##############################################
###OBJS									######
##############################################

OBJDIR			=	objs/
OBJS			=	$(subst $(SRCDIR), $(OBJDIR), $(subst .c,.o,$(SRCS)))
OBJDIRS			=	$(sort $(dir $(OBJS)))


##############################################
###FLAGS								######
##############################################

NAME			=	FdF
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror$(if $(FSANITIZE), $(FSANITIZE))
FSANITIZE		=	-fsanitize=address -g

IFLAGS			=	$(HDRINC) $(LIBFTINC) $(MLXINC)
LFLAGS			=	$(LIBFTLD) $(MLXLD)

RM				=	rm -rf
MAKE			=	make
MAKE_C			=	$(MAKE) -C

UP				=	\033[1A
FLUSH			=	\033[2K



##############################################
###RULES								######
##############################################

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LFLAGS)

$(LIBFT):
	$(MAKE_C) $(LIBFTDIR)

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(RM) .DS_Store
	$(MAKE_C) $(LIBFTDIR) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE_C) $(LIBFTDIR) $@

re: fclean all

.PHONY: all bonus clean fclean re
