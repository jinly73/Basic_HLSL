#include <Windows.h>	// ������ �����ϱ� ���� �ʿ�.
#include "Engine.h"

int WINAPI WinMain(
	HINSTANCE hinstnace, 
	HINSTANCE previnstance,
	LPSTR lpCmdLine, 
	int nCmdLine)
{
	// �׽�Ʈ��. �޽��� �ڽ�.
	//MessageBox(NULL, L"�׽�Ʈ â�Դϴ�.", L"�׽�Ʈ", MB_YESNO);

	// Engine �ν��Ͻ� ����.
	Engine engine(hinstnace);
	// �ʱ�ȭ.
	if (engine.Init() == false) 
		return 0;

	// ���� ����.
	return engine.Run();
}