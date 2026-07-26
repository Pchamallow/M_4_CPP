/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 12:47:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
// #include "../includes/Cure.hpp"
#include "iostream"

int	main ()
{
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - subject" << std::endl << std::endl;

		std::cout << std::endl << std::string(30, '-') << std::endl;
		std::cout << "TESTS - MateriaSource - learn and create same material" << std::endl << std::endl;
		
		IMateriaSource* src = new MateriaSource();
		std::cout << "IMateriaSource* src learn Ice" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "AMateria* a = src create ice" << std::endl;
		AMateria* a = src->createMateria("ice");
		std::cout << "a -> getType : " << a->getType() << std::endl;
		
		// src->learnMateria(new Cure());

		std::cout << "TESTS - inventory character and MateriaSource" << std::endl << std::endl;
		std::cout << "IMateriaSource* src learn Ice x 4 + Cure" << std::endl;
		src -> learnMateria(new Ice());
		src -> learnMateria(new Ice());
		src -> learnMateria(new Ice());
		src -> learnMateria(new Ice());
		src -> learnMateria(new Cure());
		std::cout << "AMateria* b = src create cure" << std::endl;
		AMateria* b = src->createMateria("cure");
		std::cout << "b -> getType : " << b->getType() << std::endl;

		// characters 
		// use ice 
		// use cure

	}
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - " << std::endl << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - " << std::endl << std::endl;
	
		std::cout << std::string(30, '-') << std::endl << std::endl;
	}
	std::cout << std::endl;
}
