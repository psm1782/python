#pragma once
#include <string>
#include <initializer_list>
#include <iostream>
#include <vector>
#include "Spreadsheet.h"

using namespace std;
class Spreadsheet;
class SpreadsheetCell
{
public:
	friend void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell);
	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	SpreadsheetCell(const SpreadsheetCell& src);
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(const std::string& initialValue);
	void setValue(double inValue);
	double getValue() const { mNumAccesses++; return mValue; }
	const std::string& getString() const { mNumAccesses++; return mString; }
	void setString(const std::string& inString);
	const std::string& getString() const;
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	double getValue() const;
	const std::string& getString() const;
	void set(double inValue);
	void set(const std::string& inString);
	enum class Colors { Red = 1, Green, Blue, Yellow };
	void setColor(Colors color);
	SpreadsheetCell operator+(const SpreadsheetCell& cell) const;
private:
	static std::string doubleToString(double val);
	static double stringToDouble(const std::string& str);
	double mValue;
	std::string mString;
	mutable int mNumAccesses = 0;
	Colors mColor = Colors::Red;
};

class EvenSequence
{
public:
	EvenSequence(initializer_list<double> args)
	{
		if (args.size() % 2 != 0) {
			throw invalid_argument("initializer_list should contain even number of elements.");
		}
		mSequence.reserve(args.size());
		for (auto value : args) {
			mSequence.push_back(value);
		}
	}
	void dump() const
	{
		for (auto value : mSequence) {
			cout << value << ", ";
		}
		cout << endl;
	}
private:
	vector<double> mSequence;
};