//Написать программу, которая считывает из файла данные в память.
//Данные хранятся в файле в следующем виде :
//фамилия - оценка1, оценка2, ..., оценка;
//Результат выложить на GitHub
//Сорокин Алексей
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "Uty.h"

using namespace std;

int main()
{
	string FilePath = "Primer.txt";
	map<string, vector<int>> Students;
	Students = ImportList(FilePath);
	PrintList(Students);
}