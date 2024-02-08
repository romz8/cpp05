# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:51:31 by rjobert           #+#    #+#              #
#    Updated: 2024/02/08 11:13:25 by romainjober      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = Forms_madness
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -I ./
HEADER = Bureaucrat.hpp AForm.hpp colors.h ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp  \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
RM = rm -rf
OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
