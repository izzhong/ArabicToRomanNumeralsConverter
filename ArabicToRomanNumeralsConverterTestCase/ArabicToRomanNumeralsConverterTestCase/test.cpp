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
	//if (arabicNumber == 2)
	//	return "II";
	//if (arabicNumber == 3)
	//	return "III";
	//return "I";
	// 有了100%覆盖的测试，我们可以放心的大胆的进行重构
	// 因为输入只有123，所以我们可以仅考虑这几种情况
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
