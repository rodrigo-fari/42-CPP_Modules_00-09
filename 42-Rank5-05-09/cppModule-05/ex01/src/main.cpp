/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 23:18:36 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << YELLOW << "\n=== Testing Bureaucrat & Forms ===" << RESET << std::endl << std::endl;

		// Test 1: Valid bureaucrat
		std::cout << BLUE << "Test 1: Creating valid bureaucrat and form situation." << RESET << std::endl;
		Bureaucrat b1("Alice", 30);
		std::cout << std::endl << b1 << std::endl;
		Form f1("Form1", 30, 30);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << "\n";
	}
	{
		std::cout << std::endl;
		std::cout << BLUE << "Test 2: Creating invalid bureaucrat and form situation." << RESET << std::endl;
		Bureaucrat b1("Alice", 31);
		std::cout << std::endl << b1 << std::endl;
		Form f1("Form1", 30, 30);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
}