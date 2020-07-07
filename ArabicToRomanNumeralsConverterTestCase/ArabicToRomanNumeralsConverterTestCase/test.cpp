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
std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
{
	std::string romanString{};
	while (arabicNumber >= 10)
	{
		romanString.push_back('X');
		arabicNumber -= 10;
	}
	while (arabicNumber >= 1)
	{
		romanString.push_back('I');
		--arabicNumber;
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