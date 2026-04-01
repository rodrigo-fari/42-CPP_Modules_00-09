/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:39:00 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/25 00:29:29 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

	public:
		RobotomyRequestForm(const std::string target = "RobotomyRequestForm Default");
		RobotomyRequestForm(const RobotomyRequestForm &original);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm();

		void executeAction() const;
};

