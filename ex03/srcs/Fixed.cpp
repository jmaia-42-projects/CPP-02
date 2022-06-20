/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:42:04 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/25 08:53:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed const&obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(int const nbr)
{
	this->value = nbr << this->nFractionalBits;
}

Fixed::Fixed(float const nbr)
{
	float	decPart;
	int		fracPart;
	double	delta1;
	double	delta2;

	this->value = ((int) nbr) << this->nFractionalBits;
	decPart = nbr - (int) nbr;
	fracPart = decPart * (1 << this->nFractionalBits);
	this->value += fracPart;
	delta1 = this->toFloat() - nbr;
	delta1 *= delta1 < 0 ? -1 : 1;
	this->value++;
	delta2 = this->toFloat() - nbr;
	delta2 *= delta2 < 0 ? -1 : 1;
	if (delta1 < delta2)
		this->value--;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &obj) const
{
	return (this->value > obj.value);
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->value < obj.value);
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (this->value >= obj.value);
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (this->value <= obj.value);
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->value == obj.value);
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->value != obj.value);
}

Fixed	Fixed::operator+(const Fixed &obj) const
{
	Fixed	result;

	result.value = this->value + obj.value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &obj) const
{
	Fixed	result;

	result.value = this->value - obj.value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &obj) const
{
	Fixed	result;

	result = Fixed(this->toFloat() * obj.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &obj) const
{
	Fixed	result;

	result = Fixed(this->toFloat() / obj.toFloat());
	return (result);
}

Fixed	Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result;

	result = *this;
	result.value = this->value++;
	return (result);
}

Fixed	Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result;

	result = *this;
	result.value = this->value--;
	return (result);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	float			floatNbr;
	unsigned int	fracPart;

	floatNbr = this->toInt();
	fracPart = this->value << (sizeof(fracPart) * 8 - this->nFractionalBits);
	fracPart >>= (sizeof(fracPart) * 8 - this->nFractionalBits);
	floatNbr += 1.0 * fracPart / (1 << this->nFractionalBits);
	return (floatNbr);
}

int		Fixed::toInt(void) const
{
	int	nbr;

	nbr = this->value >> this->nFractionalBits;
	return (nbr);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	return (os << fixed.toFloat());
}
