#pragma once
#include "SpreadsheetCell.h"

class SpreadsheetApplication;	// 포워드 선언
class Spreadsheet
{
public:
	Spreadsheet(const SpreadsheetApplication& theApp, int inWidth = kMaxWidth, int inheight = kMaxHeight);
	~Spreadsheet();
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet& operator=(const Spreadsheet& rhs);
	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
	void copyFrom(const Spreadsheet& src);
	int getId() const;
	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;
private:
	bool inRange(int val, int upper);
	int mWidth, mHeight;
	SpreadsheetCell** mCells;
	static int sCounter;
	int mId;
	const SpreadsheetApplication& mTheApp;
};