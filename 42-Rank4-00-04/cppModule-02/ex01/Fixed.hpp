/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:24:16 by rde-fari          #+#    #+#             */
/*   Updated: 2025/10/29 16:50:11 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixedPoint;
		static const int	_fracBits = 8;
	public:
		Fixed();
		Fixed(const int intNbr);
		Fixed(const float floatNbr);
		Fixed(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt( void ) const;
		float	toFloat( void ) const;

		//Operator Overload Sector.
		Fixed&	operator=(const Fixed& other);
};

std::ostream& operator<<(std::ostream& os, Fixed const& rhs);

#endif
