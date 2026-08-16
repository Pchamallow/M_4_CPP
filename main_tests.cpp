/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 09:52:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/16 09:53:27 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RED		"\033[31m"
#define BROWN	"\033[33m"
#define RESET	"\033[0m"

int main( void )
{
	std::cout << std::endl << std::string(60, '-') << std::endl;

	std::cout << BROWN << "TESTS - Intern : create each form + try create with form wrong name" << RESET << std::endl;
	std::cout << std::endl;
}