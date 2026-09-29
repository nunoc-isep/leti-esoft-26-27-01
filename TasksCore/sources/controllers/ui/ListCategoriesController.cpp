#include "headers/controllers/ui/ListCategoriesController.h"
#include "headers/controllers/ui/App.h"

list<shared_ptr<Category>> ListCategoriesController::getAll() {
    App* app = App::getInstance();
    this->container = app->getCategoryContainer();
    return this->container->getAll();
}
