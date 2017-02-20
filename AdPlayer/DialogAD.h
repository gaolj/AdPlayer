#pragma once
#include "Resource.h"
#include "explorer1.h"
#include "Resource.h"


// CDialogAD 对话框

class CDialogAD : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAD)

public:
	CDialogAD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogAD();

// 对话框数据
	enum { IDD = IDD_DIALOG_AD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
