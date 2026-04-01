/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:22:27 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 01:53:38 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& main);
		~Brain();
		Brain& operator=(const Brain& other);

		void	setIdea(int index, std::string idea);
		std::string& getIdea(int index);
};

#endif