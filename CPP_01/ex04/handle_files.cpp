/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:20:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/18 17:48:16 by pswirgie         ###   ########.fr       */
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
	if (!av[1] || is_whitespaces(av[1])
		|| !av[2] || is_whitespaces(av[2])
		|| !av[3] || is_whitespaces(av[3]))
	{
		std::cerr << "Error: 3 parameters requiered" << std::endl;
		return (1);
	}
	data->file.open(av[1], std::ios::in);
	if (!data->file.is_open())
	{
		std::cerr << "Error: Unable to open " << av[1] << std::endl; 
		return (1);
	}
	if (!getline(data->file, data->line))
	{
		std::cerr << "Error: Failed to read data from " << av[1] << std::endl;
		data->file.close();
		return (1);
	}
	return (0);
}

int	create_file(t_data *data, char *original)
{
	std::string	name;
	name = original;
	name.append(".replace");

	// is exist / truncate
	data->out_target.open(name.c_str());
	if (!data->out_target.is_open())
	{
		std::cerr << "Error: Unable to open " << name << std::endl; 
		return (1);
	}
	data->out_target.close();

	// permission write
	data->perm_target.open(name.c_str());
	if (!data->perm_target.is_open())
	{
		std::cerr << "Error: Permission denied for " << name << std::endl; 
		return (1);
	}
	data->perm_target.close();
	
	data->write_target.open(name.c_str());

	return (0);
}
