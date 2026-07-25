/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 16:33:35 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
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
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - initialisation - Cat" << std::endl << std::endl;
		Cat	a;
		std::cout << std::endl;
		Cat	b(a);
		std::cout << std::endl;
		Cat	c = b;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - initialisation - Dog" << std::endl << std::endl;
		Dog	a;
		std::cout << std::endl;
		Dog	b(a);
		std::cout << std::endl;
		Dog	c = b;
		std::cout << std::endl;
	}
}

void	testsSoundAndType()
{
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
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

void	testsSubject()
{
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
	std::cout << "TESTS - the subject" << std::endl << std::endl;
	
	const Animal* j = new Dog();
	std::cout << "getype: " << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << std::endl;
	
	const Animal* i = new Cat();
	std::cout << "getype: " << i->getType() << " " << std::endl;
	i->makeSound();
	
	std::cout << std::endl;
	const Animal* meta = new Animal();
	meta->makeSound();
	std::cout << std::endl;

	delete j;
	delete i;
	delete meta;
}

int	main ()
{
	#ifdef DEBUG
	testsInitByTypes();
	#endif

	testsSubject();
	testsSoundAndType();
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - WrongAnimal and WrongCat" << std::endl << std::endl;

		const WrongAnimal* a = new WrongCat();
		std::cout << std::endl;
		std::cout << "getype: " << a->getType() << " " << std::endl;
		a->makeSound();
		std::cout << std::endl;
		delete a;
	}
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
}
