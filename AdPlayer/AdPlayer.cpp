// AdPlayer.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AdPlayer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CAdPlayerApp

BEGIN_MESSAGE_MAP(CAdPlayerApp, CWinApp)
END_MESSAGE_MAP()


// CAdPlayerApp ����

CAdPlayerApp::CAdPlayerApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAdPlayerApp ����

CAdPlayerApp theApp;


// CAdPlayerApp ��ʼ��

BOOL CAdPlayerApp::InitInstance()
{


	CoInitialize(NULL);

// 	HRESULT hr = OleInitialize(NULL);
// 	if (hr == S_FALSE) {
// 		OleUninitialize();
// 	}else{
// 		if (hr == S_OK) {
// 			AfxMessageBox("OLE needs to be initialized in the Client Application before using this DLL");
// 		}else{
// 			AfxMessageBox("There is a problem with initializing OLE");
// 		}
// 		return FALSE;
// 	}
// #endif

	// Call if using OLE Controls
	AfxEnableControlContainer();

	// Register all OLE server (factories) as running. This enables the
	// OLE libraries to create objects from other applications.
	COleObjectFactory::RegisterAll();

	CWinApp::InitInstance();
	return TRUE;
}
