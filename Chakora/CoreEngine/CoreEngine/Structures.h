#ifndef ENGINESTRUCTURES_H_INCLUDED
#define ENGINESTRUCTURES_H_INCLUDED

#include <string>
#include <math.h>
#include <string>
#include <stdio.h>
#include <iostream>

template <class T>
class Point {

public:
	T x;
	T y;
	T z;
	T w;

public:
	/* Default constructor (0,0,0,1) */
	Point();

	/* Create a point at (x,y,z,1) */
	Point(T x, T y, T z);

	/* Create a point at (x,y,z,w). */
	Point(T x, T y, T z, T w);

	/* Copy Constructor */
	Point(const Point &other);

	/* Assignment operator */
	Point& operator=(const Point &rhs);

	/* Equality operator */
	bool operator==(const Point<T> &other) const;

	/* Inequality operator */
	bool operator!=(const Point<T> &other) const;

	/* Calculate the distance between the current point to
	* the given point.
	*/
	T distance(const Point &other) const;

	/* Transform the point by the given matrix (homogenous)*/
	void transform(T matrix[4][4]);

	/* Set point to a new location (x,y,z,w). */
	void setPoint(T x, T y, T z, T w);

	/**
	* Display a point
	*/
	friend std::ostream & operator<<(std::ostream &os, const Point &point) {
		return os << "Point: (" << point.x << ", " << point.y << ", " << point.z << ", " << point.w << ")";
	}
};


/* Create a point at (0.0, 0.0, 0.0, 1.0 ) */
template <class T> Point<T>::Point() {
	setPoint(0.0, 0.0, 0.0, 1.0);
}

/* Create a point at (x,y,z,1) */
template <class T> Point<T>::Point(T x, T y, T z) {
	setPoint(x, y, z, 1.0);
}

/* Create a point at (x,y,z,w) */
template <class T> Point<T>::Point(T x, T y, T z, T w) {
	setPoint(x, y, z, w);
}

template <class T> Point<T>::Point(const Point &other) {
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

template <class T> Point<T>& Point<T>::operator=(const Point &rhs) {
	// Check for self-assignment
	if (this == &rhs)
		return *this;        // skip and return this

	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return *this;
}

template <class T> bool Point<T>::operator==(const Point<T> &other) const {
	if (x == other.x && y == other.y && z == other.z && w == other.w) {
		return true;
	}
	return false;
}

template <class T> bool Point<T>::operator!=(const Point<T> &other) const {
	return !(*this == other);
}

/* Calculate the distance between this point and a given point */
template <class T> T Point<T>::distance(const Point &other) const {
	return sqrt((other.x - x)*(other.x - x) +
		(other.y - y)*(other.y - y) +
		(other.z - z)*(other.z - z));
}

/* Transform the point by a given amount (x,y,z). */
template <class T> void Point<T>::transform(T matrix[4][4]) {
	// Matrix multiplication
	T value[] = { 0, 0, 0, 1 };
	value[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3] * w;
	value[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3] * w;
	value[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3] * w;

	x = value[0];
	y = value[1];
	z = value[2];
	w = 1.0;
}

/* Set the point to a new position */
template <class T> void Point<T>::setPoint(T x, T y, T z, T w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

template <class T>
class CoreVector3D {

public: 
	T x;
	T y;
	T z;

public:

	/* Create a vector with (0,0,0) */
	CoreVector3D();

	/* Create a vector with (x,y,z) */
	CoreVector3D(T x, T y, T z);

	CoreVector3D(const CoreVector3D &other);

	/* Creates a vector from two points */
	CoreVector3D(Point<T> p1, Point<T> p2);

	/* Addition of vectors */
	CoreVector3D<T> operator+(const CoreVector3D<T> &other) const;

	/* Subtraction of vectors */
	CoreVector3D<T> operator-(const CoreVector3D<T> &other) const;

	/* Comparison operator */
	bool operator==(const CoreVector3D<T> &other) const;

	/* Scale the vector */
	CoreVector3D<T> operator*(T scaleFactor) const;

	CoreVector3D<T> operator/(T scaleFactor) const;

	/* CoreVector3D Assignment */
	CoreVector3D<T> &operator=(const CoreVector3D<T> &other);

	/* Compute the dot product of two vectors */
	T dot(const CoreVector3D<T> &v1) const;

	/* Compute the dot product between a vector and a point */
	T dot(Point<T> p1) const;

	/* Computer the cross product of two vectors */
	CoreVector3D cross(const CoreVector3D<T> &v1) const;

	/* Compute the length of a vector */
	T length() const;

	/* Normalize the vector */
	void normalize();

	/* Reverse the direction of the vector */
	void reverse();

	CoreVector3D<T> reflect(const CoreVector3D<T> &source, const CoreVector3D<T> &normal);

	/* Transform (ROTATE) the vector by a given matrix */
	void transform(T matrix[4][4]);

	/* Set the vector to (x,y,z) components */
	void setCoreVector3D(T x, T y, T z);

	/* Set the vector between points p1 and p2 */
	void setCoreVector3D(const Point<T> &p1, const Point<T> &p2);

	/* Set the vector given another vector */
	void setCoreVector3D(const CoreVector3D<T> &other);

	/* Set the vector to (0,0,0) */
	void zero();

	/* Display a CoreVector3D */
	friend std::ostream & operator<<(std::ostream &os, const CoreVector3D<T> &v) {
		os << "CoreVector3D: (" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}

};

template <class T> CoreVector3D<T>::CoreVector3D()
	: x(0), y(0), z(0) {
}

template <class T> CoreVector3D<T>::CoreVector3D(T vx, T vy, T vz)
	: x(vx), y(vy), z(vz) {
}

template <class T> CoreVector3D<T>::CoreVector3D(const CoreVector3D<T> &v)
	: x(v.x), y(v.y), z(v.z) {
}

template <class T> CoreVector3D<T>::CoreVector3D(Point<T> p1, Point<T> p2) {
	setCoreVector3D((p1.x - p2.x), (p1.y - p2.y), (p1.z - p2.z));
}

template <class T> CoreVector3D<T> CoreVector3D<T>::operator+(const CoreVector3D<T> &other) const {
	CoreVector3D<T> result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;
	result.z = this->z + other.z;
	return result;
}

template <class T> CoreVector3D<T> CoreVector3D<T>::operator-(const CoreVector3D<T> &other) const {
	CoreVector3D<T> result;
	result.x = this->x - other.x;
	result.y = this->y - other.y;
	result.z = this->z - other.z;
	return result;
}

template <class T> bool CoreVector3D<T>::operator==(const CoreVector3D<T> &other) const {
	return (this->x == other.x && this->y == other.y &&
		this->z == other.z);
}

template <class T> CoreVector3D<T> CoreVector3D<T>::operator*(T scaleFactor) const {
	CoreVector3D<T> result(*this);
	result.x *= scaleFactor;
	result.y *= scaleFactor;
	result.z *= scaleFactor;
	return result;
}

template <class T> CoreVector3D<T> CoreVector3D<T>::operator/(T rhs) const {
	CoreVector3D<T> result(*this);
	result.x /= rhs;
	result.y /= rhs;
	result.z /= rhs;
	return result;
}

template <class T> CoreVector3D<T> &CoreVector3D<T>::operator=(const CoreVector3D<T> &other) {
	if (this == &other) {
		return *this;
	}
	setCoreVector3D(other.x, other.y, other.z);
	return *this;
}

template <class T> T CoreVector3D<T>::dot(const CoreVector3D<T> &v1) const {
	return  (x * v1.x + y * v1.y + z * v1.z);
}

template <class T> T CoreVector3D<T>::dot(Point<T> p1) const {
	return (x * p1.x + y * p1.y + z * p1.z);
}

template <class T> CoreVector3D<T> CoreVector3D<T>::cross(const CoreVector3D<T> &v1) const {
	CoreVector3D<T> result;
	result.x = (y * v1.z - z * v1.y);
	result.y = -(x * v1.z - z * v1.x);
	result.z = (x * v1.y - y * v1.x);
	return result;
}

template <class T> T CoreVector3D<T>::length() const {
	return sqrt(x*x + y * y + z * z);
}

template <class T> void CoreVector3D<T>::normalize() {
	T length = this->length(); /* Compute the magnitude */

	if (length != 0) { /* Prevent divide by zero */
		x /= length;
		y /= length;
		z /= length;
	}
	else {
		//printf( "VECTOR DIVIDE BY ZERO ERROR\n" );
	}
}

template <class T> void CoreVector3D<T>::reverse() {
	x = -x;
	y = -y;
	z = -z;
}

template <class T> CoreVector3D<T> CoreVector3D<T>::reflect(const CoreVector3D<T> &source, const CoreVector3D<T> &normal) {
	CoreVector3D<T> result = (normal * (2.0 * source.dot(normal)));
	result = source - result;
	result.normalize();
	return result;
}

template <class T> void CoreVector3D<T>::transform(T matrix[4][4]) {
	T value[] = { 0, 0, 0 };
	value[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
	value[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
	value[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
	x = value[0];
	y = value[1];
	z = value[2];
}

template <class T> void CoreVector3D<T>::setCoreVector3D(T x, T y, T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

template <class T> void CoreVector3D<T>::setCoreVector3D(const Point<T> &p1, const Point<T> &p2) {
	setCoreVector3D((p1.x - p2.x), (p1.y - p2.y), (p1.z - p2.z), 1.0f);
}

template <class T> void CoreVector3D<T>::setCoreVector3D(const CoreVector3D<T> &other) {
	setCoreVector3D(other.x, other.y, other.z);
}

template <class T> void CoreVector3D<T>::zero() {
	setCoreVector3D(0.0, 0.0, 0.0);
}

class CColor
{
private:
	int R;
	int G;
	int B;
public:
	CColor(int r, int g, int b)
	{
		try
		{
			if (r > 255 or g > 255 or b > 255)
				throw 1;
			if (r < 0 or g < 0 or b < 0)
				throw 2;
			R = r;
			G = g;
			B = b;
			std::cout << R << ' ' << G << ' ' << B << std::endl;
		}
		catch (int ex)
		{
			switch (ex)
			{
			case 1:
				std::cout << ex << ". Incorect Color Value(over 255)";
				break;
			case 2:
				std::cout << ex << ". Incorect Color Value(negative)";
				break;
			}
		}
	}
	CColor(double r, double g, double b)
	{
		try
		{
			if (r > 1 or g > 1 or b > 1)
				throw 1;
			if (r < 0 or g < 0 or b < 0)
				throw 2;
			R = floor(255 * r);
			G = floor(255 * g);
			B = floor(255 * b);
		}
		catch (int ex)
		{
			switch (ex)
			{
			case 1:
				std::cout << ex << ". Incorect Color Value(over 255)";
				break;
			case 2:
				std::cout << ex << ". Incorect Color Value(negative)";
				break;
			}

		}
	}
	CColor(std::string color)
	{
		try
		{
			if (color == "red") {
				R = 255;
				G = 0;
				B = 0;
			}
			else if (color == "yellow") {
				R = 255;
				G = 255;
				B = 0;
			}
			else if (color == "blue") {
				R = 0;
				G = 0;
				B = 255;
			}
			else if (color == "black") {
				R = 0;
				G = 0;
				B = 0;
			}
			else if (color == "white") {
				R = 255;
				G = 255;
				B = 255;
			}
			else if (color == "green") {
				R = 0;
				G = 255;
				B = 0;
			}
			else if (color == "purple") {
				R = 153;
				G = 51;
				B = 255;
			}
			else if (color == "pink") {
				R = 255;
				G = 51;
				B = 255;
			}
			else if (color == "orange") {
				R = 255;
				G = 153;
				B = 51;
			}
			else {
				if (color[0] == '#') {
					color = color.substr(1, 6);
				}

				const char *r = color.substr(0, 2).c_str();
				const char *g = color.substr(2, 2).c_str();
				const char *b = color.substr(4, 2).c_str();
				char * pEnd;

				R = strtol(r, &pEnd, 16);
				G = strtol(g, &pEnd, 16);
				B = strtol(b, &pEnd, 16);
			}

		}
		catch (int ex)
		{
			switch (ex)
			{
			case 0:
				std::cout << ex << ". Incorect Color Value(over 255)";
				break;
			}

		}
	}
	void Darker(double percent) {
		percent = 1 - percent;
		R = (R*percent >= 0 ? R * percent : 0);
		G = (G*percent >= 0 ? G * percent : 0);
		B = (B*percent >= 0 ? B * percent : 0);
	}

	void Lighten(double percent) {
		percent = 1 + percent;
		R = (R*percent <= 255 ? R * percent : 255);
		G = (G*percent <= 255 ? G * percent : 255);
		B = (B*percent <= 255 ? B * percent : 255);
	}

	float ReturnColorRF()
	{
		return R/255.0;
	}

	float ReturnColorGF()
	{
		return G/255.0;
	}

	float ReturnColorBF()
	{
		return B/255.0;
	}
};

typedef CoreVector3D<float> CVector;

#endif // ENGINESTRUCTURES_H_INCLUDED
