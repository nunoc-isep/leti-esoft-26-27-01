#include "gtest/gtest.h"
#include <headers/domain/model/Person.h>
#include <headers/domain/exceptions/TaskDomainError.h>

class PersonFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        // Add here some testing set up code
    }

    virtual void TearDown() {
        // Add here some testing tear down code
    }
};

TEST_F(PersonFixture, CreateWithNonValidName) {
    EXPECT_THROW(new Person(L"  "), TaskDomainError);
    EXPECT_THROW(new Person(L""), TaskDomainError);
}

TEST_F(PersonFixture, CreateWithValidName) {
    EXPECT_NO_THROW(new Person(L"John"));
}

TEST_F(PersonFixture, CheckingNameHasNoLeftAndRightSpaces) {
    Person p(L" Jo hn ");

    EXPECT_EQ(p.getName(), L"Jo hn");
}