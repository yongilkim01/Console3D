#include "File.h"
#include "DebugHelper/Debug.h"

LFile::LFile()
{


}

LFile::~LFile()
{
	// 소멸자를 이용해서 자연스럽게 파괴되도록 만드는게 좋다.
	Close();
}

void LFile::FileOpen(const char* mode)
{
	fopen_s(&file_, path_, mode);

	// 방어코드
	// 파일을 열지 못했다.
	if (nullptr == file_)
	{
		// char [] Arr0
		// char [] Arr1
		// Arr0 + Arr1

		MSGASSERT(path_ /*+ "파일 오픈에 실패했습니다"*/);
	}
}


void LFile::Write(const void* ptr, size_t size)
{
	if (0 == size)
	{
		MSGASSERT("크기가 0인 데이터를 쓸수는 없습니다.");
	}

	if (nullptr == ptr)
	{
		MSGASSERT("존재하지 않는 메모리를 사용하려고 했습니다.");
	}

	// w일 경우에 대한 예외처리
	if (nullptr == file_)
	{
		MSGASSERT("열지 않은 파일에 내용을 쓰려고 했습니다");
		return;
	}

	fwrite(ptr, size, 1, file_);
}

void LFile::Read(void* ptr, size_t size)
{
	if (0 == size)
	{
		MSGASSERT("크기가 0인 데이터를 읽을수는 없습니다.");
	}

	if (nullptr == ptr)
	{
		MSGASSERT("존재하지 않는 메모리를 읽으려고 했습니다.");
	}

	if (nullptr == file_)
	{
		MSGASSERT("열지 않은 파일에 내용을 쓰려고 했습니다");
		return;
	}

	fread(ptr, size, 1, file_);
}

// 인라인은 구현과 선언을분리하면 인라인을 하기 힘듭니다.
bool LFile::IsExits()
{
	int result = _access(path_, 00);

	// 0이면 있는것 0 이외의 값이면 없는 것
	return 0 == result;
}



// 보통 파일 혹은 플랫폼 기능들은 언제나 한쌍이다.
// 시작한다.
// 사용한다.
// 끝낸다
void LFile::Close()
{
	// 방어코드
	if (nullptr != file_)
	{
		fclose(file_);
		file_ = nullptr;
	}
}

