/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:46:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 18:12:43 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

static void enter_to_continue()
{
	std::cout << "\n\nPress |ENTER| to continue" << std::endl;
	std::cin.get();
	system("clear");
}

static void TestEmptyArray()
{
	Array<int> array;
	
	try
	{
		std::cout << array[0] << std::endl;;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;;
	}
	enter_to_continue();
}

static void TestDefaultArray()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
		array[i] = rand() % 100;
	
	for(unsigned int i = 0; i < array.size(); i++)
		std::cout << "index[" << i << "]: " << array[i] << std::endl;;
	enter_to_continue();
}

static void TestCopyArray()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << "Original index[" << i << "]: " << array[i] << std::endl;;
	}
	
	Array<int> copy(array);
	
	for(unsigned int i = 0; i < copy.size(); i++)
		std::cout << "Copy index[" << i << "]: " << copy[i] << std::endl;;
	enter_to_continue();
}

static void TestAssignArray()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << "Original index[" << i << "]: " << array[i] << std::endl;;
	}
	
	Array<int> copy(3);
	
	copy = array;
	
	for(unsigned int i = 0; i < copy.size(); i++)
		std::cout << "Copy index[" << i << "]: " << copy[i] << std::endl;;
	enter_to_continue();
}

static void TestAccessingElements()
{
	Array<int> array(5);
	
	for(unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = rand() % 100;
		std::cout << "index[" << i << "]: " << array[i] << std::endl;;
	}
	try
	{
		std::cout << "Trying to access an element within the array limits" << std::endl;;
		std::cout << "Element at index 4: " << std::endl;;
		std::cout << array[4] << std::endl;;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;;
	}

	try
	{
		std::cout <<"Trying to access an element out of the array limits" << std::endl;;
		std::cout << "Element at index 5: " << std::endl;;
		std::cout << array[5] << std::endl;;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	enter_to_continue();
}

static void TestMemberFunction()
{
	Array<int> array(5);

	std::cout << "Array size: " << array.size() << std::endl;
	enter_to_continue();
}

int main()
{
	std::cout << "--- Test Empty Array ---" << std::endl;
	TestEmptyArray();
	std::cout << "--- Test Default Array ---" << std::endl;
	TestDefaultArray();
	std::cout << "--- Test Copy Array ---" << std::endl;
	TestCopyArray();
	std::cout << "--- Test Assign Array ---" << std::endl;
	TestAssignArray();
	std::cout << "--- Test Accessing Elements ---" << std::endl;
	TestAccessingElements();
	std::cout << "--- Test Member Function ---" << std::endl;
	TestMemberFunction();
	return (0);
}