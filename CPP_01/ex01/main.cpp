/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:39:25 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/08 23:58:47 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "Mish");
    for (int i = 0; i < N; ++i)
        horde[i].announce();
    delete[] horde;
    return (0);
}