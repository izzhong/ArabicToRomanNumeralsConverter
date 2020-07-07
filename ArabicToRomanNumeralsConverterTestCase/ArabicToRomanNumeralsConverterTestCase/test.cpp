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
/// ����������������ת��Ϊ���������ַ���
/// </summary>
/// <param name="arabicNumber"></param>
/// <returns></returns>
std::string convertArabicNumberToRomanNumeral(const unsigned int arabicNumber)
{
	return "I";
}

TEST(AragicToRomanNumeralsConverterTestCase, 1_isConvertedTo_I)
{
	ASSERT_EQ("I", convertArabicNumberToRomanNumeral(1));
}
