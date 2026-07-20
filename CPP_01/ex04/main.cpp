/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:26:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 11:04:57 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"
#include <iostream>
#include <fstream>

void	write_to_replace(t_data *data, std::string oldStr, std::string newStr)
{
	size_t lenOldStr = oldStr.size();
	size_t lenNewStr = newStr.size();
	size_t i = data->line.find(oldStr);

	std::string before;
	std::string after;
	while (getline(data->original, data->line))
	{
		while (lenOldStr > 0 && i != std::string::npos)
		{
			i = data->line.find(oldStr);
			if (i == std::string::npos)
				break ;
			if (i > 0)
				before = data->line.substr(0, i);
			if (lenNewStr)
				before.append(newStr);
			if (data->line[i + oldStr.size()])
			{
				after = data->line.substr(i + lenOldStr, data->line.size());
				before.append(after);
			}
			data->line = before;
		}
		i = 0;
		before.clear();
		after.clear();
		data->create_target << data->line << std::endl;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (invalid_args(&data, ac, av))
		return (1);

	if (create_file(&data, av[1]))
		return (1);

	write_to_replace(&data, av[2], av[3]);

	data.original.close();
	data.create_target.close();
}
