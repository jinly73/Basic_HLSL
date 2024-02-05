#pragma once
#include <Windows.h>
#include "DXUtil.h"
#include <xnamath.h>

class DXApp
{
public:

	// ���� ����ü ����.
	struct Vertex
	{
		/*float x, y, z;
		float r, g, b, a;*/
		XMFLOAT3 position;
		XMFLOAT4 color;

		Vertex() { }
		Vertex(float x, float y, float z,
			float r, float g, float b, float a) : position(x, y, z), color(r, g, b, a) { }
		Vertex(XMFLOAT3 pos, XMFLOAT4 color) : position(pos), color(color) { }
	};

	// ��� ���ۿ� ����ü ����.
	struct CBPerObject
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	DXApp(HINSTANCE hinstance);
	virtual ~DXApp();

	// ���� �޽��� ����.
	int Run();

	// �����ӿ�ũ �޼ҵ�.
	virtual bool Init();
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:

	// Win32 ��� ����.
	HWND		hwnd;
	HINSTANCE	hinstance;
	UINT		clientWidth;
	UINT		clientHeight;
	LPCWSTR		appTitle;
	DWORD		wndStyle;

	// DirectX 11 ��� ����.
	ID3D11Device*			pDevice;			// ������ ���� �ٸ� ���� ����.
	ID3D11DeviceContext*	pDeviceContext;		// ������ ����.
	IDXGISwapChain*			pSwapChain;			// ���� ü��.
	ID3D11RenderTargetView* pRenderTargetView;	// ���� Ÿ��.

	ID3D11Buffer*		vertexBuffer;			// ���� ����.
	ID3D11VertexShader* vertexShader;			// ���� ���̴�(���̴�).
	ID3D11PixelShader*  pixelShader;			// �ȼ� ���̴�.
	ID3DBlob*			vertexShaderBuffer;		// ���� ���̴� ����.
	ID3DBlob*			pixelShaderBuffer;		// �ȼ� ���̴� ����.
	ID3D11InputLayout*	vertexInputLayout;		// ���� �Է� ���̾ƿ�.

	ID3D11Buffer*		indexBuffer;			// �ε��� ����.

	// ���� ��ȯ ���.
	XMMATRIX world;
	XMMATRIX view;
	XMMATRIX projection;

	// ����� ���� �� �ʿ��� ��.
	XMVECTOR cameraPos;
	XMVECTOR cameraTarget;
	XMVECTOR cameraUp;

	// ��� ����.
	ID3D11Buffer* cbBuffer;

protected:

	// Win32 �޼ҵ�. 
	// ������ �ʱ�ȭ.
	bool InitWindow();

	// DirectX �ʱ�ȭ.
	bool InitDirect3D();

	// ��� �ʱ�ȭ.
	bool InitScene();
};