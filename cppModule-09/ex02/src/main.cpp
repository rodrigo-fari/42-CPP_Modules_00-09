/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:37:37 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/22 14:47:13 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> stringToIntVector(const std::string &str)
{
    std::vector<int> result;
    std::stringstream ss(str);
    std::string word;

    while (ss >> word)
    {
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] == '+' || word[i] == '-')
                throw PmergeMe::SignalsFoundException();
            if (!std::isdigit(word[i]))
                throw PmergeMe::NonNumericExpressionFoundException();
        }
        std::stringstream convert(word);
        int numero;
        convert >> numero;
        result.push_back(numero);
    }
    return result;
}

int main(int ac, char **av)
{
	if (ac != 2 || !av)
		return ((std::cerr << "Error: Invalid program usage.\n Try: ./PmergeMe \"agr1 arg2 ...\"" << std::endl), 1);

	try {
		std::vector<int> argsVect = stringToIntVector(av[1]);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	std::cout << "==| Success! |==" << std::endl;
	system("make fclean"); //! APENAS PRA DEBUG; NAO ESQUECER DE REMOVER POSTERIORMENTE!
	return (0);
}
