/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 10:49:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/08 16:08:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		 std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for(int i = 1; av[i]; ++i)
	{
		std::string s = av[i];
		std::string::iterator j;
		for(j = s.begin(); j != s.end(); ++j)
			std::cout << (char)std::toupper(*j);
	}
	std::cout << std::endl;
	return (0);
}
