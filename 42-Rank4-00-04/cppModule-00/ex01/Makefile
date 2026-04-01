MAKEFLAGS += -s
NAME     = phonebook
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC      = Contact.cpp PhoneBook.cpp main.cpp
OBJ      = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
