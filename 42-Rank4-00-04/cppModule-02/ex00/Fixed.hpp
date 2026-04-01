/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:24:16 by rde-fari          #+#    #+#             */
/*   Updated: 2025/07/09 16:45:45 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_fixedPoint;
		static const int	_fracBits = 8;
	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed&	operator=( const Fixed& other );
		~Fixed();
		int				getRawBits( void ) const;
		void			setRawBits( const int raw );
		
};

#endif