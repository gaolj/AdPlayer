#pragma once


// CDialogNotice �Ի���
class CPlayer;
class CDialogNotice : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogNotice)

public:
	CDialogNotice(CWnd* pParent = NULL,CPlayer* play = NULL);   // ��׼���캯��
	virtual ~CDialogNotice();

// �Ի�������
	enum { IDD = IDD_DIALOG_NOTICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnUserThreadend(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserPlayComplete(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowAd(WPARAM wParam, LPARAM lParam);

private:
	CPlayer *_play;
};
