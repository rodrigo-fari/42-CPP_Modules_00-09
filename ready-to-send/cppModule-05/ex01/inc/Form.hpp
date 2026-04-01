/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:31:52 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 22:17:10 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;

public:
	// Orthodox Canonical Form
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form& original);
	Form &operator=(const Form &rhs);
	~Form();

	// Getters
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	// Member function
	void beSigned(const Bureaucrat& bcrat);

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

	class FormAlreadySignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

// Operator overload
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif