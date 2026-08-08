/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:18:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/08 14:01:06 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#define RED		"\033[31m"
#define RESET	"\033[0m"

// void	testsInit()
// {
// 	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
	

// 	std::cout << "TESTS - initialisation - getter - setter " << std::endl << std::endl;
	

// }

// void	testsLimits()
// {
// 	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
// 	std::cout << "TESTS - Limits grades" << std::endl << std::endl;
	


// }

int main( void )
{
	// testsInit();
	// testsLimits();

	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
	std::cout << "TESTS - Bureaucrat try to sign a form" << std::endl << std::endl;
	
	Bureaucrat quentin("Quentin", 3);
	
	ShrubberyCreationForm formS("permis");
	// AForm *forms = new ShrubberyCreationForm("permis");
	quentin.executeForm(formS);
	formS.execute(quentin);

	std::cout << std::endl << std::string(60, '-') << std::endl << std::endl;
}