/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:21:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 18:00:28 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Brain:: Brain()
{
	for(int i = 0; i < 100; i++)
		ideas[i] = "Brain is empty";
	std::cout << "An Brain is created" << std::endl;
}

Brain:: Brain( const Brain& other )
{
	(*this) = other;
	std::cout << "A Brain copy is created" << std::endl;
}

Brain& Brain::operator=( const Brain& other )
{
	if (this != &other)
	{	
		for(int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "A new same Brain is created" << std::endl;
	return (*this);
}

Brain:: ~Brain()
{	std::cout << "A Brain is destroyed" << std::endl;	}


// = METHODS ===================================================

void	Brain::setIdea( int index, std::string content )
{	ideas[index] = content;	}

std::string	Brain::getIdea( int index ) const
{	return (ideas[index]);	}

