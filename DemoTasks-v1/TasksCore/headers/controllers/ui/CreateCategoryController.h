#ifndef TASKS_CREATECATEGORYCONTROLLER_H
#define TASKS_CREATECATEGORYCONTROLLER_H

#include <string>
#include "AuthController.h"
#include "../../domain/model/Person.h"
#include "../../domain/model/Category.h"
#include "../../domain/model/CategoryContainer.h"

using namespace std;

class CreateCategoryController : public AuthController {
private:
    shared_ptr<Category> category;
    shared_ptr<CategoryContainer> container;

public:
    CreateCategoryController(const wstring &userToken) : AuthController(userToken) {};

    CreateCategoryController(shared_ptr<Person> person, const wstring &userToken) : AuthController(person, userToken) {};

    void createCategory(const wstring &code, const wstring &description);

    Result saveCreatedCategory();

    Result createAndSaveCategory(const wstring &code, const wstring &description);
};

#endif //TASKS_CREATECATEGORYCONTROLLER_H