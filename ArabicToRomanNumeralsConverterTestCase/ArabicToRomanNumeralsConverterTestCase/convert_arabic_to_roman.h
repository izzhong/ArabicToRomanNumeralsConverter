#pragma once
#include "arabic_to_roman_mapping.h"

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