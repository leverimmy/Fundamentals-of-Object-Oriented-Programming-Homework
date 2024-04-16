
// ShapeMFCDoc.h: CShapeMFCDoc 类的接口
//


#pragma once
#include "CP_Circle.h"
#include "CP_Square.h"
#include "CP_Triangle.h"

class CShapeMFCDoc : public CDocument
{
protected: // 仅从序列化创建
	CShapeMFCDoc();
	DECLARE_DYNCREATE(CShapeMFCDoc)

// 特性
public:
	CP_Circle m_circle;
	CP_Square m_square;
	CP_Triangle m_triangle;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CShapeMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
