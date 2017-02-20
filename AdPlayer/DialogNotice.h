#pragma once


// CDialogNotice 对话框
class CPlayer;
class CDialogNotice : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogNotice)

public:
	CDialogNotice(CWnd* pParent = NULL,CPlayer* play = NULL);   // 标准构造函数
	virtual ~CDialogNotice();

// 对话框数据
	enum { IDD = IDD_DIALOG_NOTICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnUserThreadend(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserPlayComplete(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowAd(WPARAM wParam, LPARAM lParam);

private:
	CPlayer *_play;
};
