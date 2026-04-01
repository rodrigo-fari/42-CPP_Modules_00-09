/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:45:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/01 16:22:02 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ConvertState.hpp"

static bool isNan(double value)
{
    return (value != value);
}

static bool isInf(double value)
{
    return (value == std::numeric_limits<double>::infinity()
        || value == -std::numeric_limits<double>::infinity());
}

static bool isWholeNumber(double value)
{
    if (isNan(value) || isInf(value))
        return (false);
    return (std::floor(value) == value);
}

static bool isPseudoLiteral(const std::string& inputData)
{
    return (inputData == "nan" || inputData == "nanf"
        || inputData == "+inf" || inputData == "-inf"
        || inputData == "inf" || inputData == "+inff"
        || inputData == "-inff" || inputData == "inff");
}

static bool parseToDouble(const std::string& inputData, double& value)
{
    if (inputData.length() == 1
        && !std::isdigit(static_cast<unsigned char>(inputData[0])))
    {
        value = static_cast<double>(inputData[0]);
        return (true);
    }
    if (inputData.length() == 3
        && inputData[0] == '\'' && inputData[2] == '\'')
    {
        value = static_cast<double>(inputData[1]);
        return (true);
    }
    if (isPseudoLiteral(inputData))
    {
        std::string normalized = inputData;
        if (!normalized.empty() && normalized[normalized.length() - 1] == 'f')
            normalized = normalized.substr(0, normalized.length() - 1);
        value = std::strtod(normalized.c_str(), NULL);
        return (true);
    }
    char* endPtr = NULL;
    value = std::strtod(inputData.c_str(), &endPtr);
    if (endPtr == inputData.c_str())
        return (false);
    if (*endPtr == '\0')
        return (true);
    if (*endPtr == 'f' && *(endPtr + 1) == '\0')
        return (true);
    return (false);
}

static void parseChar(double inputData, OutputData* outpData, ConvertState* state)
{
    if (!state->valid || isNan(inputData) || isInf(inputData)
        || inputData < 0.0 || inputData > 127.0)
    {
        state->charImpossible = true;
        return ;
    }
    outpData->chr = static_cast<char>(inputData);
    if (!std::isprint(static_cast<unsigned char>(outpData->chr)))
        state->charNonDisplayable = true;
}

static void parseInt(double inputData, OutputData* outpData, ConvertState* state)
{
    if (!state->valid || isNan(inputData) || isInf(inputData)
        || inputData < static_cast<double>(INT_MIN)
        || inputData > static_cast<double>(INT_MAX))
    {
        state->intImpossible = true;
        return ;
    }
    outpData->nbr = static_cast<int>(inputData);
}

static void parseFloat(double inputData, OutputData* outpData, ConvertState* state)
{
    if (!state->valid)
    {
        outpData->flt = std::numeric_limits<float>::quiet_NaN();
        return ;
    }
    outpData->flt = static_cast<float>(inputData);
}

static void parseDouble(double inputData, OutputData* outpData, ConvertState* state)
{
    if (!state->valid)
    {
        outpData->dbl = std::numeric_limits<double>::quiet_NaN();
        return ;
    }
    outpData->dbl = inputData;
}

static void printFloatValue(float value)
{
    if (isNan(value))
    {
        std::cout << "nanf";
        return ;
    }
    if (isInf(value))
    {
        if (value < 0)
            std::cout << "-inff";
        else
            std::cout << "+inff";
        return ;
    }
    if (isWholeNumber(value))
        std::cout << std::fixed << std::setprecision(1) << value << "f";
    else
        std::cout << std::setprecision(7) << value << "f";
}

static void printDoubleValue(double value)
{
    if (isNan(value))
    {
        std::cout << "nan";
        return ;
    }
    if (isInf(value))
    {
        if (value < 0)
            std::cout << "-inf";
        else
            std::cout << "+inf";
        return ;
    }
    if (isWholeNumber(value))
        std::cout << std::fixed << std::setprecision(1) << value;
    else
        std::cout << std::setprecision(15) << value;
}

static void printData(OutputData* outpData, ConvertState* state)
{
    std::ios::fmtflags	oldFlags = std::cout.flags();
    std::streamsize		oldPrec = std::cout.precision();

    std::cout << "char: ";
    if (state->charImpossible)
        std::cout << "impossible";
    else if (state->charNonDisplayable)
        std::cout << "Non displayable";
    else
        std::cout << "'" << outpData->chr << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (state->intImpossible)
        std::cout << "impossible";
    else
        std::cout << outpData->nbr;
    std::cout << std::endl;

    std::cout << "float: ";
    if (state->floatImpossible)
        std::cout << "impossible";
    else
        printFloatValue(outpData->flt);
    std::cout << std::endl;

    std::cout << "double: ";
    if (state->doubleImpossible)
        std::cout << "impossible";
    else
        printDoubleValue(outpData->dbl);
    std::cout << std::endl;

    std::cout.flags(oldFlags);
    std::cout.precision(oldPrec);
}

void ScalarConverter::convert(std::string& baseString)
{
    OutputData	outpData;
    ConvertState	state;
    double		parsedValue;

    state.valid = parseToDouble(baseString, parsedValue);
    state.charImpossible = false;
    state.charNonDisplayable = false;
    state.intImpossible = false;
    state.floatImpossible = false;
    state.doubleImpossible = false;

    parseChar(parsedValue, &outpData, &state);
    parseInt(parsedValue, &outpData, &state);
    parseFloat(parsedValue, &outpData, &state);
    parseDouble(parsedValue, &outpData, &state);
    printData(&outpData, &state);
}

//NON NEEDED OCF IMPLEMENTATION

ScalarConverter::ScalarConverter() { };

ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {(void)other; return(*this);}

ScalarConverter::~ScalarConverter() { };