#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class videoshop
{
public:
	string film_name, director, genre;
	double pop_rat;
	int disk_price;
	videoshop()
	{

	}
	videoshop(string name_1, string name_2, string name_3, double rating, int price)
	{
		film_name = name_1;
		director = name_2;
		genre = name_3;
		pop_rat = rating;
		disk_price = price;
	}
	videoshop(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
	{

	}
};