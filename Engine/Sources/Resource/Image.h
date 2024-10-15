#pragma once
#include <Math/Math.h>

// �����Կ��� �̹����� 
// ������ 2���� �迭�̴�.

//class Color
//{
//	unsigned char r;
//	unsigned char g;
//	unsigned char b;
//	unsigned char a;
//};


// �̹��� => Image
// �׸��� => Renderer �̿� ���� Ŭ�������� ������ ���´�.
class ConsoleImage
{

public:
	~ConsoleImage();

	void Release();

	// ���� ä��ų�?
	// �̹����� ũ�⸦ �ٲ۴�.
	// void Resize(int _X, int _Y, char _BaseChar);

	// �̹����� �����.
	void Clear(char _Clearchar);

	void Create(FIntPoint size, char _BaseChar)
	{
		Create(size.x_, size.y_, _BaseChar);
	}

	// �̹����� �����.
	void Create(int _X, int _Y, char _BaseChar);

	inline char* GetLine(size_t _Y)
	{
		return Arr[_Y];
	}

	inline char GetPixel(int _X, int _Y)
	{
		return Arr[_Y][_X];
	}

	inline int GetImageSizeX()
	{
		return X;
	}

	inline int GetImageSizeY()
	{
		return Y;
	}

	void Copy(FIntPoint _Offset, ConsoleImage& _Image);

	void SetPixel(FIntPoint _Pos, char _Char);

private:
	// ��� �ȵ˴ϴ�.
	char** Arr = nullptr;
	int X = 0;
	int Y = 0;
};

