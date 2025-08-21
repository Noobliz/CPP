CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = ex00

SRC =   src/main.cpp \
        src/Animal.cpp \
		src/Cat.cpp \
		src/Dog.cpp \
		src/WrongAnimal.cpp \
		src/WrongCat.cpp

OBJDIR = .obj/
OBJ = $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@


$(OBJDIR)%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all