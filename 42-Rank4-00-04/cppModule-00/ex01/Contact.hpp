/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:34:59 by rde-fari          #+#    #+#             */
/*   Updated: 2025/06/23 00:06:51 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
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

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		void	setInfo();
		void	displayShort(int index) const;
		void	displayFull() const;
		bool	isEmpty() const;
};

void wait_seconds(int sec);

#endif