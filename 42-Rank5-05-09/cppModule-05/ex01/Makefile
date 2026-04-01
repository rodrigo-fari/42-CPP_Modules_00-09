#Flags & Variables
MAKEFLAGS += -s
NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I inc/ -g3 -fsanitize=address
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
SRC = $(shell find $(SRC_DIR) -name "*.cpp")
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

#Colors & Text Formmating
RED					= \033[0;31m
GREEN				= \033[0;32m
YELLOW				= \033[0;33m
BLUE				= \033[0;34m
WHITE				= \033[1;37m
RESET				= \033[0m
BOLD				= \033[1m
BLINK				= \033[5m


all: $(NAME)
	printf "$(BOLD)$(GREEN)[$(BLINK) ✓$(RESET)$(BOLD)$(GREEN) ] COMPILATION SUCCESSFUL!$(RESET)\n"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	printf "$(BLUE)[ + ] Creating object directory$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	printf "$(YELLOW)[ + ] Compiling $(notdir $<)$(RESET)\n"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	printf "$(BLUE)[ + ] Linking executable$(RESET)\n"
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	printf "$(RED)[ x ] Cleaning object files$(RESET)\n"
	rm -rf $(OBJ_DIR)

fclean: clean
	printf "$(RED)[ x ] Full clean - removing executable$(RESET)\n"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re