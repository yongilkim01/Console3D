#pragma once
#include <..\..\BaseSystem\Sources\Math\Math.h>
#include "Resource/Image.h"

class AActor
{
public:
	virtual void BeginPlay();
	virtual void Tick();

	void Render(ConsoleImage* _BackBuffer);

	void SetActorLocation(FIntPoint _Pos);

	void AddActorLocation(FIntPoint _Pos);

	FIntPoint GetActorLocation()
	{
		return Pos;
	}

	class Renderer* CreateDefaultSubObject();

	class Renderer* GetImageRenderer()
	{
		return ImageRenderer;
	}

	void Destroy();

	bool IsDestory()
	{
		return DestoryValue;
	}

	bool IsActive()
	{
		return ActiveValue;
	}

	bool IsTickable()
	{
		return false == DestoryValue && true == ActiveValue;
	}


protected:
	// ConsoleImage RenderImage;
	// �������� ����� ����.
	// �׷����� �ϸ� �������� �����
	// �ȱ׷������ϸ� �ȸ���� �ȴ�.

private:
	// ���� �׾���? ��ҳ�?
	// true ���� ���� ��ü
	bool DestoryValue = false;
	bool ActiveValue = true;


	class Renderer* ImageRenderer;
	FIntPoint Pos;
	// �����Ҵ� �Ұų� ���ų�?
};

typedef AActor Super;
