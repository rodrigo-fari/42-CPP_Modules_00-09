# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arrox <arrox@student.42porto.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 12:03:00 by arrox             #+#    #+#              #
#    Updated: 2026/03/03 12:03:00 by arrox            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                     names                                    #
#==============================================================================#
name = btc

_success        = [$(grn)success$(d)]

#==============================================================================#
#                                    paths                                     #
#==============================================================================#
inc_path        = inc
src_path        = src
build_path      = .build

src             = main.cpp src/BitcoinExchange.cpp

objs            = $(src:%.cpp=$(build_path)/%.o)

#==============================================================================#
#                              compiler & flags                                #
#==============================================================================#
cxx         = c++ -g
cxxflags    = -Wall -Werror -Wextra -std=c++98
incs        = -I $(inc_path)

#==============================================================================#
#                                  rules                                       #
#==============================================================================#
all: $(name)

$(build_path):
	$(mkdir_p) $(build_path)

$(name): $(objs)
	@echo "[$(yel)compiling $(name)$(d)]"
	$(cxx) $(cxxflags) $(incs) $(objs) -o $(name)
	@echo "[$(_success) compiling $(mag)$(name)!$(d)]"

$(build_path)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo -n "$(mag)#$(d)"
	$(cxx) $(cxxflags) $(incs) -c $< -o $@

clean:
	@echo "* $(yel)removing $(mag)$(name)$(d) and deps $(yel)object files$(d)"
	rm -rf $(build_path)
	@echo "* $(yel)removing $(cya)$(build_path)$(d) folder & files$(d): $(_success)"

fclean: clean
	rm -f $(name)
	@echo "* $(yel)cleaning executable$(d): $(_success)"

re: fclean all

.phony: all clean fclean re

#==============================================================================#
#                                  utils                                       #
#==============================================================================#
mkdir_p = mkdir -p
b       = $(shell tput bold)
bla     = $(shell tput setaf 0)
red     = $(shell tput setaf 1)
grn     = $(shell tput setaf 2)
yel     = $(shell tput setaf 3)
blu     = $(shell tput setaf 4)
mag     = $(shell tput setaf 5)
cya     = $(shell tput setaf 6)
whi     = $(shell tput setaf 7)
d       = $(shell tput sgr0)
