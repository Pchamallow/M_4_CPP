/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 12:08:45 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
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

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		// src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

	}
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - " << std::endl << std::endl;

		// materia source learn a materia and verifier que le createmateria 
		// remvoie bien le meme type 
		// dernier learn = type du creer

		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - " << std::endl << std::endl;
	
		std::cout << std::string(30, '-') << std::endl << std::endl;
	}
	std::cout << std::endl;
}
