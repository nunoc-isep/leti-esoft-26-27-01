#include "headers/domain/model/Person.h"
#include "headers/domain/shared/StringUtils.h"
#include "headers/domain/exceptions/TaskDomainError.h"

using namespace std;

Person::Person(const wstring &name) {
    if (!this->isNameValid(name))
        throw TaskDomainError("Invalid value for a person name.");
    this->name = StringUtils::trim(name);
}

bool Person::isNameValid(const wstring &name) {
    return StringUtils::ensureNotNullOrEmpty(name);
}

const wstring &Person::getName() const {
    return this->name;
}