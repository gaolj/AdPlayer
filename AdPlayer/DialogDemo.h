#pragma once
#include "Resource.h"


// CDialogDemo �Ի���

class CDialogDemo : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogDemo)

public:
	CDialogDemo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogDemo();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
