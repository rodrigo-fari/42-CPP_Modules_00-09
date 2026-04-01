/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:02:09 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/27 17:10:19 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <exception>
# include <algorithm>
# include <vector>
# include <list>
# include <stack>

# define Red "\033[31m"
# define Green "\033[32m"
# define Orange "\033[38;5;208m"
# define Purple "\e[35m"
# define Yellow "\033[33m"
# define Cyan "\033[36m"
# define Reset "\033[0m"

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &other);
		virtual ~MutantStack(void);

		MutantStack&	operator=(MutantStack const &other);
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
};

# include "MutantStack.tpp"

#endif