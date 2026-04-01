/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:21:35 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/01 18:55:46 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "Colors.hpp"

# define SUCCESS 0
# define ERRO 1

class FileReplacer {
private:
	std::string _fileName;
	std::string _s1;
	std::string _s2;

public:
	void setFilename(const std::string& fileName) { _fileName = fileName; }
	void setS1(const std::string& s1) { _s1 = s1; }
	void setS2(const std::string& s2) { _s2 = s2; }
	
	const std::string& getFileName() const { return _fileName; }
	const std::string& getS1() const { return _s1; }
	const std::string& getS2() const { return _s2; }
};

bool	validateArguments(int ac, char **av);
bool	validateArgumentsContent(const std::string& str);
void	setInfo(FileReplacer& instance, char **av);
bool	searchAndReplace(FileReplacer& instance);

#endif