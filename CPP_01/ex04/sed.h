/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:55:24 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/19 11:41:23 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

# include <fstream>
# include <string>

typedef struct		s_data
{
	std::string		line;
	std::string		original_name;
	std::fstream	original;
	std::fstream	write_target;
	std::ifstream	perm_target;
	std::ofstream	out_target;
}					t_data;

int	is_whitespaces(std::string str);
int	invalid_args(t_data *data, int ac, char **av);
int	create_file(t_data *data, char *original);


#endif