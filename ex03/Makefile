NAME := bsp
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

.PHONY: run re test clean

re: clean $(NAME)

clean:
	rm -f *.o $(NAME)
