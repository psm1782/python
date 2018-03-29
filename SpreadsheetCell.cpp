#include "SpreadsheetCell.h"
#include <iostream>
#include <sstream>
using namespace std;

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) :
	mValue(src.mValue), mString(src.mString)
{
}
SpreadsheetCell::SpreadsheetCell()
{
	mValue = 0;
}
SpreadsheetCell::SpreadsheetCell(double initialValue)
{
	setValue(initialValue);
}
SpreadsheetCell::SpreadsheetCell(const string& initialValue)
{
	setString(initialValue);
}
void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
	mString = doubleToString(mValue);
}
inline double SpreadsheetCell::getValue() const
{
	mNumAccesses++;
	return mValue;
}
void SpreadsheetCell::set(const string& inString)
{
	mString = inString;
	mValue = stringToDouble(mString);
}
inline const string& SpreadsheetCell::getString() const
{
	mNumAccesses++;
	return mString;
}
string SpreadsheetCell::doubleToString(double inValue)
{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}
double SpreadsheetCell::stringToDouble(const string& inString)
{
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof()) {
		return 0;
	}
	return temp;
}
SpreadsheetCell& SpreadsheetCell::operator = (const SpreadsheetCell& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	mValue = rhs.mValue;
	mString = rhs.mString;
	return *this;
}

void SpreadsheetCell::setColor(Colors color)
{
	mColor = color;
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const
{
	SpreadsheetCell newCell;
	newCell.set(mValue + cell.mValue);	// mValue와 mString 멤버를 업데이트한다.
	return newCell;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue + rhs.mValue);	// mValue와 mString 멤버를 업데이트한다.
	return newCell;
}



SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue * rhs.mValue);	//mValue와 mString 멤버 업데이트
	return newCell;
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue / rhs.mValue);	//mValue와 mString 멤버 업데이트
	return newCell;
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue - rhs.mValue);	//mValue와 mString 멤버 업데이트
	return newCell;
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(mValue + rhs.mValue);		//set()을 호출하여 mValue와 mString을 업데이트한다.
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(mValue = rhs.mValue);		//set()을 호출하여 mValue와 mString을 업데이트한다.
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(mValue * rhs.mValue);		//set()을 호출하여 mValue와 mString을 업데이트한다.
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	set(mValue / rhs.mValue);		//set()을 호출하여 mValue와 mString을 업데이트한다.
	return *this;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.mValue == rhs.mValue);
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.mValue < rhs.mValue);
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.mValue > rhs.mValue);
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.mValue != rhs.mValue);
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.mValue <= rhs.mValue);
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.mValue >= rhs.mValue);
}