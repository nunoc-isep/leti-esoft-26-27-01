#include "headers/controllers/ui/CreateCategoryController.h"
#include "headers/controllers/ui/App.h"

void CreateCategoryController::createCategory(const wstring &code, const wstring &description) {
    App* app = App::getInstance();
    this->container = app->getCategoryContainer();
    this->category = this->container->create(code, description);
}

Result CreateCategoryController::saveCreatedCategory() {
    if (this->category)
        return this->container->save(this->category);
    return Result::NOK(L"A category should be created first.");
}

Result CreateCategoryController::createAndSaveCategory(const wstring &code, const wstring &description) {
    return Result::NOK(L"not implemented yet");
}