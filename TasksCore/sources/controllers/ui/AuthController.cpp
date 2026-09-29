#include <stdexcept>
#include "headers/controllers/ui/AuthController.h"
#include "headers/controllers/ui/App.h"
#include "headers/domain/shared/StringUtils.h"

AuthController::AuthController(const wstring &userToken) : AuthController(App::getInstance()->getPerson(), userToken) {
}

AuthController::AuthController(shared_ptr<Person> person, const wstring &userToken) {
    this->userToken = StringUtils::trim(userToken);
    this->person = person;
    if (!person)
        throw invalid_argument("Invalid argument: 'person' cannot be null.");
    if (!ensureUserTokenIsValid())
        throw invalid_argument("Invalid argument: 'userToken' is not valid.");
}

bool AuthController::ensureUserTokenIsValid() {
    return StringUtils::ensureNotNullOrEmpty(this->userToken);
}

bool AuthController::ensureUserHasRole(const wstring &role) {
    return (StringUtils::trim(role) == StringUtils::trim(this->userToken));
}