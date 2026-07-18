/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:26:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/18 18:10:23 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.h"
#include <iostream>
#include <fstream>

int	write_to_replace(t_data *data, std::string model, std::string target)
{
	(void)model;
	(void)target;
	(void)data;

	// print tout l original
	// mais if find model replace by target
	// data-> line a deja du contenu
	size_t i = data->line.find(model);

	
	while (i != std::string::npos)
	{
		size_t len = model.size();
		data->line.replace(i, i + len, target);
		std::cout << data->line << std::endl;
		
		i = data->line.find(model);
		if (i == std::string::npos)
			std::cout << "not found" << std::endl;
		if (i != std::string::npos)
			std::cout << "founded" << std::endl;
	}
	// data->write_target << "lol";
	data->write_target << data->line;
	
	// getline(data->file, data->line);

	return (0);
}

/*
* TO DO TESTS
* replace already exist, 
* replace already have content
* replace chmod 000
*/
int	main(int ac, char **av)
{
	t_data	data;

	if (invalid_args(&data, ac, av))
		return (1);

	if (create_file(&data, av[1]))
		return (1);
	
	if (write_to_replace(&data, av[2], av[3]))
		return (1);

	// remplacer chaque cibel par target

	// 4. comment ecrire dans un doc 

	// 
	data.file.close();
	data.write_target.close();
}
