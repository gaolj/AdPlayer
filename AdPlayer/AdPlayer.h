// AdPlayer.h : AdPlayer DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAdPlayerApp
// �йش���ʵ�ֵ���Ϣ������� AdPlayer.cpp
//

class CAdPlayerApp : public CWinApp
{
public:
	CAdPlayerApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
