/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:19:20 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 20:03:04 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	{
		Point	a;
		Point	b(1.f, 2.f);
		Point	c(b);
		Point	d = b;

		std::cout << "Initialisations" << std::endl;
		std::cout << "Point	a =		" << a.getX() << std::endl;
		std::cout << "Point	b(1.f, 2.f) =	" << b.getX() << std::endl;
		std::cout << "Point	c(b) =		" << c.getX() << std::endl;
		std::cout << "Point	d = b ->	" << d.getX() << std::endl;
		std::cout << std::endl;
	}
	{
		Point	a(0.f, 0.f);
		Point	b(5.f, 4.f);
		Point	c(0.f, 4.f);
		Point	point(0.f, 0.f);
		if (bsp(a, b, c, point))
			std::cout << "Point is inside triangle" << std::endl;
		else
			std::cout << "Point is outside triangle" << std::endl;
	}
}