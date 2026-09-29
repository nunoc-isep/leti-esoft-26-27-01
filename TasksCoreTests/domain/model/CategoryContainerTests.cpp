#include "gtest/gtest.h"
#include <headers/domain/model/Category.h>
#include <headers/domain/model/CategoryContainer.h>

class CategoryContainerFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        // Add here some testing set up code
        container = new CategoryContainer();
    }

    virtual void TearDown() {
        // Add here some testing tear down code
    }

    void populateWithFourCategories() {
        EXPECT_TRUE(this->container->isEmpty());
        cat1 = this->container->create(L"C0019", L"Category 19");
        cat2 = this->container->create(L"C0020", L"Category 20");
        cat3 = this->container->create(L"C0021", L"Category 21");
        cat4 = this->container->create(L"C0022", L"Category 22");
        this->container->save(cat1);
        this->container->save(cat2);
        this->container->save(cat3);
        this->container->save(cat4);
        EXPECT_EQ(this->container->count(), 4);
    }

    CategoryContainer *container;
    shared_ptr<Category> cat1, cat2, cat3, cat4;
};

TEST_F(CategoryContainerFixture, CreateWithValidArguments) {
    shared_ptr<Category> cat = this->container->create(L"C0019", L"Category 19");
    EXPECT_EQ(cat->getCode(), L"C0019");
}

TEST_F(CategoryContainerFixture, CreateWithInvalidArguments) {
    EXPECT_THROW(this->container->create(L"C19", L"Category 19"), invalid_argument);
}

TEST_F(CategoryContainerFixture, SavingNulls) {
    EXPECT_FALSE(this->container->save(nullptr).isOK());
    EXPECT_TRUE(this->container->isEmpty());

    EXPECT_FALSE(this->container->save(NULL).isOK());
    EXPECT_TRUE(this->container->isEmpty());

    shared_ptr<Category> ptr;
    EXPECT_FALSE(this->container->save(ptr).isOK());
    EXPECT_TRUE(this->container->isEmpty());
}

TEST_F(CategoryContainerFixture, RemovingNulls) {
    this->populateWithFourCategories();

    EXPECT_FALSE(this->container->remove(nullptr).isOK());
    EXPECT_EQ(this->container->count(), 4);

    EXPECT_FALSE(this->container->remove(NULL).isOK());
    EXPECT_EQ(this->container->count(), 4);

    shared_ptr<Category> ptr;
    EXPECT_FALSE(this->container->remove(ptr).isOK());
    EXPECT_EQ(this->container->count(), 4);
}

TEST_F(CategoryContainerFixture, GetAllWhenEmpty) {
    EXPECT_TRUE(this->container->isEmpty());

    list<shared_ptr<Category>> list = this->container->getAll();

    EXPECT_TRUE(list.empty());
}

TEST_F(CategoryContainerFixture, GetAllWhenPopulated) {
    this->populateWithFourCategories();

    list<shared_ptr<Category>> list = this->container->getAll();

    EXPECT_EQ(list.size(), 4);
}

TEST_F(CategoryContainerFixture, AddingOneCategory) {
    EXPECT_TRUE(this->container->isEmpty());
    shared_ptr<Category> cat = this->container->create(L"C0019", L"Category 19");
    this->container->save(cat);
    EXPECT_FALSE(this->container->isEmpty());
}

TEST_F(CategoryContainerFixture, AddingDuplicatedCategory) {
    EXPECT_TRUE(this->container->isEmpty());
    shared_ptr<Category> cat1 = this->container->create(L"C0019", L"Category 19");
    shared_ptr<Category> cat2 = this->container->create(L"C0019", L"Category C0019");
    this->container->save(cat1);
    EXPECT_EQ(this->container->count(), 1);
    EXPECT_TRUE(this->container->save(cat1).isOK());
    EXPECT_EQ(this->container->count(), 1);
    EXPECT_FALSE(this->container->save(cat2).isOK());
    EXPECT_EQ(this->container->count(), 1);
}

TEST_F(CategoryContainerFixture, AddingMultipleCategories) {
    this->populateWithFourCategories();
}

TEST_F(CategoryContainerFixture, RemovingCategory) {
    this->populateWithFourCategories();

    EXPECT_TRUE(this->container->remove(cat2).isOK());
    EXPECT_EQ(this->container->count(), 3);
    optional<shared_ptr<Category>> obj = this->container->findById(L"C020");
    EXPECT_FALSE(obj.has_value());
}

TEST_F(CategoryContainerFixture, RemovingNonExistingCategory) {
    this->populateWithFourCategories();

    shared_ptr<Category> obj = this->container->create(L"C0099", L"Category 99");
    EXPECT_FALSE(this->container->remove(obj).isOK());
    EXPECT_EQ(this->container->count(), 4);
}

TEST_F(CategoryContainerFixture, RemovingTwiceSameCategory) {
    this->populateWithFourCategories();

    EXPECT_TRUE(this->container->remove(cat3).isOK());
    EXPECT_EQ(this->container->count(), 3);
    EXPECT_FALSE(this->container->remove(cat3).isOK());
}

TEST_F(CategoryContainerFixture, FindingCategoriesById) {
    this->populateWithFourCategories();

    optional<shared_ptr<Category>> obj = this->container->findById(L"C031");
    EXPECT_FALSE(obj.has_value());

    obj = this->container->findById(L"C0019");
    EXPECT_TRUE(obj.has_value());
    EXPECT_EQ(obj.value(), cat1);

    obj = this->container->findById(L"C0020");
    EXPECT_TRUE(obj.has_value());
    EXPECT_EQ(obj.value(), cat2);

    obj = this->container->findById(L"C0021");
    EXPECT_TRUE(obj.has_value());
    EXPECT_EQ(obj.value(), cat3);

    obj = this->container->findById(L"C0022");
    EXPECT_TRUE(obj.has_value());
    EXPECT_EQ(obj.value(), cat4);
}