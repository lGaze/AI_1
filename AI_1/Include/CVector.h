#pragma once
#include "math.h"

class CVector
{
public:

	CVector();
	CVector(float x, float y);
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
	CVector operator-(const CVector & val);
	/**
	 * Overload operator *
	 */
	CVector operator*(float val);
	/**
	 * Overload operator +
	 */
	CVector operator+(const CVector & vall);
	public:

	float m_X;
	float m_Y;
};
