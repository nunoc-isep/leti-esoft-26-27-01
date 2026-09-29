#ifndef TASKS_AUTHCONTROLLER_H
#define TASKS_AUTHCONTROLLER_H

#include <string>
#include <memory>
#include "../../domain/model/Person.h"
#include "../../domain/model/Category.h"

using namespace std;

class AuthController {
protected:
    wstring userToken;
    shared_ptr<Person> person;

    bool ensureUserTokenIsValid();

    bool ensureUserHasRole(const wstring &role);

public:
    AuthController(const wstring &userToken);

    AuthController(shared_ptr<Person> person, const wstring &userToken);
};

#endif //TASKS_AUTHCONTROLLER_H