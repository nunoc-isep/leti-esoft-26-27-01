#ifndef TASKS_DELETECATEGORYCONTROLLER_H
#define TASKS_DELETECATEGORYCONTROLLER_H

#include <vector>
#include "AuthController.h"
#include "../../domain/model/Person.h"
#include "../../domain/model/Category.h"
#include "../../domain/model/CategoryContainer.h"

using namespace std;

class DeleteCategoryController : public AuthController {
private:
    shared_ptr<Category> category;
    shared_ptr<CategoryContainer> container;

public:
    DeleteCategoryController(const wstring &userToken) : AuthController(userToken) {};

    DeleteCategoryController(shared_ptr<Person> person, const wstring &userToken) : AuthController(person, userToken) {};

    vector<shared_ptr<Category>> getAll();

    Result deleteCategory(const wstring &code);
};

#endif //TASKS_DELETECATEGORYCONTROLLER_H