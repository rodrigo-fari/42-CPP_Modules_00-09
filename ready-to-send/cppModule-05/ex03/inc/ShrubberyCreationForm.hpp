/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:39:05 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/25 00:32:32 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;
	public:
		ShrubberyCreationForm(const std::string target = "ShrubberyCreationForm Default");
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		void executeAction() const;

	class UnableToOpenFileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};