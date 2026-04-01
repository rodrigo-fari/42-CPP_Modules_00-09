/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:54:42 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 15:27:24 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string		str = "HI THIS IS BRAIN";
	std::string&	strREF = str;
	std::string*	strPTR = &str;

	
	std::cout << "┏━━━┫ MEMORY ADDRESS ┣━━━━━━━━┓" << std::endl;
	std::cout << "┃    var  = " << &str << "    ┃" << std::endl;
	std::cout << "┃  varPTR = " << strPTR << "    ┃" << std::endl;
	std::cout << "┃  varREF = " << &strREF << "    ┃" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
	
	std::cout << std::endl;

	std::cout << "┏━━━┫ VALUES ┣━━━━━━━━━━━━━━━━┓" << std::endl;
	std::cout << "┃    var  = " << str << "  ┃" << std::endl;
	std::cout << "┃  varPTR = " << *strPTR << "  ┃" << std::endl;
	std::cout << "┃  varREF = " << strREF << "  ┃" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
}
