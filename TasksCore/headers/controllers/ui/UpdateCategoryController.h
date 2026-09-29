#ifndef TASKS_UPDATECATEGORYCONTROLLER_H
#define TASKS_UPDATECATEGORYCONTROLLER_H

#include "AuthController.h"
#include "../../domain/model/Person.h"
#include "../../domain/model/Category.h"
#include "../../domain/model/CategoryContainer.h"

using namespace std;

class UpdateCategoryController : public AuthController {
private:
    shared_ptr<Category> category;
    shared_ptr<CategoryContainer> container;

public:
    UpdateCategoryController(const wstring &userToken) : AuthController(userToken) {};

    UpdateCategoryController(shared_ptr<Person> person, const wstring &userToken) : AuthController(person, userToken) {};

    list<shared_ptr<Category>> getAll();

    Result updateCategory(const wstring &code, const wstring &description);
};

#endif //TASKS_UPDATECATEGORYCONTROLLER_H