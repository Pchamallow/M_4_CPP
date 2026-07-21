/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:19:20 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 18:23:37 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <cstdlib>

Point MakePoint( int choose )
{
	switch (choose)
	{
		case inside:
			return	Point(3.f, 3.f);
		case outside:
			return	Point(0.f, 1.f);
		case onEdge:
			return	Point(1.f, 4.f);
		case onVertex:
			return	Point(0.f, 0.f);
		default: // inside
			return	Point(3.f, 3.f);
	}
}

int main( int, char **av )
{
	{
		Point	a;
		Point	b(1.f, 2.f);
		Point	c(b);
		Point	d = b;

		std::cout << std::endl;
		std::cout << "Initialisations" << std::endl;
		std::cout << "Point	a -> getX =		" << a.getX() << std::endl;
		std::cout << "Point	b(1.f, 2.f) -> getY =	" << b.getY() << std::endl;
		std::cout << "Point	c(b) -> getX =		" << c.getX() << std::endl;
		std::cout << "Point	(d = b) -> getY = 	" << d.getY() << std::endl;
		std::cout << std::endl;
	}
	{
		Point	a(0.f, 0.f);
		Point	b(5.f, 4.f);
		Point	c(0.f, 4.f);

		int	choose = 4;
		if (av && av[1])
			choose = std::atoi(av[1]);

		Point point = MakePoint(choose);

		std::cout << "Triangle" << std::endl;
		std::cout << "Point	a =		" << a.getX() << "; " << a.getY() << std::endl;
		std::cout << "Point	b =		" << b.getX() << "; " << b.getY() << std::endl;
		std::cout << "Point	c =		" << c.getX() << "; " << c.getY() << std::endl;
		std::cout << "Point	point =		" << point.getX() << "; " << point.getY() << std::endl;
		if (bsp(a, b, c, point))
			std::cout << "Point is inside triangle" << std::endl;
		else
			std::cout << "Point is outside triangle" << std::endl;
		std::cout << std::endl;

	}
}