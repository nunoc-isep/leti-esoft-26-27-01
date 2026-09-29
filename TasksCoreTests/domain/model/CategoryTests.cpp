#include "gtest/gtest.h"
#include <headers/domain/model/Category.h>
#include <headers/domain/shared/Result.h>

class CategoryFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        // Add here some testing set up code
    }

    virtual void TearDown() {
        // Add here some testing tear down code
    }
};

TEST_F(CategoryFixture, CreateWithEmptyCode) {
    EXPECT_THROW(new Category(L"", L"Category One"), std::invalid_argument);
}

TEST_F(CategoryFixture, CreateWithCodeHavingOneChar) {
    EXPECT_THROW(new Category(L"1", L"Category One"), std::invalid_argument);
}

TEST_F(CategoryFixture, CreateWithCodeHavingFourChars) {
    EXPECT_THROW(new Category(L"C001", L"Category One"), std::invalid_argument);
}

TEST_F(CategoryFixture, CreateWithEmptyDescription) {
    EXPECT_THROW(new Category(L"C0001", L""), std::invalid_argument);
}

TEST_F(CategoryFixture, CreateWithValidData) {
    EXPECT_NO_THROW(new Category(L"C0001", L"Category One"));
}

TEST_F(CategoryFixture, CheckingSavingDataOnCreation) {
    Category cat(L"C0001", L"Category One");
    EXPECT_EQ(cat.getCode(), L"C0001");
    EXPECT_EQ(cat.getDescription(), L"Category One");
}

TEST_F(CategoryFixture, ChangingToInvalidDescription) {
    Category cat(L"C0001", L"Category One");
    EXPECT_TRUE(cat.changeDescription(L"").isNOK());
    EXPECT_EQ(cat.getDescription(), L"Category One");
}

TEST_F(CategoryFixture, ChangingToValidDescription) {
    Category cat(L"C0001", L"Category One");
    EXPECT_TRUE(cat.changeDescription(L"Changed Category").isOK());
    EXPECT_EQ(cat.getDescription(), L"Changed Category");
}

TEST_F(CategoryFixture, CheckingHasCode) {
    Category cat(L"C0001", L"Category One");
    EXPECT_TRUE(cat.hasCode(L"C0001"));
    EXPECT_FALSE(cat.hasCode(L"c0001"));
}

TEST_F(CategoryFixture, CheckingEqualOperatorUsingMemoryAddress) {
    Category cat1(L"C0001", L"Category One");
    Category cat2 = cat1;
    EXPECT_TRUE(cat1 == cat2);
}

TEST_F(CategoryFixture, CheckingEqualOperatorUsingSameCodeValue) {
    Category cat1(L"C0001", L"Category One");
    Category cat2(L"C0001", L"Category Two");
    EXPECT_TRUE(cat1 == cat2);
}

TEST_F(CategoryFixture, CheckingEqualOperatorUsingDistinctCodeValues) {
    Category cat1(L"C0001", L"Category One");
    Category cat2(L"C0002", L"Category Two");
    EXPECT_FALSE(cat1 == cat2);
}

TEST_F(CategoryFixture, CheckingEqualOperatorCaseSensitivity) {
    Category cat1(L"C0001", L"Category One");
    Category cat2(L"c0001", L"Category Two");
    EXPECT_FALSE(cat1 == cat2);
}

TEST_F(CategoryFixture, CheckingLessOperator) {
    Category cat1(L"C0001", L"Category One");
    Category cat2(L"C0002", L"Category Two");
    Category cat3(L"C0003", L"Category Three");
    Category cat4(L"C0001", L"Category Four");
    EXPECT_TRUE(cat1 < cat2);
    EXPECT_TRUE(cat2 < cat3);
    EXPECT_TRUE(cat4 < cat3);
    EXPECT_FALSE(cat1 < cat4);
}