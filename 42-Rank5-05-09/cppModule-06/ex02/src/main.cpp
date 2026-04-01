/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:55:52 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/19 14:45:28 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main (void)
{
	Base *base;
	Base *nulPtr = 0;
	base = generate();

	std::cout << "== Identify Base With Pointer Paramater ==\n" << std::endl;
	identify(base);
	std::endl(std::cout);
	std::cout << "== Identify Base With Reference Paramater ==\n" << std::endl;
	identify(*base);
	std::endl(std::cout);
	std::cout << "== Identify Base With Null Pointer Paramater ==\n" << std::endl;
	identify(nulPtr);

	delete (base);
	delete (nulPtr);
}