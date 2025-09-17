#include <gtest/gtest.h>
#include <string>
#include "../include/numb_func.h" 

// Тестовые случаи для функции numb_func
TEST(NumbFuncTest, BasicExtraction) {
    EXPECT_EQ(numb_func("abc123def456"), "123456");
    EXPECT_EQ(numb_func("1a2b3c4d"), "1234");
    EXPECT_EQ(numb_func("a1b2c3d4e5f6"), "123456");
}

TEST(NumbFuncTest, OnlyLettersReturnsEmpty) {
    EXPECT_EQ(numb_func("abcdef"), "");
    EXPECT_EQ(numb_func("HelloWorld"), "");
    EXPECT_EQ(numb_func("ТестПроверка"), "");
}

TEST(NumbFuncTest, OnlyNumbersReturnsAll) {
    EXPECT_EQ(numb_func("123456"), "123456");
    EXPECT_EQ(numb_func("9876543210"), "9876543210");
    EXPECT_EQ(numb_func("000"), "000");
}

TEST(NumbFuncTest, MixedWithSpecialCharacters) {
    EXPECT_EQ(numb_func("!@#$%^&*()123abc"), "123");
    EXPECT_EQ(numb_func("test123!@#456test"), "123456");
    EXPECT_EQ(numb_func("a-b_c.d+e*f"), "");
}

TEST(NumbFuncTest, EmptyString) {
    EXPECT_EQ(numb_func(""), "");
}

TEST(NumbFuncTest, StringWithSpaces) {
    EXPECT_EQ(numb_func("abc 123 def 456"), "123456");
    EXPECT_EQ(numb_func("1 2 3 4 5"), "12345");
    EXPECT_EQ(numb_func("   test  "), "");
}

TEST(NumbFuncTest, RussianTextWithNumbers) {
    EXPECT_EQ(numb_func("Привет123Мир456"), "123456");
    EXPECT_EQ(numb_func("Тест987Один654"), "987654");
    EXPECT_EQ(numb_func("Строка42сЧислами99"), "4299");
}

TEST(NumbFuncTest, SingleCharacters) {
    EXPECT_EQ(numb_func("a"), "");
    EXPECT_EQ(numb_func("5"), "5");
    EXPECT_EQ(numb_func("z9"), "9");
    EXPECT_EQ(numb_func("0"), "0");
}

TEST(NumbFuncTest, EdgeCases) {
    EXPECT_EQ(numb_func("000"), "000");
    EXPECT_EQ(numb_func("999"), "999");
    EXPECT_EQ(numb_func("0a0b0c0"), "0000");
}

TEST(NumbFuncTest, LongStringPerformance) {
    std::string longInput;
    std::string expected;
    
    // Генерируем длинную строку с числами
    for (int i = 0; i < 1000; i++) {
        longInput += "a" + std::to_string(i % 10);
        expected += std::to_string(i % 10);
    }
    
    EXPECT_EQ(numb_func(longInput), expected);
}

TEST(NumbFuncTest, AllASCIICharacters) {
    std::string allAscii;
    std::string expectedNumbers;
    
    // Создаем строку со всеми ASCII символами
    for (int i = 0; i < 256; i++) {
        char c = static_cast<char>(i);
        allAscii += c;
        if (c >= '0' && c <= '9') {
            expectedNumbers += c;
        }
    }
    
    EXPECT_EQ(numb_func(allAscii), expectedNumbers);
}

// Тест для проверки порядка сохранения цифр
TEST(NumbFuncTest, OrderPreservation) {
    EXPECT_EQ(numb_func("a1b2c3"), "123");
    EXPECT_EQ(numb_func("3a2b1c"), "321");
    EXPECT_EQ(numb_func("9a8b7c6d5e4f3g2h1i0"), "9876543210");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}