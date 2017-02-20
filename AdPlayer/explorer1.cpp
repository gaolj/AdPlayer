// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。


#include "stdafx.h"
#include "explorer1.h"

/////////////////////////////////////////////////////////////////////////////
// CExplorer1

IMPLEMENT_DYNCREATE(CExplorer1, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CExplorer1 属性

/////////////////////////////////////////////////////////////////////////////
// CExplorer1 操作
BOOL CExplorer1::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (WM_MOUSEFIRST == pMsg->message) return TRUE;
	else if (WM_MOUSEMOVE == pMsg->message) return TRUE;
	else if (WM_RBUTTONDOWN == pMsg->message) return TRUE;
	else if (WM_RBUTTONDBLCLK == pMsg->message) return TRUE;
	else if (WM_RBUTTONUP == pMsg->message) return TRUE;
	else if (WM_MBUTTONDOWN == pMsg->message) return TRUE;
	else if (WM_MBUTTONUP == pMsg->message) return TRUE;
	else if (WM_MBUTTONDBLCLK == pMsg->message) return TRUE;
	else if (WM_LBUTTONDOWN == pMsg->message)
	{ // 左键
		this->GetParent()->PostMessageA(WM_CLOSE);
		return TRUE;
	}

	return CWnd::PreTranslateMessage(pMsg);
}
