NAME := bsp
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

.PHONY: run re test clean

re: clean $(NAME)

clean:
	rm -f *.o $(NAME)
