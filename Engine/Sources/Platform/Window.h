#pragma once
#include "Resource/Image.h"
#include <../../BaseSystem/Sources/Math/Math.h>

class UConsoleWindow
{

public:
	UConsoleWindow();


	// �ʹ̴� ��ǻ�Ͱ� �ִٰ� ��������.

	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0
	// "****************"0

	void BeginPlay();

	void ScreenRender();

	void SetScreenSize(FIntPoint _Value)
	{
		SetScreenSize(_Value.X, _Value.Y);
	}

	void SetScreenSize(int _X, int _Y);

	void WindowSetPixel(FIntPoint _Value, char _Text = '*')
	{
		WindowSetPixel(_Value.X, _Value.Y, _Text);
	}

	void WindowSetPixel(int _X, int _Y, char _Text = '*');

	void Clear();

	ConsoleImage* GetBackBufferPtr()
	{
		return &BackBuffer;
	}

	ConsoleImage& GetBackBufferRef()
	{
		return BackBuffer;
	}

	int GetWindowSizeX()
	{
		return BackBuffer.GetImageSize().X;
	}

	int GetWindowSizeY()
	{
		return BackBuffer.GetImageSize().Y;
	}

private:
	int FrameDelay = 250;

	// ���������� �츮 ���� ���� �̹���.
	// ���⿡�ٰ� �׸��� ������ ���� ������ �ʾƿ�.
	ConsoleImage BackBuffer;
};

