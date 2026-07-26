/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 13:38:08 by pswirgie         ###   ########.fr       */
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

		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

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
		std::cout << "TESTS - MateriaSource - learn and create same material" << std::endl << std::endl;
		
		IMateriaSource* src = new MateriaSource();
		std::cout << "IMateriaSource* src learn Ice" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "AMateria* a = src create ice" << std::endl;
		AMateria* a = src->createMateria("ice");
		std::cout << "a -> getType : " << a->getType() << std::endl;

		std::cout << std::endl << std::string(30, '-') << std::endl;
		std::cout << "TESTS - inventory character and MateriaSource" << std::endl << std::endl;
		
		std::cout << "IMateriaSource* src learn Ice x 4 + Cure" << std::endl;
		src -> learnMateria(new Ice());
		src -> learnMateria(new Ice());
		src -> learnMateria(new Ice());
		src -> learnMateria(new Ice());
		src -> learnMateria(new Cure());
		std::cout << "AMateria* b = src create cure" << std::endl;
		AMateria* b = src->createMateria("cure");
		if (b)
			std::cout << "b -> getType : " << b->getType() << std::endl;
		else
			std::cout << "cure infind" << std::endl;

		std::cout << std::endl << "ICharacter equip ice x 4 + cure" << std::endl;
		Character *mish = new Character("Mish");
		std::cout << "getName : " << mish->getName() << std::endl;
		for (int i = 0; i < 4; i++)
			mish->equip(a);
		mish->equip(a);
		IMateriaSource* srcB = new MateriaSource();
		srcB->learnMateria(new Cure());
		AMateria* cure = srcB->createMateria("cure"); 
		mish->equip(cure);
		std::cout << "Last materia in inventory is " << mish->getInventory(3)->getType() << std::endl;

		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - Characters equip, unequip and use " << std::endl << std::endl;
		mish->unequip(4);
		if (mish->getFloor(0))
			std::cout << "Mish unequip successfully, so on the ground we have materia " << mish->getFloor(0)->getType();
		else
			std::cout << "Mish try to unequip index 4 unsuccessfully, so the floor is empty" << std::endl;
		mish->unequip(3);
		std::cout << "Mish unequip his inventory[3]" << std::endl;
		if (mish->getFloor(0))
			std::cout << "Mish unequip successfully, so on the ground we have materia " << mish->getFloor(0)->getType();
		
		
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
		std::cout << "TESTS - " << std::endl << std::endl;
	
		std::cout << std::string(30, '-') << std::endl << std::endl;
	}
	std::cout << std::endl;
}
