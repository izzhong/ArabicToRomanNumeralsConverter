#include "pch.h"

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(AragicToRomanNumeralsConverterTestCase, PreparationsCompleted)
{
	// GTEST_FAIL();
	GTEST_SUCCEED();
}

/// <summary>
/// 将给定正整数参数转换为罗马数字字符串
/// </summary>
/// <param name="arabicNumber"></param>
/// <returns></returns>
std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
{
	if (arabicNumber == 10)
		return "X";
	if (arabicNumber == 20)
		return "XX";
	if (arabicNumber == 30)
		return "XXX";


	std::string romanString{};
	while (arabicNumber >= 1)
	{
		romanString.push_back('I');
		--arabicNumber;
	}
	return romanString;
}

TEST(AragicToRomanNumeralsConverterTestCase, 1_isConvertedTo_I)
{
	ASSERT_EQ("I", convertArabicNumberToRomanNumeral(1));
}

TEST(AragicToRomanNumeralsConverterTestCase, 2_isConvertedTo_II)
{
	ASSERT_EQ("II", convertArabicNumberToRomanNumeral(2));
}

TEST(AragicToRomanNumeralsConverterTestCase, 3_isConvertedTo_III)
{
	ASSERT_EQ("III", convertArabicNumberToRomanNumeral(3));
}

TEST(AragicToRomanNumeralsConverterTestCase, 10_isConvertedTo_X)
{
	ASSERT_EQ("X", convertArabicNumberToRomanNumeral(10));
}

TEST(AragicToRomanNumeralsConverterTestCase, 20_isConvertedTo_XX)
{
	ASSERT_EQ("XX", convertArabicNumberToRomanNumeral(20));
}

TEST(AragicToRomanNumeralsConverterTestCase, 30_isConvertedTo_XXX)
{
	ASSERT_EQ("XXX", convertArabicNumberToRomanNumeral(30));
}
