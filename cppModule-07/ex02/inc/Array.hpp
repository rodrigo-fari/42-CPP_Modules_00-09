/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:07:36 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 18:09:57 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <string>
# include <exception>

template<typename T>
class Array {
	private:
		T*		_arrayTemplate;
		size_t	_size;

	public:
		Array() : _arrayTemplate(NULL), _size(0) { }
		Array(unsigned int n) : _arrayTemplate(new T[n]()), _size(n) { }
		Array(const Array& other) : _arrayTemplate(NULL), _size(other._size) {
			if (_size > 0)
				_arrayTemplate = new T[_size];
			for (size_t i = 0; i < _size; i++) {
				_arrayTemplate[i] = other._arrayTemplate[i];
			}
		}
		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _arrayTemplate;
				_size = other._size;
				_arrayTemplate = (_size > 0) ? new T[_size] : NULL;
				for (size_t i = 0; i < _size; i++) {
					_arrayTemplate[i] = other._arrayTemplate[i];
				}
			}
			return (*this);
		}
		~Array() {
			delete[] _arrayTemplate;
		}
		T& operator[](size_t index) {
			if (index >= _size)
				throw OutOfBounds();
			return (_arrayTemplate[index]);
		}
		const T& operator[](size_t index) const {
			if (index >= _size)
				throw OutOfBounds();
			return (_arrayTemplate[index]);
		}
		size_t size() const {
			return (this->_size);
		}
		class OutOfBounds : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Error: Index out of bounds!");
				};
		};
};

#endif