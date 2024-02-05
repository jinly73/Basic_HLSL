#pragma once

#include <d3d11.h>
#include "d3dx11.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")

// �޸� ������ ���� �Լ�(helper function).
namespace Memory
{
	// DX �������̽� ������.
	template <class T> void SafeRelease(T& t)
	{
		if (t)
		{
			t->Release();
			t = nullptr;
		}
	}

	// ���� �Ҵ��� �ν��Ͻ� ������.
	template <class T> void SafeDelete(T& t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
		}
	}

	// �迭 ������.
	template <class T> void SafeDeleteArr(T& t)
	{
		if (t)
		{
			delete[] t;
			t = nullptr;
		}
	}
}