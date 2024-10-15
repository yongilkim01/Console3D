#include "File.h"
#include "DebugHelper/Debug.h"

LFile::LFile()
{


}

LFile::~LFile()
{
	// �Ҹ��ڸ� �̿��ؼ� �ڿ������� �ı��ǵ��� ����°� ����.
	Close();
}

void LFile::FileOpen(const char* mode)
{
	fopen_s(&file_, path_, mode);

	// ����ڵ�
	// ������ ���� ���ߴ�.
	if (nullptr == file_)
	{
		// char [] Arr0
		// char [] Arr1
		// Arr0 + Arr1

		MSGASSERT(path_ /*+ "���� ���¿� �����߽��ϴ�"*/);
	}
}


void LFile::Write(const void* ptr, size_t size)
{
	if (0 == size)
	{
		MSGASSERT("ũ�Ⱑ 0�� �����͸� ������ �����ϴ�.");
	}

	if (nullptr == ptr)
	{
		MSGASSERT("�������� �ʴ� �޸𸮸� ����Ϸ��� �߽��ϴ�.");
	}

	// w�� ��쿡 ���� ����ó��
	if (nullptr == file_)
	{
		MSGASSERT("���� ���� ���Ͽ� ������ ������ �߽��ϴ�");
		return;
	}

	fwrite(ptr, size, 1, file_);
}

void LFile::Read(void* ptr, size_t size)
{
	if (0 == size)
	{
		MSGASSERT("ũ�Ⱑ 0�� �����͸� �������� �����ϴ�.");
	}

	if (nullptr == ptr)
	{
		MSGASSERT("�������� �ʴ� �޸𸮸� �������� �߽��ϴ�.");
	}

	if (nullptr == file_)
	{
		MSGASSERT("���� ���� ���Ͽ� ������ ������ �߽��ϴ�");
		return;
	}

	fread(ptr, size, 1, file_);
}

// �ζ����� ������ �������и��ϸ� �ζ����� �ϱ� ����ϴ�.
bool LFile::IsExits()
{
	int result = _access(path_, 00);

	// 0�̸� �ִ°� 0 �̿��� ���̸� ���� ��
	return 0 == result;
}



// ���� ���� Ȥ�� �÷��� ��ɵ��� ������ �ѽ��̴�.
// �����Ѵ�.
// ����Ѵ�.
// ������
void LFile::Close()
{
	// ����ڵ�
	if (nullptr != file_)
	{
		fclose(file_);
		file_ = nullptr;
	}
}

