/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 14:35:43 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "iostream"

void	testsInitByTypes()
{
	{
		std::cout << "TESTS - initialisation - Animal" << std::endl << std::endl;
		Animal	a;
		std::cout << std::endl;
		Animal	b(a);
		std::cout << std::endl;
		Animal	c = b;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::string(80, '-') << std::endl << std::endl;
		std::cout << "TESTS - initialisation - Cat" << std::endl << std::endl;
		Cat	a;
		std::cout << std::endl;
		Cat	b(a);
		std::cout << std::endl;
		Cat	c = b;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::string(80, '-') << std::endl << std::endl;
		std::cout << "TESTS - initialisation - Dog" << std::endl << std::endl;
		Dog	a;
		std::cout << std::endl;
		Dog	b(a);
		std::cout << std::endl;
		Dog	c = b;
		std::cout << std::endl;
	}
}

int	main ()
{
	#ifdef DEBUG
	testsInitByTypes();
	#endif

	{
		std::cout << std::endl << std::string(80, '-') << std::endl << std::endl;
		std::cout << "TESTS - makesound - getType" << std::endl << std::endl;

		Cat	a;
		a.makeSound();
		std::cout << "getype: " << a.getType() << std::endl;
		std::cout << std::endl;

		Dog	b;
		b.makeSound();
		std::cout << "getype: " << b.getType() << std::endl;
		std::cout << std::endl << std::endl;
	}
	{
		// const Animal* meta = new Animal();
		// const Animal* j = new Dog();
		// const Animal* i = new Cat();
		// std::cout << j->getType() << " " << std::endl;
		// std::cout << i->getType() << " " << std::endl;
		// i->makeSound(); //will output the cat sound!
		// j->makeSound();
		// meta->makeSound();
	}
}