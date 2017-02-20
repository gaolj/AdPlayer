#pragma once
#include "Resource.h"


// CDialogDemo 对话框

class CDialogDemo : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogDemo)

public:
	CDialogDemo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogDemo();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
