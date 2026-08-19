/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 10:35:52 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/19 11:06:01 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Base
{
	public:
		virtual ~Base(){};
};

class A : virtual public Base
{

};

class B : virtual public Base
{

};

class C : virtual public Base
{

};

class D : virtual public Base
{

};