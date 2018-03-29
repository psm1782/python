#include "Spreadsheet.h"
Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp, int inWidth, int inHeight) :
	mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth),
	mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight), mTheApp(theApp)
{
	mId = sCounter++;
	mCells = new SpreadsheetCell* [mWidth];
	for (int i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::~Spreadsheet()
{
	for (int i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	mCells[x][y] = cell;
}
SpreadsheetCell& Spreadsheet::getCellAt(int x, int y)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	mCells[x][y];
}

void Spreadsheet::copyFrom(const Spreadsheet& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
	for (int i = 0; i < mWidth; i++) {
		for (int j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : mTheApp(src.mTheApp)
{
	mId = sCounter++;
	copyFrom(src);
}
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	//자기 자신을 대입하는지 검사
	if (this == &rhs) {
		return *this;
	}
	// 기존에 사용하던 메모리 반환
	for (int i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
	//새로운 값으로 복제
	copyFrom(rhs);
	return *this;
}