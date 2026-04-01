/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:39:02 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/25 00:29:29 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;

	public:
		PresidentialPardonForm(const std::string target = "PresidentialPardonForm Default");
		PresidentialPardonForm(const PresidentialPardonForm &original);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		void executeAction() const;
};

