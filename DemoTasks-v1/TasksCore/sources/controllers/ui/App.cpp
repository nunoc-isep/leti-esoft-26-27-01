#include "headers/controllers/ui/App.h"

using namespace std;

/**
 * Static methods should be defined outside the class.
 */

App *App::instance{nullptr};
std::mutex App::mutex;

/**
 * Instance Methods
 */
App::App() {
    this->person = make_shared<Person>(L"John");
    this->categoryContainer = make_shared<CategoryContainer>();
}

App::~App() {
}

shared_ptr<Person> App::getPerson() {
    return this->person;
}

shared_ptr<CategoryContainer> App::getCategoryContainer() {
    return this->categoryContainer;
}

/**
 * The first time we call getInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
App *App::getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr) {
        instance = new App();
    }
    return instance;
}