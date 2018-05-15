NAME = ft_retro

INC = -I./includes

FLAGS = clang++ 
#-Wall -Werror -Wextra

LIB = -lncurses

SRC = Bullet.cpp retro.cpp MenuInterface.cpp Enemy.cpp GameClass.cpp Player.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o:%.cpp
	$(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
