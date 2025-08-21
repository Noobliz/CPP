CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

SRC =   src/main.cpp \
        src/ClapTrap.cpp \
		src/FragTrap.cpp \

OBJDIR = .obj/
OBJ = $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@


$(OBJDIR)%.o : %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all