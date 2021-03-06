#pragma once

class CPlaceable
{
public:
	// disable allocation
	static void *operator new(size_t) = delete;

	CMatrix m_matrix;

	CPlaceable(void);
	virtual ~CPlaceable(void);
	CVector &GetPosition(void) { return m_matrix.GetPosition(); }
	CVector &GetRight(void) { return m_matrix.GetRight(); }
	CVector &GetForward(void) { return m_matrix.GetForward(); }
	CVector &GetUp(void) { return m_matrix.GetUp(); }
	CMatrix &GetMatrix(void) { return m_matrix; }
	void SetTransform(RwMatrix *m) { m_matrix = CMatrix(m, false); }
	void SetHeading(float angle);
	void SetOrientation(float x, float y, float z){
		CVector pos = m_matrix.GetPosition();
		m_matrix.SetRotate(x, y, z);
		m_matrix.Translate(pos);
	}
	bool IsWithinArea(float x1, float y1, float x2, float y2);
	bool IsWithinArea(float x1, float y1, float z1, float x2, float y2, float z2);
};
static_assert(sizeof(CPlaceable) == 0x4C, "CPlaceable: error");