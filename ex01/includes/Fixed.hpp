/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:31:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/18 10:40:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class	Fixed
{
	private:
		static int const	nFractionalBits = 8;
		int					value;
	public:
		Fixed(void);
		Fixed(Fixed const &obj);
		Fixed(int const nbr);
		Fixed(float const floatNbr);
		~Fixed(void);

		Fixed	&operator=(const Fixed& obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
