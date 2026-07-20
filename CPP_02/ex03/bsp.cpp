/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:17:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 20:03:51 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static float	area(Point const point1, Point const point2, Point const point3)
{
	int x1 = point1.getX();
	int y1 = point1.getY();
	int x2 = point2.getX();
	int y2 = point2.getY();
	int x3 = point3.getX();
	int y3 = point3.getY();
	return (std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	triangle = area(a, b, c);
	float	areaPoint1 = area(point, b, c);
	float	areaPoint2 = area(a, point, c);
	float	areaPoint3 = area(a, b, point);

	if (triangle == areaPoint1 + areaPoint2 + areaPoint3)
		
	
	return ();
}
