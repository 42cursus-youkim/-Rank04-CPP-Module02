NAME := prog.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 \
						-I include/											 \
						-I util/

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:%.cpp=%.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: re clean run leak

re: clean $(NAME)

clean:
	rm -f $(OBJ) $(NAME)

run: $(NAME)
	./$(NAME)

leak:
	colour-valgrind ./$(NAME)