#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <iostream>
#include <immintrin.h>
#include <stdio.h>

#define USE_SIMD

class Vec3
{
public:
#ifdef USE_SIMD:
	__m128 sseVector;
#else
	float x, y, z;
#endif

	Vec3(float x, float y, float z);
	Vec3(__m128);

	Vec3 operator+(const Vec3& other);
	void operator+=(const Vec3& other);
	Vec3 operator-(const Vec3& other);
	void operator-=(const Vec3& other);
	Vec3 operator*(const float scale);   // multiple vector by scalar
	float operator*(const Vec3& other);  // dot product

	float dot(const Vec3& other);

	float magnitudeSquared();

	float magnitude();

	Vec3 normalized();

	float getX(); // This one is fine
	float getY(); // These might not be optimal in SIMD
	float getZ(); // But shouldn't be called too much anyway

	void setX(float x);  // These are also also a bit slow in SIMD
	void setY(float y);  // And also shouldn't be neccesary too often
	void setZ(float z);

	static bool usingSimd();

	Vec3() = default;
};

#endif