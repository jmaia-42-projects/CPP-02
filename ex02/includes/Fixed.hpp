/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:31:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/23 12:11:04 by jmaia            ###   ########.fr       */
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

		Fixed			&operator=(const Fixed& obj);
		bool			operator>(const Fixed &obj) const;
		bool			operator<(const Fixed &obj) const;
		bool			operator>=(const Fixed &obj) const;
		bool			operator<=(const Fixed &obj) const;
		bool			operator==(const Fixed &obj) const;
		bool			operator!=(const Fixed &obj) const;
		Fixed			operator+(const Fixed &obj) const;
		Fixed			operator-(const Fixed &obj) const;
		Fixed			operator*(const Fixed &obj) const;
		Fixed			operator/(const Fixed &obj) const;
		Fixed			operator++();
		Fixed			operator++(int);
		Fixed			operator--();
		Fixed			operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
