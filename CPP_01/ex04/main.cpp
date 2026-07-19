/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:26:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/19 13:12:16 by pswirgie         ###   ########.fr       */
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

	std::string before;
	std::string after;
	while (getline(data->original, data->line))
	{
		while (i != std::string::npos)
		{
			i = data->line.find(model);
			if (i == std::string::npos)
				break ;
			if (i > 0)
				before = data->line.substr(0, i);
			before.append(target);
			if (data->line[i + model.size()])
			{
				after = data->line.substr(i + len, data->line.size());
				before.append(after);
			}
			data->line = before;
		}
		i = 0;
		before.clear();
		after.clear();
		data->write_target << data->line << std::endl;
	}
	return ;
}

/*
* Handle : 
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
