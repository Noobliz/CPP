# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lisux <lisux@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:04:58 by lguiet            #+#    #+#              #
#    Updated: 2025/05/22 10:51:00 by lisux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    := violence
SRCS    := main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS    := $(SRCS:.cpp=.o)
CXX     := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re