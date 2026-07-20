/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:19:20 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 18:20:25 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed const e( 4235.574215361f );
	Fixed		f( 541 );

	a = Fixed( 1234.4321f );

	std::cout << std::endl;
	std::cout << "comparison operators" << std::endl;
	if (c > b)
		std::cout << c << " > " << b << std::endl;
	if (c < b)
		std::cout << c << " < " << b << std::endl;
	if (e >= a)
		std::cout << e << " >= " << a << std::endl;
	if (e <= a)
		std::cout << e << " <= " << a  << std::endl;
	if (e != a)
		std::cout << e << " != " << a  << std::endl;
	std::cout << std::endl;
	
	std::cout << "arithmetic operators" << std::endl;
	std::cout << c << " + " << b << " = " << c + b << std::endl;
	std::cout << c << " - " << b << " = " << c - b << std::endl;
	std::cout << c << " * " << b << " = " << c * b << std::endl;
	std::cout << c << " / " << b << " = " << c / b << std::endl;
	std::cout << std::endl;

	std::cout << "increment / decrement" << std::endl;
	std::cout << "f	= " << f << std::endl;
	std::cout << "++f	= " << ++f << std::endl;
	std::cout << "f	= " << f << std::endl;
	std::cout << "f++	= " << f++ << std::endl;
	std::cout << "f	= " << f << std::endl;
	std::cout << "--f	= " << --f << std::endl;
	std::cout << "f--	= " << f-- << std::endl;
	std::cout << "f	= " << f << std::endl << std::endl;

	std::cout << "max / min" << std::endl;
	std::cout << "const : " << d << "; " << e << std::endl;
	std::cout << "max is	:" << Fixed::max(d, e) << std::endl;
	std::cout << "min is	:" << Fixed::min(d, e) << std::endl;
	std::cout << "for : " << a << "; " << f << std::endl;
	std::cout << "max is	:" << Fixed::max(a, f) << std::endl;
	std::cout << "min is	:" << Fixed::min(a, f) << std::endl;

	return (0);
}