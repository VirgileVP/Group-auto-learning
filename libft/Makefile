# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vveyrat- <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 10:38:57 by vveyrat-     #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 01:33:30 by vveyrat-    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME= libft.a

COMP= gcc -Wall -Werror -Wextra -I.


CONVERT= convert/
INT= int/
IS= is/
LST= lst/
MEM= mem/
OTHER= other/
PUT= put/
STR= str/

CONVERTSRCS=ft_itoa.c \
			ft_atoi.c \
			ft_alltoa.c \
			ft_itoa_base.c \
			ft_ultoa_base.c \
			ft_to_ascii.c \


INTSRCS=	ft_intlenght.c \
			ft_intmax.c \
			ft_intmin.c \
			ft_intmoy.c \

ISSRCS=		ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_incharset.c


LSTSRCS=	ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \


MEMSRCS=	ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \

OTHERSRCS=	ft_bzero.c \
			ft_count_words.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c

PUTSRCS=	ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnchar.c \
			ft_putnbr_fd.c \
			ft_putnstr.c \
			ft_putstr.c \
			ft_putstr_fd.c \

STRSRCS=	ft_strcat.c \
			ft_strcapitalize.c \
			ft_strchr.c \
			ft_strpbrk.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strout.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_fstrjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c\
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_strmove.c \


SRCS= 	$(addprefix $(CONVERT),$(CONVERTSRCS)) \
		$(addprefix $(INT),$(INTSRCS)) \
		$(addprefix $(IS),$(ISSRCS)) \
		$(addprefix $(LST),$(LSTSRCS)) \
		$(addprefix $(MEM),$(MEMSRCS)) \
		$(addprefix $(OTHER),$(OTHERSRCS)) \
		$(addprefix $(PUT),$(PUTSRCS)) \
		$(addprefix $(STR),$(STRSRCS))


OBJ= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(COMP) -o $@ -c $<

$(NAME): $(OBJ)
	@printf "Creation de la libft\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n"

clean:
	@printf "Suppression des .o\n"
	@rm -f */*.o
	@printf "\n"

fclean: clean
	@printf "Suppression de la libft.a\n"
	@rm -f $(NAME)
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re
.SILENT: all $(NAME)$(OBJ)
