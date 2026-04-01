/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:08:41 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/19 14:47:37 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() { };

Base* generate(void)
{
	std::srand(std::time(0));
	
	int random = 1 + (rand() % 3);
	
	if (random == 1)
		return (new(A));
	else if (random == 2)
		return (new(B));
	else
		return (new(C));
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class type: C" << std::endl;
	else
		std::cout << "Class type: Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Class type: A" << std::endl;
		return ;
	}
	catch (const std::exception& e){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Class type: B" << std::endl;
		return ;
	}
	catch (const std::exception& e){}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Class type: C" << std::endl;
		return ;
	}
	catch(const std::exception& e){std::cout << "Class type: Unknown" << std::endl;}

}