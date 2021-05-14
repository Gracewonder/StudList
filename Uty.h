#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

string ImportName(string str)
{
	int pos = str.find(';');
	string name = str.substr(0, pos);
	return name;
}
vector<int> ImportNumbers(string str)
{
	vector<int> nums;
	int num;
	string temp;
	int pos;
	do {
		pos = str.find(';');
		if (pos == 0 && str.length() > 1)
		{
			str = str.substr(pos + 1);
		}
		pos = str.find(';');
		temp = str.substr(0, pos);
		num = stoi(temp);
		nums.push_back(num);
		str = str.substr(pos);
	} while (str != ";");

	return nums;
}

map<string, vector<int>> ImportList(string FilePath)
{
	map<string, vector<int>> StudsResult;
	pair<string, vector<int>> OneStud;
	vector <int> OneStudNums;
	fstream file;
	file.open(FilePath);
	string temp;
	string Name;
	if (!file.is_open())
	{
		cout << "Error. File is not found";
	}
	else {
		while (!file.eof()) {
			getline(file, temp);
			OneStud.first = ImportName(temp);
			int pos = temp.find(';');
			temp = temp.substr(pos);
			OneStud.second = ImportNumbers(temp);
			StudsResult.insert(OneStud);
		}
		file.close();
	}
	return StudsResult;
}
void PrintList(map<string, vector<int>> list)
{
	for (auto item : list) {
		cout << item.first << " - ";
		for (auto elem : item.second)
		{
			cout << elem << "\t";
		}
		cout << endl;
	}
}