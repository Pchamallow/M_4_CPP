/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:26:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/19 12:35:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"
#include <iostream>
#include <fstream>

void	write_to_replace(t_data *data, std::string model, std::string target)
{
	data->original.open(data->original_name.c_str(), std::ios::in);

	size_t len = model.size();
	size_t i = data->line.find(model);
	while (getline(data->original, data->line))
	{
		while (i != std::string::npos)
		{
			data->line.replace(i, i + len, target);
			i = data->line.find(model);
		}
		i = 0;
		data->write_target << data->line << std::endl;
	}
	return ;
}

/*
* TO DO TESTS
* replace already exist, 
* replace already have content
* replace chmod 000
* valgrind
* original = several lines
* original = without the model
*/
int	main(int ac, char **av)
{
	t_data	data;

	if (invalid_args(&data, ac, av))
		return (1);

	if (create_file(&data, av[1]))
		return (1);

	write_to_replace(&data, av[2], av[3]);

	data.original.close();
	data.write_target.close();
}
