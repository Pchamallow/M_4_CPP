/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:20:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 11:06:38 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"
#include <iostream>
#include <fstream>

int	is_whitespaces(std::string str)
{
	for(int i = 0; str[i]; ++i)
	{
		if (!std::isspace(str[i]))
			return (0);
	}
	return (1);
}

/*
* 3 none-empty arguments
* a valid file (exist with read permission)
*/
int	invalid_args(t_data *data, int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: 3 parameters requiered" << std::endl;
		return (1);
	}
	if (!av[1] || is_whitespaces(av[1]))
	{
		std::cerr << "Error: Unable to open " << av[1] << std::endl;
		return (1);
	}
	data->original.open(av[1]);
	if (!data->original.is_open())
	{
		std::cerr << "Error: Unable to open " << av[1] << std::endl; 
		return (1);
	}
	data->original_name = av[1];
	return (0);
}

int	create_file(t_data *data, char *original)
{
	std::string	name;
	name = original;
	name.append(".replace");

	data->create_target.open(name.c_str());
	if (!data->create_target.is_open())
	{
		std::cerr << "Error: Unable to open " << name << std::endl; 
		data->original.close();
		return (1);
	}
	return (0);
}
