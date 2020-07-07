#include "pch.h"
#include <array>


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

struct ArabicToRomanMapping
{
	unsigned int arabicNumber;
	std::string romanNumeral;
};

constexpr std::size_t numberOfMappings{ 7 };
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMappings>;
const ArabicToRomanMappings arabicToRomanMappings{ {
	{1000,"M"},
	{500,"D"},
	{100,"C"},
	{50,"L"},
	{10,"X"},
	{5,"V"},
	{1,"I"},
}};

std::array<int, 10> ar {
	{1,2,3,4,5,6}
};

/// <summary>
/// 将给定正整数参数转换为罗马数字字符串
/// </summary>
/// <param name="arabicNumber"></param>
/// <returns></returns>
std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
{
	std::string romanString{};
	for (const auto& mapping : arabicToRomanMappings)
	{
		while (arabicNumber >= mapping.arabicNumber)
		{
			romanString += mapping.romanNumeral;
			arabicNumber -= mapping.arabicNumber;
		}
	}
	return romanString;
}

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
}