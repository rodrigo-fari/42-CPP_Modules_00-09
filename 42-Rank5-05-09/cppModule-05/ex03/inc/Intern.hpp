/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:06:14 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/26 21:10:03 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		AForm *Presidential(std::string target);
		AForm *Shrubbery(std::string target);
		AForm *Robotomy(std::string target);
	
	public:
		Intern(void);
		~Intern(void);
		AForm* (Intern::*funcArray[3])(std::string target);
		AForm* makeForm(std::string formName, std::string target);

	class NoFormException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
};
