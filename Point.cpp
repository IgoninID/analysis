// Автор: Игонин Владимир ИВТ-23

#include <iostream>
#include <cassert>
#include <cmath>
#include "Point.h"

/// <summary>
/// Вычисление расстояния между точкой и началом координат
/// </summary>
/// <param name="point - точка"></param>
/// <returns>
/// Расстояние между точкой и началом координат
/// </returns>
double Distance(TPoint& point)
{
	return sqrt((point.x * point.x) + (point.y * point.y));
}

/// <summary>
/// Нахождение точки ближайшей к началу координат
/// Худший случай O(n) - количество сравнений = количеству точек-1, Лучший O(1) - сравнений между точками не требуется
/// </summary>
/// <param name="area - массив точек"></param>
/// <param name="n - количество точек"></param>
/// <returns>
/// Индекс+1 ближайшей к началу координат точки в массиве
/// </returns>
size_t Near0(TPoint* area, size_t n)
{
	if (n >= 1)
	{
		double near = Distance(area[0]);
		int ans = 1;
		if (n == 1)
		{
			return ans;
		}
		for (size_t i = 1; i < n; i++)
		{
			if (near > Distance(area[i]))
			{
				near = Distance(area[i]);
				ans = i+1;
			}
		}
		return ans;
	}
	else
	{
		return 0;
	}
}

/// <summary>
/// Тесты для Вычисления расстояния между точкой и началом координат
/// </summary>
void TestDist()
{
	TPoint p1; p1.x = 5; p1.y = 8;
	TPoint p2; p2.x = -5; p2.y = -6;
	TPoint p3; p3.x = -3; p3.y = 4;
	TPoint p4; p4.x = 2; p4.y = -9;
	TPoint p5; p5.x = 0; p5.y = 0;
	TPoint p6; p6.x = 5; p6.y = 0;
	TPoint p7; p7.x = 0; p7.y = 3;
	TPoint p8; p8.x = -8; p8.y = 0;
	TPoint p9; p9.x = 0; p9.y = -7;
	assert(abs(Distance(p1) - 9.4339) < 0.0001);
	assert(abs(Distance(p2) - 7.8102) < 0.0001);
	assert(abs(Distance(p3) - 5) < 0.0001);
	assert(abs(Distance(p4) - 9.2195) < 0.0001);
	assert(abs(Distance(p5) - 0) < 0.0001);
	assert(abs(Distance(p6) - 5) < 0.0001);
	assert(abs(Distance(p7) - 3) < 0.0001);
	assert(abs(Distance(p8) - 8) < 0.0001);
	assert(abs(Distance(p9) - 7) < 0.0001);
}

/// <summary>
/// Тесты для Нахождения точки ближайшей к началу координат
/// </summary>
void TestNear()
{
	TPoint area1[1]; area1[0].x = 5; area1[0].y = 5;
	TPoint area2[2]; area2[0].x = 5; area2[0].y = 5; area2[1].x = 2; area2[1].y = 2;
	TPoint area5[5]; area5[0].x = 1; area5[0].y = 1; area5[1].x = -4; area5[1].y = -3; area5[2].x = 1; area5[2].y = -9; area5[3].x = -1; area5[3].y = 4; area5[4].x = -5; area5[4].y = 2;
	TPoint area2s[2]; area2s[0].x = 2; area2s[0].y = 2; area2s[1].x = 2; area2s[1].y = 2;
	TPoint area4d[4]; area4d[0].x = 9; area4d[0].y = 4; area4d[1].x = -3; area4d[1].y = -5; area4d[2].x = 9; area4d[2].y = 4; area4d[3].x = -3; area4d[3].y = -5;
	assert(Near0(area1, 1) == 1);
	assert(Near0(area2, 2) == 2);
	assert(Near0(area1, 0) == 0);
	assert(Near0(area5, 5) == 1);
	assert(Near0(area2s, 2) == 1);
	assert(Near0(area4d, 4) == 2);
}