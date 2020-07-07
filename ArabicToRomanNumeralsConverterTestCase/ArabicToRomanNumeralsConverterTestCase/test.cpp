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

constexpr std::size_t numberOfMappings{ 13 };
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMappings>;
const ArabicToRomanMappings arabicToRomanMappings{ {
	{1000,"M"},
	{900,"CM"},
	{500,"D"},
	{400,"CD"},
	{100,"C"},
	{90,"XC"},
	{50,"L"},
	{40,"XL"},
	{10,"X"},
	{9,"IX"},
	{5,"V"},
	{4,"IV"},
	{1,"I"},
}};

std::array<int, 10> ar {
	{1,2,3,4,5,6}
};

/// <summary>
/// ����������������ת��Ϊ���������ַ���
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



// �۲���Щ���ԣ���������ǳ��ߣ��ظ��Ҳ�����
// ���Դ���ҲӦ�ñ��ع�
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

// �ع�����
TEST(AragicToRomanNumeralsConverterTestCase, 33_isConvertedTo_XXXIII)
{
	// ASSERT_EQ("XXXIII", convertArabicNumberToRomanNumeral(33));
	// ʹ��һ���Զ���Ĳ���
	assertThat(33).isConvertedToRomanNumeral("XXXIII");
}

// ���ϲ���
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