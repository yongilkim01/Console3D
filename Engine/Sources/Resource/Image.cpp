#include "Image.h"

ConsoleImage::~ConsoleImage()
{
	Release();
}

void ConsoleImage::Release()
{
	if (0 == X || 0 == Y)
	{
		return;
	}

	for (size_t y = 0; y < Y; y++)
	{
		delete[] Arr[y];
	}
	delete[] Arr;
}

void ConsoleImage::Create(int _X, int _Y, char _BaseChar)
{
	X = _X;
	Y = _Y;

	// ��
	Arr = new char* [_Y];
	for (size_t y = 0; y < _Y; y++)
	{
		Arr[y] = new char[_X + 1];
	}

	Clear(_BaseChar);
}

void ConsoleImage::Clear(char _Clearchar)
{
	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			Arr[y][x] = _Clearchar;
		}
		// ���������ο� 0�� �ִ´�.
		Arr[y][X] = 0;
	}
}

void ConsoleImage::SetPixel(FIntPoint _Pos, char _Char)
{
	// ȭ�� �ٱ��� �׷����°� ������
	if (0 > _Pos.x_ || X < _Pos.x_)
	{
		return;
	}

	// ȭ�� �ٱ��� �׷����°� ������.
	if (0 > _Pos.y_ || X < _Pos.y_)
	{
		return;
	}

	Arr[_Pos.y_][_Pos.x_] = _Char;
}

void ConsoleImage::Copy(FIntPoint _Offset, ConsoleImage& _Image)
{
	// 2����
	// ��뵵 2����
	for (int y = 0; y < _Image.GetImageSizeY(); y++)
	{
		for (int x = 0; x < _Image.GetImageSizeX(); x++)
		{
			FIntPoint SetPos = _Offset + FIntPoint{ x, y };

			char X = _Image.GetPixel(x, y);

			SetPixel(SetPos, X);
		}
	}
}