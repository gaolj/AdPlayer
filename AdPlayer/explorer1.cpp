// ������������� Microsoft Visual C++ ������ IDispatch ��װ��

// ע��: ��Ҫ�޸Ĵ��ļ������ݡ����������
//  Microsoft Visual C++ �������ɣ������޸Ľ������ǡ�


#include "stdafx.h"
#include "explorer1.h"

/////////////////////////////////////////////////////////////////////////////
// CExplorer1

IMPLEMENT_DYNCREATE(CExplorer1, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CExplorer1 ����

/////////////////////////////////////////////////////////////////////////////
// CExplorer1 ����
BOOL CExplorer1::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (WM_MOUSEFIRST == pMsg->message) return TRUE;
	else if (WM_MOUSEMOVE == pMsg->message) return TRUE;
	else if (WM_RBUTTONDOWN == pMsg->message) return TRUE;
	else if (WM_RBUTTONDBLCLK == pMsg->message) return TRUE;
	else if (WM_RBUTTONUP == pMsg->message) return TRUE;
	else if (WM_MBUTTONDOWN == pMsg->message) return TRUE;
	else if (WM_MBUTTONUP == pMsg->message) return TRUE;
	else if (WM_MBUTTONDBLCLK == pMsg->message) return TRUE;
	else if (WM_LBUTTONDOWN == pMsg->message)
	{ // ���
		this->GetParent()->PostMessageA(WM_CLOSE);
		return TRUE;
	}

	return CWnd::PreTranslateMessage(pMsg);
}
