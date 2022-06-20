/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:16:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/20 21:47:37 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

#include <cmath>

static double	area(Point const a, Point const b, Point const c);
static double	getLength(Point const a, Point const b);
static double	sum(double *nbrs, size_t length);
static bool		isPointOnLine(Point point, Point a, Point b);
static bool		isNumberBetween(double nbr, double a, double b);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	double	fullArea;
	double	subAreas[3];

	if (isPointOnLine(point, a, b) || isPointOnLine(point, a, c) || isPointOnLine(point, b, c))
		return (false);
	fullArea = area(a, b, c);
	subAreas[0] = area(a, b, point);
	subAreas[1] = area(a, c, point);
	subAreas[2] = area(b, c, point);
	return (roundf(sum(subAreas, 3) * 1000) == roundf(fullArea * 1000));
}

static double	area(Point const a, Point const b, Point const c)
{
	double	lengths[3];
	double	s;

	lengths[0] = getLength(a, b);
	lengths[1] = getLength(b, c);
	lengths[2] = getLength(c, a);
	s = 1.0 / 2 * (lengths[0] + lengths[1] + lengths[2]);
	return (sqrt(s*(s-lengths[0])*(s-lengths[1])*(s-lengths[2])));
}

static double	getLength(Point const a, Point const b)
{
	double	side1;
	double	side2;
	double	length;

	side1 = (a.getX() - b.getX()).toFloat();
	side2 = (a.getY() - b.getY()).toFloat();
	length = sqrt(pow(side1, 2) + pow(side2, 2));
	return (length);
}

static double	sum(double *nbrs, size_t length)
{
	double	_sum;

	_sum = 0;
	for (unsigned int i = 0; i < length; i++)
		_sum += nbrs[i];
	return (_sum);
}

static bool	isPointOnLine(Point point, Point a, Point b)
{
	Fixed	m;
	Fixed	p;

	if (point.getX() == a.getX() && a.getX() == b.getX())
	   	return (isNumberBetween(point.getY().toFloat(), a.getY().toFloat(), b.getY().toFloat()));
	m = (b.getY() - a.getY()) / (b.getX() - a.getX());
	p = b.getY() - m * b.getX();
	if (point.getX() * m + p != point.getY())
		return (false);
	return (isNumberBetween(point.getX().toFloat(), a.getX().toFloat(), b.getX().toFloat()));
}

static bool	isNumberBetween(double nbr, double a, double b)
{
	double	distance;

	distance = std::abs(a - b);
	return (std::abs(nbr - a) <= distance && std::abs(nbr - b) <= distance);
}
