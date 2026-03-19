/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:18:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/19 12:33:36 by rde-fari         ###   ########.fr       */
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
}

int main (void)
{
	{
		printMsg("== Populating structure ==\n");
		
		Data data;
		data.dataNumber = 42;
		data.dataString = "Welcome to 42 school!";
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
		
	}
	return (0);
}
