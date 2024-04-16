
// ShapeMFCDoc.cpp: CShapeMFCDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ShapeMFC.h"
#endif

#include "ShapeMFCDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CShapeMFCDoc

IMPLEMENT_DYNCREATE(CShapeMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CShapeMFCDoc, CDocument)
END_MESSAGE_MAP()


// CShapeMFCDoc 构造/析构

CShapeMFCDoc::CShapeMFCDoc() : m_circle(CP_Point(100, 100), 50), m_square(CP_Point(100, 100), 100), m_triangle(CP_Point(100, 100), 50 * sqrt(3))
{
	// TODO: 在此添加一次性构造代码

}

CShapeMFCDoc::~CShapeMFCDoc()
{
}

BOOL CShapeMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CShapeMFCDoc 序列化

void CShapeMFCDoc::Serialize(CArchive& ar)
{
	int flag;
	CString cs;
	wchar_t* buf;
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		cs.Format(_T("#Circle begin\n"));
		ar.WriteString(cs);
		cs.Format(_T("%g,%g,%g\n"), m_circle.m_center.m_x, m_circle.m_center.m_y, m_circle.m_radius);
		ar.WriteString(cs);
		cs.Format(_T("#Circle end\n"));
		ar.WriteString(cs);

		cs.Format(_T("#Square begin\n"));
		ar.WriteString(cs);
		cs.Format(_T("%g,%g,%g\n"), m_square.m_center.m_x, m_square.m_center.m_y, m_square.m_side_length);
		ar.WriteString(cs);
		cs.Format(_T("#Square end\n"));
		ar.WriteString(cs);

		cs.Format(_T("#Triangle begin\n"));
		ar.WriteString(cs);
		cs.Format(_T("%g,%g,%g\n"), m_triangle.m_center.m_x, m_triangle.m_center.m_y, m_triangle.m_side_length);
		ar.WriteString(cs);
		cs.Format(_T("#Triangle end\n"));
		ar.WriteString(cs);
	}
	else
	{
		// TODO: 在此添加加载代码
		flag = 0;
		while (ar.ReadString(cs)) {
			cs.Trim();
			if (flag == 0) {
				if (cs.CompareNoCase(_T("#Circle begin")) == 0)
					flag = 1;
				if (cs.CompareNoCase(_T("#Square begin")) == 0)
					flag = 2;
				if (cs.CompareNoCase(_T("#Triangle begin")) == 0)
					flag = 3;
			}
			else if (flag == 1) {
				buf = cs.GetBuffer();
				swscanf_s(buf, _T("%lf,%lf,%lf"), &(m_circle.m_center.m_x), &(m_circle.m_center.m_y), &(m_circle.m_radius));
			}
			else if (flag == 2) {
				buf = cs.GetBuffer();
				swscanf_s(buf, _T("%lf,%lf,%lf"), &(m_square.m_center.m_x), &(m_square.m_center.m_y), &(m_square.m_side_length));
			}
			else if (flag == 3) {
				buf = cs.GetBuffer();
				swscanf_s(buf, _T("%lf,%lf,%lf"), &(m_triangle.m_center.m_x), &(m_triangle.m_center.m_y), &(m_triangle.m_side_length));
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CShapeMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CShapeMFCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CShapeMFCDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CShapeMFCDoc 诊断

#ifdef _DEBUG
void CShapeMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShapeMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CShapeMFCDoc 命令
