#include <fstream>
#include <iostream>
#include <string>
#include "Class.h"
using namespace std;

Pond::Pond() = default;
Pond::Pond(Pond& obj)
{
	this->width = obj.width;
	this->lenth = obj.lenth;
	this->depth = obj.depth;
	this->type = obj.type;
}
Pond::Pond(int width, int lenth, int depth, char* type)
{
	this->width = width;
	this->lenth = lenth;
	this->depth = depth;
	this->type = type;
}

int Pond::Size()
{
	return width * lenth * depth;
}
int Pond::Area()
{
	return width * lenth;
}
bool Pond::TypeCheck(Pond& obj)
{
	bool res = strcmp(this->type, obj.type);
	if (res == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Pond::AreaCheck(Pond& obj)
{
	if (strcmp(this->type, obj.type) == 0)
	{
		if (this->Area() == obj.Area())
		{
			return 1;
		}
		else if (this->Area() < obj.Area())
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	
}

const int Pond::GetWidth()
{
	return width;
}
const int Pond::GetLenth()
{
	return lenth;
}
const int Pond::GetDepth()
{
	return depth;
}
const char* Pond::GetType()
{
	return type;
}

const void Pond::SetWidth(int _width)
{
	width = _width;
}
const void Pond::SetLenth(int _lenth)
{
	lenth = _lenth;
}
const void Pond::SetDepth(int _depth)
{
	depth = _depth;
}
const void Pond::SetType(char* _type)
{
	type = _type;
}

istream& operator>>(std::istream& ConsoleIn, Pond& obj)
{
	int width;
	cout << "Width: ";
	ConsoleIn >> width;
	obj.SetWidth(width);

	int lenth;
	cout << "Lenth: ";
	ConsoleIn >> lenth;
	obj.SetLenth(lenth);

	int depth;
	cout << "Depth: ";
	ConsoleIn >> depth;
	obj.SetDepth(depth);

	char my_type[20];
	cout << "Type: ";
	ConsoleIn >> my_type;
	obj.SetType(my_type);

	return ConsoleIn;
}
ostream& operator<<(std::ostream& ConsoleOut, Pond& obj)
{
	ConsoleOut << "Width: " << obj.GetWidth() << endl;
	ConsoleOut << "Lenth: " << obj.GetLenth() << endl;
	ConsoleOut << "Depth: " << obj.GetDepth() << endl;
	ConsoleOut << "Type: " << obj.GetType() << endl;

	return ConsoleOut;
}

void Add(Pond*& arr, int& size)
{
	size += 1;
	Pond* tmp = new Pond[size];

	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}

	cin >> tmp[size - 1];

	delete[] arr;
	arr = tmp;
}
void Remove(Pond*& arr, int& size)
{
	int element;
	cout << "Enter element to remove: ";
	cin >> element;

	size -= 1;
	Pond* tmp = new Pond[size];

	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (element - 1 == i)
		{
			j += 1;
		}

		tmp[i] = arr[j];

		j++;
	}

	delete[] arr;
	arr = tmp;
}
void Print(Pond* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void WriteTxt(Pond* arr, int size)
{
	fstream file;

	file.open("txt_file", fstream::in | fstream::out);

	for (int i = 0; i < size; i++)
	{
		file << arr[i] << endl;
	}
	file.close();
}
void WriteBin(Pond* arr, int size)
{
	fstream file;

	file.open("bin_file", fstream::in | fstream::out | fstream::binary);
	file.write((char*)arr, size * sizeof(Pond));
	file.close();
}

int main()
{
	int size = 2;
	Pond* arr = new Pond[size];

	arr[0].SetWidth(3400);
	arr[0].SetLenth(20000);
	arr[0].SetDepth(1240);
	char type1[] = "sea";
	arr[0].SetType(type1);

	arr[1].SetWidth(300);
	arr[1].SetLenth(200);
	arr[1].SetDepth(13);
	char type2[] = "lake";
	arr[1].SetType(type2);

	Print(arr, size);

	WriteTxt(arr, size);
	WriteBin(arr, size);

	delete[]arr;
}
