#include "headers/controllers/ui/DeleteCategoryController.h"
#include "headers/controllers/ui/App.h"
#include <vector>

vector<shared_ptr<Category>> DeleteCategoryController::getAll() {
    App* app = App::getInstance();
    this->container = app->getCategoryContainer();
    list<shared_ptr<Category>> list = this->container->getAll();
    vector<shared_ptr<Category>> categories;
    /** Transforming a list into a vector --> adapting to the UI needs
     *  This differs from what was done on the UpdateCategoryController to show some diversity
     *  and explores the responsibilities of Controllers (i.e. serving as adapters)
    */
    for (shared_ptr<Category> cat: list)
        categories.push_back(cat);

    return categories;
}

Result DeleteCategoryController::deleteCategory(const wstring &code) {
    optional<shared_ptr<Category>> obj = this->container->findById(code);
    if (obj.has_value()) {
        shared_ptr<Category> cat = obj.value();
        return this->container->remove(cat);
    }
    return Result::NOK(L"Category not found.");
}