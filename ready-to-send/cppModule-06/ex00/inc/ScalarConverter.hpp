/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:23:13 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/17 12:35:02 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cmath>

#define NON_PRINTABLE "Unable to print."
#define NON_CONVERTABLE "Unable to convert."
#define OVER_BOUNDAERIES "Number out of boundaries."

struct OutputData
{
	char	chr;
	int		nbr;
	float	flt;
	double	dbl;
};

class ScalarConverter 
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(std::string& inputString);
};

