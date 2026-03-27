/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:02:22 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/27 17:11:52 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

static void enter_to_continue()
{
	std::cout << "\n\nPress |ENTER| to continue" << std::endl;
	std::cin.get();
	system("clear");
}

static void PrintListElements(std::list<int> &lst)
{
	std::list<int>::reverse_iterator it = lst.rbegin();
	std::list<int>::reverse_iterator ite = lst.rend();
	
	std::cout << Orange << "Iterating through List" << Reset << std::endl;

 	for(; it != ite; ++it)
	{
		std::cout << Orange << "Element: " << Reset << *it << std::endl;
	}
}

static void PrintStackElements(MutantStack<int> &mstack)
{
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	
	std::cout << Orange << "Iterating through Stack" << Reset << std::endl;

 	for(; it != ite; ++it)
	{
		std::cout << Orange << "Element: " << Reset << *it << std::endl;
	}
}

static void SubjectTest()
{
	try
	{
		MutantStack<int> mstack;
		std::cout << Cyan << "Pushing 5, 17 to Stack" << Reset << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << Orange << "Top of Stack: " << Reset << std::endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << Orange << "Stack size: " << Reset << std::endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << Orange << "Iterating through Stack" << Reset << std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

static void SubjectTestRemixed()
{
	try
	{
		MutantStack<int> mstack;
		
		std::cout << Cyan << "Pushing 5, 17 to Stack" << Reset << std::endl;
		mstack.push(5);
		mstack.push(17);

		std::cout << std::endl;
		PrintStackElements(mstack);
		std::cout << std::endl;
		
		std::cout << Orange << "Top of Stack: " << Reset << mstack.top() << std::endl << std::endl;
		
		std::cout << Cyan << "Poping from Stack" << Reset << std::endl;
		mstack.pop();
		std::cout << std::endl;
		PrintStackElements(mstack);
		std::cout << std::endl;
		
		std::cout << Orange << "Stack size: " << Reset << mstack.size() << std::endl << std::endl;
		
		std::cout << Cyan << "Pushing 3, 5, 737, 0 to Stack" << Reset << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		std::cout << std::endl;
		PrintStackElements(mstack);
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

static void TestWithList()
{
	try
	{
		std::cout << Purple << "--- Test With List ---" << std::endl << Reset;
		std::list<int> lst;
		
		std::cout << Cyan << "Pushing 5, 17 to List" << Reset << std::endl;
		lst.push_back(5);
		lst.push_back(17);
	
		std::cout << std::endl;
		PrintListElements(lst);
		std::cout << std::endl;
		
		std::cout << Orange << "Top of List: " << Reset << lst.back() << std::endl << std::endl;
		
		std::cout << Cyan << "Poping from List" << Reset << std::endl;
		lst.pop_back();
		
		std::cout << std::endl;
		PrintListElements(lst);
		std::cout << std::endl;
		
		std::cout << Orange << "List size: " << Reset << lst.size() << std::endl << std::endl;


		std::cout << Cyan << "Pushing 3, 5, 737, 0 to List" << Reset << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::cout << std::endl;
		PrintListElements(lst);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Red << e.what() << Reset << '\n';
	}
	enter_to_continue();
}

int main()
{
	SubjectTest();
	SubjectTestRemixed();
	TestWithList();
	return (0);
}
