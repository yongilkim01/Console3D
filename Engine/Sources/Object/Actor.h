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
	// 값형으로 만들수 없다.
	// 그려져야 하면 랜더러를 만들고
	// 안그려져야하면 안만들면 된다.

private:
	// 내가 죽었나? 살았나?
	// true 나는 죽은 객체
	bool DestoryValue = false;
	bool ActiveValue = true;


	class Renderer* ImageRenderer;
	FIntPoint Pos;
	// 동적할당 할거냐 말거냐?
};

typedef AActor Super;
