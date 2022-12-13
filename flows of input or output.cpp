#include "videoshop.cpp"
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
#include <stdio.h>
/*0 � ������
1 � �����
2 � �������
3 � �������
4 � �������
5 � �������
6 � ������
7 � �����
8 � �����
9 � ����� - �����
A � ������ - �������
B � ������ - �������
� � ������ - �������
E � ������ - ������
F � ���� - �����
system("color F0");*/  // ��������� ������ ���� � ������� ������
int get_var(int count);
void print_menu();
void name_search(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10);
void genre_search(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10);
void dir_search(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10);
void the_most_pop_film_in_a_genre(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10);
void show_of_all_rec(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10);
void rem_or_add_of_new_film(videoshop *films);
void sort(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10);
void print(const string& item);
void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int variant;
	videoshop film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10;
	film_1 = { "������� ����", "������� ���� �������", "�����", 9.0, rand() % 100 + 1000 };
	film_2 = { "��������� �����", "����� �������", "�����", 9.1, rand() % 100 + 1000 };
	film_3 = { "���������� ����", "����� ������", "�������", 9.1, rand() % 100 + 1000 };
	film_4 = { "������������ �����", "������� ���������", "������������", 9.1, rand() % 100 + 1000 };
	film_5 = { "�����, ������, 2 ������", "��� ����", "������", 9.0, rand() % 100 + 1000 };
	film_6 = { "������� ���", "��� ����", "������������", 9.0, rand() % 100 + 1000 };
	film_7 = { "12 ������������ ������", "����� �����", "������������", 8.7, rand() % 100 + 1000 };
	film_8 = { "����� ������", "��������� �����", "�������", 9.0, rand() % 100 + 1000 };
	film_9 = { "�������, ������, ����", "������� �����", "�������", 8.6, rand() % 100 + 1000 };
	film_10 = { "�������", "���� ��������", "������", 9.0, rand() % 100 + 1000 };
	videoshop* films = new videoshop{ film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10 };
	ofstream ofile("videoshop.txt", ios::out);
	ifstream ifile("videoshop.txt", ios::in);
	if (ifile.is_open())
	{
		string line;
		while (ifile >> line) cout << line << ' ';
	}
	do
	{
		print_menu();
		variant = get_var(8);
		switch (variant)
		{
		case 1:
		{
			name_search(film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10);
			break;
		}
		case 2:
		{
			genre_search(film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10);
			break;
		}
		case 3:
		{
			dir_search(film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10);
			break;
		}
		case 4:
		{
			the_most_pop_film_in_a_genre(film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10);
			break;
		}
		case 5:
		{
			show_of_all_rec(film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10);
			break;
		}
		case 6:
		{
			rem_or_add_of_new_film(films);
			break;
		}
		case 7:
		{
			sort(film_1, film_2, film_3, film_4, film_5, film_6, film_7, film_8, film_9, film_10);
			break;
		}
		}
		if (variant != 8) system("pause");
	} while (variant != 8);
}
int get_var(int count)
{
	int variant;
	char s[100];
	scanf("%s", s);
	while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
	{
		SetColor(1, 0);
		cout << "������. ������� ����������� ����� - ";
		scanf("%s", s);
	}
	return variant;
}
void print_menu()
{
	SetColor(2, 0);
	cout << "����� �� ��������=1, ����� �� �����=2, ����� �� ��������=3, ����� ���������� ����� � �����=4, ����� ���� �������=5, �������� ��� ���������� ������ ������=6, ����������=7" << endl;
}
void name_search(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
{
	ofstream ofile("videoshop.txt", ios::out);
	ifstream file("videoshop.txt");
	string search, title;
	char name;
	while (!file.eof())
	{
		file.get(name);
		search.push_back(name);
	}
	file.close();
	SetColor(3, 0);
	cout << "��������, ������� ���� �����, - ";
	cin >> title;
	int position = search.find(title);
	if (ofile.is_open())
	{
		ofile << "����� �� ��������" << endl;
		if (position == -1) ofile << "������" << endl;
		else if (title == film_1.film_name) ofile << film_1.film_name << setw(6) << film_1.director << setw(6) << film_1.genre << setw(6) << film_1.pop_rat << setw(6) << film_1.disk_price << endl;
		else if (title == film_2.film_name) ofile << film_2.film_name << setw(6) << film_2.director << setw(6) << film_2.genre << setw(6) << film_2.pop_rat << setw(6) << film_2.disk_price << endl;
		else if (title == film_3.film_name) ofile << film_3.film_name << setw(6) << film_3.director << setw(6) << film_3.genre << setw(6) << film_3.pop_rat << setw(6) << film_3.disk_price << endl;
		else if (title == film_4.film_name) ofile << film_4.film_name << setw(6) << film_4.director << setw(6) << film_4.genre << setw(6) << film_4.pop_rat << setw(6) << film_4.disk_price << endl;
		else if (title == film_5.film_name) ofile << film_5.film_name << setw(6) << film_5.director << setw(6) << film_5.genre << setw(6) << film_5.pop_rat << setw(6) << film_5.disk_price << endl;
		else if (title == film_6.film_name) ofile << film_6.film_name << setw(6) << film_6.director << setw(6) << film_6.genre << setw(6) << film_6.pop_rat << setw(6) << film_6.disk_price << endl;
		else if (title == film_7.film_name) ofile << film_7.film_name << setw(6) << film_7.director << setw(6) << film_7.genre << setw(6) << film_7.pop_rat << setw(6) << film_7.disk_price << endl;
		else if (title == film_8.film_name) ofile << film_8.film_name << setw(6) << film_8.director << setw(6) << film_8.genre << setw(6) << film_8.pop_rat << setw(6) << film_8.disk_price << endl;
		else if (title == film_9.film_name) ofile << film_9.film_name << setw(6) << film_9.director << setw(6) << film_9.genre << setw(6) << film_9.pop_rat << setw(6) << film_9.disk_price << endl;
		else if (title == film_10.film_name) ofile << film_10.film_name << setw(6) << film_10.director << setw(6) << film_10.genre << setw(6) << film_10.pop_rat << setw(6) << film_10.disk_price << endl;
		else ofile << "������� � " << position << " ���������� �������" << endl;
		ifstream ifile("videoshop.txt", ios::in);
		if (ifile.is_open())
		{
			string line;
			while (ifile >> line) cout << line << ' ';
		}
	}
}
void genre_search(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
{
	ofstream ofile("videoshop.txt", ios::out);
	ifstream file("videoshop.txt");
	string genre, search;
	char name;
	while (!file.eof())
	{
		file.get(name);
		search.push_back(name);
	}
	file.close();
	SetColor(4, 0);
	cout << "����, ������� ���� �����, - ";
	cin >> genre;
	int position = search.find(genre);
	if (ofile.is_open())
	{
		ofile << "����� �� �����" << endl;
		if (position == -1) ofile << "������" << endl;
		else if (genre == film_1.genre)
		{
			ofile << film_1.film_name << setw(6) << film_1.director << setw(6) << film_1.genre << setw(6) << film_1.pop_rat << setw(6) << film_1.disk_price << endl;
			ofile << film_2.film_name << setw(6) << film_2.director << setw(6) << film_2.genre << setw(6) << film_2.pop_rat << setw(6) << film_2.disk_price << endl;
		}
		else if (genre == film_3.genre)
		{
			ofile << film_3.film_name << setw(6) << film_3.director << setw(6) << film_3.genre << setw(6) << film_3.pop_rat << setw(6) << film_3.disk_price << endl;
			ofile << film_8.film_name << setw(6) << film_8.director << setw(6) << film_8.genre << setw(6) << film_8.pop_rat << setw(6) << film_8.disk_price << endl;
		}
		else if (genre == film_4.genre)
		{
			ofile << film_4.film_name << setw(6) << film_4.director << setw(6) << film_4.genre << setw(6) << film_4.pop_rat << setw(6) << film_4.disk_price << endl;
			ofile << film_6.film_name << setw(6) << film_6.director << setw(6) << film_6.genre << setw(6) << film_6.pop_rat << setw(6) << film_6.disk_price << endl;
			ofile << film_7.film_name << setw(6) << film_7.director << setw(6) << film_7.genre << setw(6) << film_7.pop_rat << setw(6) << film_7.disk_price << endl;
		}
		else if (genre == film_5.genre)
		{
			ofile << film_5.film_name << setw(6) << film_5.director << setw(6) << film_5.genre << setw(6) << film_5.pop_rat << setw(6) << film_5.disk_price << endl;
			ofile << film_10.film_name << setw(6) << film_10.director << setw(6) << film_10.genre << setw(6) << film_10.pop_rat << setw(6) << film_10.disk_price << endl;
		}
		else if (genre == film_9.genre) ofile << film_9.film_name << setw(6) << film_9.director << setw(6) << film_9.genre << setw(6) << film_9.pop_rat << setw(6) << film_9.disk_price << endl;
	}
	else ofile << "������� � " << position << " ���������� �������" << endl;
	ifstream ifile("videoshop.txt", ios::in);
	if (ifile.is_open())
	{
		string line;
		while (ifile >> line) cout << line << ' ';
	}
}
void dir_search(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
{
	ofstream ofile("videoshop.txt", ios::out);
	ifstream file("videoshop.txt");
	string director, search;
	char name;
	while (!file.eof())
	{
		file.get(name);
		search.push_back(name);
	}
	file.close();
	SetColor(5, 0);
	cout << "�������, �������� ���� �����, - ";
	cin >> director;
	int position = search.find(director);
	if (ofile.is_open())
	{
		ofile << "����� �� ��������" << endl;
		if (position == -1) ofile << "������" << endl;
		else if (director == film_1.director) ofile << film_1.film_name << setw(6) << film_1.director << setw(6) << film_1.genre << setw(6) << film_1.pop_rat << setw(6) << film_1.disk_price << endl;
		else if (director == film_2.director) ofile << film_2.film_name << setw(6) << film_2.director << setw(6) << film_2.genre << setw(6) << film_2.pop_rat << setw(6) << film_2.disk_price << endl;
		else if (director == film_3.director) ofile << film_3.film_name << setw(6) << film_3.director << setw(6) << film_3.genre << setw(6) << film_3.pop_rat << setw(6) << film_3.disk_price << endl;
		else if (director == film_4.director) ofile << film_4.film_name << setw(6) << film_4.director << setw(6) << film_4.genre << setw(6) << film_4.pop_rat << setw(6) << film_4.disk_price << endl;
		else if (director == film_5.director)
		{
			ofile << film_5.film_name << setw(6) << film_5.director << setw(6) << film_5.genre << setw(6) << film_5.pop_rat << setw(6) << film_5.disk_price << endl;
			ofile << film_6.film_name << setw(6) << film_6.director << setw(6) << film_6.genre << setw(6) << film_6.pop_rat << setw(6) << film_6.disk_price << endl;
		}
		else if (director == film_7.director) ofile << film_7.film_name << setw(6) << film_7.director << setw(6) << film_7.genre << setw(6) << film_7.pop_rat << setw(6) << film_7.disk_price << endl;
		else if (director == film_8.director) ofile << film_8.film_name << setw(6) << film_8.director << setw(6) << film_8.genre << setw(6) << film_8.pop_rat << setw(6) << film_8.disk_price << endl;
		else if (director == film_9.director) ofile << film_9.film_name << setw(6) << film_9.director << setw(6) << film_9.genre << setw(6) << film_9.pop_rat << setw(6) << film_9.disk_price << endl;
		else if (director == film_10.director) ofile << film_10.film_name << setw(6) << film_10.director << setw(6) << film_10.genre << setw(6) << film_10.pop_rat << setw(6) << film_10.disk_price << endl;
	}
	else ofile << "������� � " << position << " ���������� �������" << endl;
	ifstream ifile("videoshop.txt", ios::in);
	if (ifile.is_open())
	{
		string line;
		while (ifile >> line) cout << line << ' ';
	}
}
void the_most_pop_film_in_a_genre(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
{
	int style;
	SetColor(6, 0);
	cout << "�����=1, �������=2, ������������=3, ������=4, �������=5" << endl;
	cin >> style;
	switch (style)
	{
	case 1:
	{
		ifstream file("videoshop.txt");
		string search;
		char name;
		while (!file.eof())
		{
			file.get(name);
			search.push_back(name);
		}
		file.close();
		if (film_1.pop_rat > film_2.pop_rat)
		{
			SetColor(7, 0);
			cout << film_1.film_name << setw(6) << film_1.director << setw(6) << film_1.genre << setw(6) << film_1.pop_rat << setw(6) << film_1.disk_price << endl;
		}
		else
		{
			SetColor(8, 0);
			cout << film_2.film_name << setw(6) << film_2.director << setw(6) << film_2.genre << setw(6) << film_2.pop_rat << setw(6) << film_2.disk_price << endl;
		}
		break;
	}
	case 2:
	{
		ifstream file("videoshop.txt");
		string search;
		char name;
		while (!file.eof())
		{
			file.get(name);
			search.push_back(name);
		}
		file.close();
		if (film_3.pop_rat > film_8.pop_rat)
		{
			SetColor(9, 0);
			cout << film_3.film_name << setw(6) << film_3.director << setw(6) << film_3.genre << setw(6) << film_3.pop_rat << setw(6) << film_3.disk_price << endl;
		}
		else
		{
			SetColor(10, 0);
			cout << film_8.film_name << setw(6) << film_8.director << setw(6) << film_8.genre << setw(6) << film_8.pop_rat << setw(6) << film_8.disk_price << endl;
		}
		break;
	}
	case 3:
	{
		ifstream file("videoshop.txt");
		string search;
		char name;
		while (!file.eof())
		{
			file.get(name);
			search.push_back(name);
		}
		file.close();
		if (film_4.pop_rat > film_6.pop_rat && film_4.pop_rat > film_7.pop_rat)
		{
			SetColor(11, 0);
			cout << film_4.film_name << setw(6) << film_4.director << setw(6) << film_4.genre << setw(6) << film_4.pop_rat << setw(6) << film_4.disk_price << endl;
		}
		else if (film_6.pop_rat > film_4.pop_rat && film_6.pop_rat > film_7.pop_rat)
		{
			SetColor(12, 0);
			cout << film_6.film_name << setw(6) << film_6.director << setw(6) << film_6.genre << setw(6) << film_6.pop_rat << setw(6) << film_6.disk_price << endl;
		}
		else
		{
			SetColor(13, 0);
			cout << film_7.film_name << setw(6) << film_7.director << setw(6) << film_7.genre << setw(6) << film_7.pop_rat << setw(6) << film_7.disk_price << endl;
		}
		break;
	}
	case 4:
	{
		ifstream file("videoshop.txt");
		string search;
		char name;
		while (!file.eof())
		{
			file.get(name);
			search.push_back(name);
		}
		file.close();
		if (film_5.pop_rat > film_10.pop_rat)
		{
			SetColor(14, 0);
			cout << film_5.film_name << setw(6) << film_5.director << setw(6) << film_5.genre << setw(6) << film_5.pop_rat << setw(6) << film_5.disk_price << endl;
		}
		else
		{
			SetColor(15, 0);
			cout << film_10.film_name << setw(6) << film_10.director << setw(6) << film_10.genre << setw(6) << film_10.pop_rat << setw(6) << film_10.disk_price << endl;
		}
		break;
	}
	case 5:
	{
		ifstream file("videoshop.txt");
		string search;
		char name;
		while (!file.eof())
		{
			file.get(name);
			search.push_back(name);
		}
		file.close();
		cout << film_9.film_name << setw(6) << film_9.director << setw(6) << film_9.genre << setw(6) << film_9.pop_rat << setw(6) << film_9.disk_price << endl;
		break;
	}
	}
}
void show_of_all_rec(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
{
	ofstream ofile("videoshop.txt", ios::out);
	if (ofile.is_open())
	{
		ofile << "����� ���� �������" << endl;
		ofile << film_1.film_name << setw(3);
		ofile << film_1.director << setw(3);
		ofile << film_1.genre << setw(3);
		ofile << film_1.pop_rat << setw(3);
		ofile << film_1.disk_price << endl;
		ofile << film_2.film_name << setw(3);
		ofile << film_2.director << setw(3);
		ofile << film_2.genre << setw(3);
		ofile << film_2.pop_rat << setw(3);
		ofile << film_2.disk_price << endl;
		ofile << film_3.film_name << setw(3);
		ofile << film_3.director << setw(3);
		ofile << film_3.genre << setw(3);
		ofile << film_3.pop_rat << setw(3);
		ofile << film_3.disk_price << endl;
		ofile << film_4.film_name << setw(3);
		ofile << film_4.director << setw(3);
		ofile << film_4.genre << setw(3);
		ofile << film_4.pop_rat << setw(3);
		ofile << film_4.disk_price << endl;
		ofile << film_5.film_name << setw(3);
		ofile << film_5.director << setw(3);
		ofile << film_5.genre << setw(3);
		ofile << film_5.pop_rat << setw(3);
		ofile << film_5.disk_price << endl;
		ofile << film_6.film_name << setw(3);
		ofile << film_6.director << setw(3);
		ofile << film_6.genre << setw(3);
		ofile << film_6.pop_rat << setw(3);
		ofile << film_6.disk_price << endl;
		ofile << film_7.film_name << setw(3);
		ofile << film_7.director << setw(3);
		ofile << film_7.genre << setw(3);
		ofile << film_7.pop_rat << setw(3);
		ofile << film_7.disk_price << endl;
		ofile << film_8.film_name << setw(3);
		ofile << film_8.director << setw(3);
		ofile << film_8.genre << setw(3);
		ofile << film_8.pop_rat << setw(3);
		ofile << film_8.disk_price << endl;
		ofile << film_9.film_name << setw(3);
		ofile << film_9.director << setw(3);
		ofile << film_9.genre << setw(3);
		ofile << film_9.pop_rat << setw(3);
		ofile << film_9.disk_price << endl;
		ofile << film_10.film_name << setw(3);
		ofile << film_10.director << setw(3);
		ofile << film_10.genre << setw(3);
		ofile << film_10.pop_rat << setw(3);
		ofile << film_10.disk_price;
	}
	ifstream ifile("videoshop.txt", ios::in);
	if (ifile.is_open())
	{
		string line;
		while (ifile >> line) cout << line << ' ';
	}
}
void rem_or_add_of_new_film(videoshop *films)
{
	int task;
	cout << "��������=1, ���������� ������ ������=2" << endl;
	cin >> task;
	switch (task)
	{
	case 1:
	{
		int film;
		cout << "�������� ������� ������=1, �������� ������� ������=2, �������� �������� ������=3, �������� ��������� ������=4, �������� ������ ������=5, �������� ������� ������=6, �������� �������� ������=7, �������� �������� ������=8, �������� �������� ������=9, �������� �������� ������=10" << endl;
		cin >> film;
		switch (film)
		{
		case 1:
		{
			delete& films[0];
			break;
		}
		case 2:
		{
			delete& films[1];
			break;
		}
		case 3:
		{
			delete& films[2];
			break;
		}
		case 4:
		{
			delete& films[3];
			break;
		}
		case 5:
		{
			delete& films[4];
			break;
		}
		case 6:
		{
			delete& films[5];
			break;
		}
		case 7:
		{
			delete& films[6];
			break;
		}
		case 8:
		{
			delete& films[7];
			break;
		}
		case 9:
		{
			delete& films[8];
			break;
		}
		case 10:
		{
			delete& films[9];
			break;
		}
		}
		break;
	}
	case 2:
	{
		videoshop film;
		cout << "�������� ������ - ";
		cin >> film.film_name;
		cout << "������� - ";
		cin >> film.director;
		cout << "���� - ";
		cin >> film.genre;
		cout << "������� ������������=";
		cin >> film.pop_rat;
		cout << "���� �����=";
		cin >> film.disk_price;
		cout << film.film_name << setw(9) << film.director << setw(9) << film.genre << setw(9) << film.pop_rat << setw(9) << film.disk_price << endl;
		break;
	}
	}
}
void sort(videoshop film_1, videoshop film_2, videoshop film_3, videoshop film_4, videoshop film_5, videoshop film_6, videoshop film_7, videoshop film_8, videoshop film_9, videoshop film_10)
{
	ofstream ofile("videoshop.txt", ios::out);
	int sorting;
	cout << "������ ����������=1, ���������� �� ������� ������=2" << endl;
	cin >> sorting;
	switch (sorting)
	{
	case 1:
	{
		string movie_1, movie_2, movie_3, movie_4, movie_5, movie_6, movie_7, movie_8, movie_9, movie_10;
		movie_1 = film_1.film_name + "; " + film_1.director + "; " + film_1.genre;
		movie_2 = film_2.film_name + "; " + film_2.director + "; " + film_2.genre;
		movie_3 = film_3.film_name + "; " + film_3.director + "; " + film_3.genre;
		movie_4 = film_4.film_name + "; " + film_4.director + "; " + film_4.genre;
		movie_5 = film_5.film_name + "; " + film_5.director + "; " + film_5.genre;
		movie_6 = film_6.film_name + "; " + film_6.director + "; " + film_6.genre;
		movie_7 = film_7.film_name + "; " + film_7.director + "; " + film_7.genre;
		movie_8 = film_8.film_name + "; " + film_8.director + "; " + film_8.genre;
		movie_9 = film_9.film_name + "; " + film_9.director + "; " + film_9.genre;
		movie_10 = film_10.film_name + "; " + film_10.director + "; " + film_10.genre;
		string movies[10] = { movie_1, movie_2, movie_3, movie_4, movie_5, movie_6, movie_7, movie_8, movie_9, movie_10 };
		if (ofile.is_open())
		{
			ofile << "������ ����������" << endl;
			ofile << movie_7 << endl;
			ofile << movie_3 << endl;
			ofile << movie_6 << endl;
			ofile << movie_2 << endl;
			ofile << movie_5 << endl;
			ofile << movie_1 << endl;
			ofile << movie_4 << endl;
			ofile << movie_10 << endl;
			ofile << movie_8 << endl;
			ofile << movie_9 << endl;
		}
		ifstream ifile("videoshop.txt", ios::in);
		if (ifile.is_open())
		{
			string line;
			while (ifile >> line) cout << line << ' ';
		}
		set<string> sortedItems;
		int i = 1;
		while (i <= 10)
		{
			sortedItems.insert(movies[i]);
			++i;
		}
		for_each(sortedItems.begin(), sortedItems.end(), &print);
		break;
	}
	case 2:
	{
		string movie_1, movie_2, movie_3, movie_4, movie_5, movie_6, movie_7, movie_8, movie_9, movie_10;
		movie_1 = film_1.film_name + " " + film_1.director + " " + film_1.genre;
		movie_2 = film_2.film_name + " " + film_2.director + " " + film_2.genre;
		movie_3 = film_3.film_name + " " + film_3.director + " " + film_3.genre;
		movie_4 = film_4.film_name + " " + film_4.director + " " + film_4.genre;
		movie_5 = film_5.film_name + " " + film_5.director + " " + film_5.genre;
		movie_6 = film_6.film_name + " " + film_6.director + " " + film_6.genre;
		movie_7 = film_7.film_name + " " + film_7.director + " " + film_7.genre;
		movie_8 = film_8.film_name + " " + film_8.director + " " + film_8.genre;
		movie_9 = film_9.film_name + " " + film_9.director + " " + film_9.genre;
		movie_10 = film_10.film_name + " " + film_10.director + " " + film_10.genre;
		string movies[10] = { movie_1, movie_2, movie_3, movie_4, movie_5, movie_6, movie_7, movie_8, movie_9, movie_10 };
		sort(movies + 2, movies + 10);
		int x = 0;//������ ������� �������
		if (ofile.is_open())
		{
			ofile << "���������� �� ������� ������" << endl;
			while (x < 10)
			{
				ofile << movies[x] << endl;
				x++;
			}
		}
		ifstream ifile("videoshop.txt", ios::in);
		if (ifile.is_open())
		{
			string line;
			while (ifile >> line) cout << line << ' ';
		}
		break;
	}
	}
}
void print(const string& item)
{
	cout << item << endl;
}