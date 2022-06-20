/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:05:55 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/10 19:00:54 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	x;
		Fixed const	y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &obj);
		~Point(void);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		Point	&operator=(Point const &obj);
		bool	operator==(Point const &obj) const;
};

#endif
