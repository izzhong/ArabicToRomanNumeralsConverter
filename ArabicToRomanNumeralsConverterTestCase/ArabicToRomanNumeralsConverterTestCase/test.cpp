#include "pch.h"
#include "roman_numeral_assert.h"

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


// 观察这些测试，他们冗余非常高，重复且不优雅
// 测试代码也应该被重构
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

// 重构测试
TEST(AragicToRomanNumeralsConverterTestCase, 33_isConvertedTo_XXXIII)
{
	// ASSERT_EQ("XXXIII", convertArabicNumberToRomanNumeral(33));
	// 使用一个自定义的测试
	assertThat(33).isConvertedToRomanNumeral("XXXIII");
}

// 整合测试
TEST(AragicToRomanNumeralsConverterTestCase, conversionOfArabicNumbersToRomanNumerals_Works)
{
	assertThat(33).isConvertedToRomanNumeral("XXXIII");
	assertThat(100).isConvertedToRomanNumeral("C");
	assertThat(200).isConvertedToRomanNumeral("CC");
	assertThat(300).isConvertedToRomanNumeral("CCC");
	assertThat(1000).isConvertedToRomanNumeral("M");
	assertThat(2000).isConvertedToRomanNumeral("MM");
	assertThat(3000).isConvertedToRomanNumeral("MMM");
	assertThat(3333).isConvertedToRomanNumeral("MMMCCCXXXIII");

	assertThat(5).isConvertedToRomanNumeral("V");
	assertThat(6).isConvertedToRomanNumeral("VI");
	assertThat(37).isConvertedToRomanNumeral("XXXVII");

	assertThat(50).isConvertedToRomanNumeral("L");
	assertThat(500).isConvertedToRomanNumeral("D");

	assertThat(4).isConvertedToRomanNumeral("IV");
	assertThat(34).isConvertedToRomanNumeral("XXXIV");

	assertThat(9).isConvertedToRomanNumeral("IX");
	assertThat(40).isConvertedToRomanNumeral("XL");
	assertThat(90).isConvertedToRomanNumeral("XC");
	assertThat(400).isConvertedToRomanNumeral("CD");
	assertThat(900).isConvertedToRomanNumeral("CM");

	assertThat(99).isConvertedToRomanNumeral("XCIX");
	assertThat(3999).isConvertedToRomanNumeral("MMMCMXCIX");
	assertThat(3494).isConvertedToRomanNumeral("MMMCDXCIV");
}