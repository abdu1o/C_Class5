#pragma once

class Pond
{
private:
	int width;
	int lenth;
	int depth;
	char* type;

public:
	Pond();
	Pond(int width, int lenth, int depth, char* type);
	Pond(Pond& obj);

	int Size();
	int Area();
	bool TypeCheck(Pond& obj);
	int AreaCheck(Pond& obj);

	const int GetWidth();
	const int GetLenth();
	const int GetDepth();
	const char* GetType();

	const void SetWidth(int _width);
	const void SetLenth(int _lenth);
	const void SetDepth(int _depth);
	const void SetType(char* _type);
};
