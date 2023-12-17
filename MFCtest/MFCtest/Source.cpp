#include<afxwin.h>
#include<afxext.h>
#include "resource.h"
class CMyView :CView
{
public:
	void OnDraw(CDC* pDC);
	afx_msg void OnCommand();
	
DECLARE_DYNCREATE(CMyView)
DECLARE_MESSAGE_MAP()

};
IMPLEMENT_DYNCREATE(CMyView,CView)
BEGIN_MESSAGE_MAP(CMyView, CView)
ON_COMMAND(ID_NEW_TEST,OnCommand)
END_MESSAGE_MAP()

void CMyView::OnCommand()
{
	AfxMessageBox("Menu has been clicked and process by view");
}
void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut(100,100,"This is From View");
}
class CMyDoc :public CDocument
{



};

class CMyframe :public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT);
	afx_msg void OnPaint();
};
BEGIN_MESSAGE_MAP(CMyframe, CFrameWnd)
	ON_WM_CREATE(WM_CREATE,OnCreate)
	ON_WM_PAINT()
END_MESSAGE_MAP()
int CMyframe::OnCreate(LPCREATESTRUCT lpc)
{
	//CMyView* pView = new CMyView();
	
	//AfxMessageBox("My Frame was Created!")
	return CFrameWnd::OnCreate(lpc);
}
void CMyframe::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CFont font;
	font.CreatePointFont(720, "Î¢ÈíÑÅºÚ");
	dc.SelectObject(&font);
	dc.SetTextColor(RGB(0, 255, 0));
	dc.DrawText("Hello MFC", &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}

class CMyApp:public CWinApp
{
public:
	BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	CMyframe* pFrame = new CMyframe();
	CMyDoc* pDoc = new CMyDoc();

	CCreateContext cct;
	cct.m_pCurrentDoc = pDoc;
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);//
//	pFrame->Create(NULL,"MyMFC");
	pFrame->LoadFrame(IDR_MENU1, WS_OVERLAPPEDWINDOW, NULL, &cct);
	//pFrame->SetActiveView((CMyView*)cct.m_pNewViewClass);
	m_pMainWnd = pFrame; 
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
CMyApp theApp;


