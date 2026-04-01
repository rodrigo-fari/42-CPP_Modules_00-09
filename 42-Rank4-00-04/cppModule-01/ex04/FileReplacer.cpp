/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:06:17 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/01 19:11:50 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

void	setInfo(FileReplacer& instance, char **av) {
	instance.setFilename(av[1]);
	instance.setS1(av[2]);
	instance.setS2(av[3]);
}

bool	searchAndReplace(FileReplacer& instance) {
	std::ifstream	inFile(instance.getFileName().c_str());//if and ofstream constructor need a const char*
	if (!inFile.is_open()) {
		std::cerr << RED << "[ ✗ ] " << RESET << "Unable to open "
			<< instance.getFileName() << std::endl;
			return (ERRO);
	}
	std::string		outputFileName = instance.getFileName() + ".replace";
	std::ofstream	outFile(outputFileName.c_str());
	if (!inFile.is_open()) {
		std::cerr << RED << "[ ✗ ] " << RESET << "Unable to create "
			<< outputFileName << std::endl;
			return (ERRO);
	}
	std::string		line;
	while (std::getline(inFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(instance.getS1(), pos)) != std::string::npos) {
			line.erase(pos, instance.getS1().length());
			line.insert(pos, instance.getS2());
			pos += instance.getS2().length();
		}
		outFile << line << "\n";
	}
	inFile.close();
	outFile.close();
	return (SUCCESS);
}
