/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:47:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/20 21:48:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"
#include "bsp.hpp"

int main(void)
{
	{
		Point	A(0, 0);
		Point	B(5, 5);
		Point	C(0, 10);
		Point	pt(3, 5);

		std::cout << (bsp(A, B, C, pt) ? "Inside !" : "Outside !") << std::endl;
	}
	{
		Point	A(0, 0);
		Point	B(5, 5);
		Point	C(0, 10);
		Point	pt(3, 8);

		std::cout << (bsp(A, B, C, pt) ? "Inside !" : "Outside !") << std::endl;
	}
	{
		Point	A(0, 0);
		Point	B(5, 5);
		Point	C(0, 10);
		Point	pt(5, 5);

		std::cout << (bsp(A, B, C, pt) ? "Inside !" : "Outside !") << std::endl;
	}
	{
		Point	A(0, 0);
		Point	B(5, 5);
		Point	C(0, 10);
		Point	pt(3, 3); 

		std::cout << (bsp(A, B, C, pt) ? "Inside !" : "Outside !") << std::endl;
	}
	return 0;
}
