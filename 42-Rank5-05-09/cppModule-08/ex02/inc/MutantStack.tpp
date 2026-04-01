/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:02:29 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/27 17:07:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//Begin ocf


template <class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <class T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template <class T>
MutantStack<T>::~MutantStack(void) {}

template <class T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void) {
	return (this->c.rbegin());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void) {
	return (this->c.rend());
}