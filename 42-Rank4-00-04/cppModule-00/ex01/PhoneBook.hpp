/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:35:09 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 13:50:09 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <exception>
# include <cctype>
# include "Contact.hpp"

#define RESET			"\033[0m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define CLEAR_SCREEN	"\033c"
#define BOLD			"\033[1m"
#define DIM				"\033[2m"
#define ITALIC			"\033[3m"
#define UNDERLINE		"\033[4m"
#define BLINK			"\033[5m"

class PhoneBook {
	private:
	Contact _contacts[8];
	int		_count;
	int		_nextIndex;
	public:
	PhoneBook();
	void	addContact();
	void	searchContact();
};

void wait_seconds(int sec);

#endif