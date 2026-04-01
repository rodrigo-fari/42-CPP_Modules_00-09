/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/01 16:42:04 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void printMsg(std::string msg)
{
	std::cout << msg << std::endl;
}

static void printStruct(Data* data)
{
	std::cout << "-> data.dataNumber = "
		<< data->dataNumber
		<< "\n-> data.dataString = "
		<< data->dataString
		<< std::endl;
		for (size_t i = 0; i < data->fltVector.size(); i++) {
			std::cout << "\n-> data.fltVector["
			<< i
			<< "] = "
			<< data->fltVector[i];
		}
		std::cout << std::endl;
}

int main (void)
{
	{
		printMsg("== Populating structure ==\n");
		
		Data data;
		data.dataNumber = 42;
		data.dataString = "Welcome to 42 school!";
		
		for (size_t i = 0; i < 5; i++) {
			data.fltVector.push_back(((i + 1) + 0.42));
		}
		
		printStruct(&data);

		printMsg("\n== Serializing struct pointer ==\n");

		unsigned long serializedStruct;
		serializedStruct = Serializer::serialize(&data);
		
		std::cout << "-> Serialized Value = "
			<< serializedStruct 
			<< std::endl;
		
		printMsg("\n== Deserializing struct pointer ==\n");
		
		Data* deserializedStruct = NULL;
		deserializedStruct = Serializer::deserialize(serializedStruct);
		
		printStruct(deserializedStruct);
		std::cout << std::endl;
		
	}
	return (0);
}
