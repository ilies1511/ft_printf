###MAKEFILE###

NAME = libftprintf.a

HEADER = ft_printf.h

CFLAGS = cc -Wall -Wextra -Werror

.DEFAULT_GOAL := all # default rule to be executed

SRCS += ft_printf.c
SRCS += write_char.c
SRCS += write_str.c
SRCS += write_u.c
SRCS += write_ptr.c
SRCS += write_x_upper.c
SRCS += write_x_lower.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJS): %.o: %.c $(HEADER)
	$(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# CC: Compiler command (set to cc).
# CFLAGS: Compilation flags.
# SRCDIR: Source directory.
# INCDIR: Header directory.
# SRCS: List of source files.
# OBJS: List of object files.
# LIBNAME: Name of the library.
# all: Default target (equivalent to make libft.a).
# $(LIBNAME): Rule to create the library.
# %.o: %.c: Rule for compiling individual source files.
# clean: Rule to remove object files.
# fclean: Rule to remove library and object files.
# re: Rule to rebuild everything.
# .PHONY: Marks targets as not representing files. So if you have a file name called "clean" or "all" doesn't get confusing
# Variables defined with := in GNU make are expanded when they are defined rather than when they are used.
# $< points to the first prerequisite.
# $@ points to the target
# $^ : all the prerequipments-dependencies
# ar -rcs: ar creates-modifies a group of files combined into an archive,s is like ranlib(), -c means be silent not print info, -r gives the archive file position
# % is pattern matching character ex. %.c %.o means if I have file1.c I should have same name file1.o
# ranlib command converts each Archive library to a random library. A random library is an archive library that contains a symbol table.
# to run makefile use "make -f name_of_file" or just make if name is the default Makefile or makefile
# := instead of = to avoid infinite recursion if ex. You type CC = $(CC)
#SRCS := $(wildcard *.c): $(wildcard pattern) is one of the functions for filenames. In this case, all files with the .c extension will be stored in a variable SRCS.
#BINS := $(SRCS:%.c=%): This is called as substitution reference. In this case, if SRCS has values 'foo.c bar.c', BINS will have 'foo bar'.
