/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:17:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 10:15:39 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static float	area(Point point1, Point point2, Point point3)
{
	float x1 = point1.getX();
	float y1 = point1.getY();
	float x2 = point2.getX();
	float y2 = point2.getY();
	float x3 = point3.getX();
	float y3 = point3.getY();
	return (std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	triangle = area(a, b, c);
	float	areaPoint1 = area(point, b, c);
	float	areaPoint2 = area(a, point, c);
	float	areaPoint3 = area(a, b, point);
	
	#ifdef DEBUG
	std::cout << triangle << std::endl;
	std::cout << areaPoint1 << std::endl;
	std::cout << areaPoint2 << std::endl;
	std::cout << areaPoint3 << std::endl;
	#endif

	if (areaPoint1 == 0 || areaPoint2 == 0 || areaPoint3 == 0)
		return (false);
	
	return (triangle == areaPoint1 + areaPoint2 + areaPoint3);
}
