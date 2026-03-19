/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:50:15 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/19 12:31:20 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t serializedStruct;
	
	serializedStruct = reinterpret_cast<unsigned long>(ptr);
	return (serializedStruct);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* deserializedStruct = NULL;

	deserializedStruct = reinterpret_cast<Data*>(raw);
	return (deserializedStruct);
}