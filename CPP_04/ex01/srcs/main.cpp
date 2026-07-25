/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:46:34 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"
#include "iostream"

void	testInitArray()
{
	{
		std::cout << "TESTS - init array -  half dog / half cat" << std::endl << std::endl;

		Animal* arr[8];

		for (int i = 0; i < 4; i++)
			arr[i] = new Dog();
		std::cout << std::endl;

		for (int i = 4; i < 8; i++)
			arr[i] = new Cat();
		
		std::cout << std::endl;

		for (int i = 0; i < 8; i++)
			delete arr[i];
	}
}

int	main ()
{
	std::cout << std::endl;
	testInitArray();
	
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
	std::cout << "TESTS - subject" << std::endl << std::endl;

	Animal *a = new Cat();
	a->makeSound();
	std::cout << std::endl;
	delete a;

	Animal *b = new Dog();
	b->makeSound();
	std::cout << std::endl;
	delete b;
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - setIdea / getIdea" << std::endl << std::endl;

		Cat c;

		std::cout << std::endl;
		c.setIdea(1, "salut");
		std::cout << "idea is : " << c.getIdea(1) << std::endl;
		c.setIdea(100, "salut");
		c.setIdea(-1, "salut");

		std::cout << std::endl;
	}
	std::cout << std::endl;
}
