#pragma once
#include <../../BaseSystem/Sources/Math/Math.h>
#include <vector>

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

	void Create(FIntPoint _Size, char _BaseChar)
	{
		Create(_Size.X, _Size.Y, _BaseChar);
	}

	// �̹����� �����.
	void Create(int _X, int _Y, char _BaseChar);

	// ������ �����Ұų� ������ �����Ұųİ� �����ϴ�.
	// �̰� ���簡 �Ͼ�ϴ�. 
	inline std::vector<char> GetLine(size_t _Y)
	{
		return Pixels[_Y];
	}

	// ������ ������
	inline std::vector<char>& GetLineRef(size_t _Y)
	{
		return Pixels[_Y];
	}

	inline char GetPixel(int _X, int _Y)
	{
		return Pixels[_Y][_X];
	}

	inline char* GetPixelRef(int _X, int _Y)
	{
		return &(Pixels[_Y][_X]);
	}

	inline FIntPoint GetImageSize() const
	{
		return ImageSize;
	}

	void Copy(FIntPoint _Offset, ConsoleImage& _Image);

	void SetPixel(FIntPoint _Pos, char _Char);
private:
	// ��� �ȵ˴ϴ�.
	// char** Arr = nullptr;
	std::vector<std::vector<char>> Pixels;
	FIntPoint ImageSize;
};

