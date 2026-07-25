/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:20:05 by pswirgie         ###   ########.fr       */
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
	#ifdef DEBUG
	testsInitByTypes();
	#endif

	testInitArray();
	
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;

	Animal *cat = new Cat();
	// Cat	cat();
	std::cout << cat->setIdea(0, "coucou");
}
