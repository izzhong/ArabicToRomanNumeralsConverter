#pragma once

#include "pch.h"
#include "convert_arabic_to_roman.h"

class RomanNumeralAssert
{
public:
	RomanNumeralAssert() = delete;
	explicit RomanNumeralAssert(const unsigned int arabicNumber) :
		arabicNumberToConvert(arabicNumber) {}
	void isConvertedToRomanNumeral(const std::string& expectedRomanNumeral) const
	{
		ASSERT_EQ(expectedRomanNumeral, convertArabicNumberToRomanNumeral(arabicNumberToConvert));
	}
private:
	const unsigned int arabicNumberToConvert;
};

RomanNumeralAssert assertThat(const unsigned int arabicNumber)
{
	return RomanNumeralAssert{ arabicNumber };
}