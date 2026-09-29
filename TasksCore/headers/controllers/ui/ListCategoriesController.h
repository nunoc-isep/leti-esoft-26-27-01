#ifndef TASKS_LISTCATEGORIESCONTROLLER_H
#define TASKS_LISTCATEGORIESCONTROLLER_H

#include "AuthController.h"
#include "../../domain/model/Person.h"
#include "../../domain/model/Category.h"
#include "../../domain/model/CategoryContainer.h"

using namespace std;

class ListCategoriesController : public AuthController {
private:
    shared_ptr<Category> category;
    shared_ptr<CategoryContainer> container;

public:
    ListCategoriesController(const wstring &userToken) : AuthController(userToken) {};

    ListCategoriesController(shared_ptr<Person> person, const wstring &userToken) : AuthController(person, userToken) {};

    list<shared_ptr<Category>> getAll();
};

#endif //TASKS_LISTCATEGORIESCONTROLLER_H