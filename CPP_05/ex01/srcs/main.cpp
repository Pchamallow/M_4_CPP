/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:18:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/01 16:13:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#define RED		"\033[31m"
#define RESET	"\033[0m"


void	testsInit()
{
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
	
	Form passeport;
	Form attestation("attestation");
	Form permis("permis", 10);
	Form bac("bac", 10, 13);
	Form permisB(permis);

	std::cout << "TESTS - initialisation - getter - setter " << std::endl << std::endl;
	
	std::cout << "Form attestation(attestation), so its name is : " << attestation.getName() << std::endl;
	std::cout << std::endl;

	
	std::cout << "Form permis(permis, 10), so its gardeSign is : " << permis.getGradeSign() << std::endl;
	std::cout << "By default, its gradeExec is at : " << permis.getGradeExec() << std::endl;
	if (permis.getSigned())
		std::cout << permis.getName() << " is signed" << std::endl;
	else
		std::cout << permis.getName() << " is not signed" << std::endl;
	std::cout << std::endl;

	std::cout << "Form permisB(permis), permisB name is : " << permisB.getName() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Form bac(bac, 10, 13)its gardeExec is : " << bac.getGradeExec() << std::endl;
	std::cout << std::endl;

	std::cout << "Overload << :" << std::endl;
	std::cout << bac;
}

int main( void )
{
	testsInit();

	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
	std::cout << "TESTS - Limits grades" << std::endl << std::endl;
	
	std::cout << "Form certification(certification, 151, -1) : " << std::endl;
	Form certification("certification", 151, -1);
	std::cout << std::endl;

	std::cout << "Form adoption(adoption, 150, -1) : " << std::endl;
	Form adoption("adoption", 150, -1);

	Bureaucrat jean("Jean");
	






	
	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
}