/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:14:43 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/26 15:34:41 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void printTitle(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main(void)
{
	printTitle("Teste base (subject)");
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("Overflow de capacidade");
	try {
		Span sp(2);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("Span em container vazio");
	try {
		Span sp(3);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("Span com 1 elemento");
	try {
		Span sp(3);
		sp.addNumber(42);
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("Duplicados (shortest = 0)");
	try {
		Span sp(4);
		sp.addNumber(100);
		sp.addNumber(100);
		sp.addNumber(105);
		sp.addNumber(110);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}


