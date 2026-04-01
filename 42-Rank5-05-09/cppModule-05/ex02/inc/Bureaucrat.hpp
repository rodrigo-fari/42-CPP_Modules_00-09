/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:11 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/25 00:29:29 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <exception>
#include "Colors.hpp"
#include "AForm.hpp"

#define NA ""

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &original);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		// Getters
		const std::string getName() const;
		int getGrade() const;

		// Member functions
		void increaseGrade();
		void decreaseGrade();
		void signForm(AForm &form) const;
		void executeForm(const AForm &form) const;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// Operator overload

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif