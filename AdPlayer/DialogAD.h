#pragma once
#include "Resource.h"
#include "explorer1.h"
#include "Resource.h"


// CDialogAD �Ի���

class CDialogAD : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAD)

public:
	CDialogAD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogAD();

// �Ի�������
	enum { IDD = IDD_DIALOG_AD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 m_ie;


	virtual BOOL OnInitDialog();
	//void DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
