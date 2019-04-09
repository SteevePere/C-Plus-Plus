## ETNA PROJECT, 08/04/2019 by pere_s and rachad_a
## ZAPPY
## File description:
## 		Makefile


SRC = client.cpp params.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = Client

CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14

RM = rm -f

all: $(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
