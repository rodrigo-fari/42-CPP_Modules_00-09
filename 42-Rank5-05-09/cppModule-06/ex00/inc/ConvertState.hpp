/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertState.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:33:23 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/17 12:34:02 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTSTATE_HPP
# define CONVERTSTATE_HPP

struct ConvertState
{
    bool	valid;
    bool	charImpossible;
    bool	charNonDisplayable;
    bool	intImpossible;
    bool	floatImpossible;
    bool	doubleImpossible;
};


#endif