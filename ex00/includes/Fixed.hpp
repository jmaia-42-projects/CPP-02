/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:31:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/18 09:45:51 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		static int const	nFractionalBits = 8;
		int					value;
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		~Fixed(void);

		Fixed	&operator=(const Fixed& obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif
