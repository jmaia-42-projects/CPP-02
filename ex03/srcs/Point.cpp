/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:56:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/10 19:01:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) { }
Point::Point(float const x, float const y):	x(x), y(y) { }

Point::Point(Point const &obj):	x(obj.x), y(obj.y) { }

Point::~Point(void) { }

Point	&Point::operator=(Point const &obj)
{
	(void) obj;
	return (*this);
}

bool	Point::operator==(Point const &obj) const
{
	return (this->x == obj.x && this->y == obj.y);
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}
