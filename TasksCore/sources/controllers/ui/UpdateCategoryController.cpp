#include "headers/controllers/ui/UpdateCategoryController.h"
#include "headers/controllers/ui/App.h"

list<shared_ptr<Category>> UpdateCategoryController::getAll() {
    App* app = App::getInstance();
    this->container = app->getCategoryContainer();
    return this->container->getAll();
}

Result UpdateCategoryController::updateCategory(const wstring &code, const wstring &description) {
    optional<shared_ptr<Category>> obj = this->container->findById(code);
    if (obj.has_value()) {
        shared_ptr<Category> cat = obj.value();
        Result result = cat->changeDescription(description);
        if (result.isOK())
            return this->container->save(cat);
        else
            return result;
    }
    return Result::NOK(L"Category not found.");
}