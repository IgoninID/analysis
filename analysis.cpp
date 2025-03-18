// Автор: Игонин Владимир ИВТ-23
// Задание: Напишите программу, определяющую какая из n точек, заданных своими координатами, расположена ближе к началу координат.

#include <iostream>
#include <clocale>
#include <string>
#include "Point.h"

using namespace std;

void main_without_args()
{
	int n;
	cout << "Введите количество точек: ";
	cin >> n;
	TPoint* area = new TPoint[n];
	cout << "\nВведите координаты точек: x, y\n";
	for (int i = 0; i < n;i++)
	{
		cin >> area[i].x;
		cin >> area[i].y;
	}
	int nearpoint = Near0(area, n);
	cout << "Ближайшая точка к началу координат: " << area[nearpoint].x << " ; " << area[nearpoint].y;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	TestDist();
	TestNear();
	if (argc == 1)
	{
		main_without_args();
		return 0;
	}
	if ((argc == 2) || (argv[1] == "-h") || (argv[1] == "--h"))
	{
		cout << "Программа вычисляет ближайшую точку к началу координат\n" << "1 аргумент - коичестов точек\n" << "2... аргументы - координаты точек в формате x, y\n";
		return 0;
	}
	if ((argc > 2) && (argc == (stoi(argv[1]) * 2) + 2))
	{
		TPoint* area = new TPoint[stoi(argv[1])];
		for (int i = 0; i < stoi(argv[1]); i++)
		{
			area[i].x = stoi(argv[2 * i + 2]);
			area[i].y = stoi(argv[2 * i + 3]);
		}
		int nearpoint = Near0(area, stoi(argv[1]));
		cout << "Ближайшая точка к началу координат: " << area[nearpoint].x << " ; " << area[nearpoint].y;
		return 0;
	}
	else return 1;
}