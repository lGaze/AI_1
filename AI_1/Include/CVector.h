#pragma once
#include "math.h"

class CVector
{
public:

	CVector();
	~CVector();
	
	/**
	 * Set X Value.
	 */
	void setValueX(float x);
	/**
	 * Set Y Value.
	 */
	void setValueY(float y);
	/**
	 * Return X Value.
	 */
	float getValueX();
	/**
	 * Return Y Value.
	 */
	float getValueY();
	/**
	 * Returns the magnitude of a Vector.
	 */
	float magnitude();
	/**
	 * Returns a normalized Vector.
	 */
	CVector normalize();
	/**
	 * Overload operator -
	 */
	CVector operator-(CVector val);
	/**
	 * Overload operator *
	 */
	CVector operator*(float val);

private:

	float m_X;
	float m_Y;
};
