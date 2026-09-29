#include "../../../headers/domain/model/Category.h"
#include <stdexcept>

using namespace std;

Category::Category(const wstring &code, const wstring &description) {
    if (!this->isCodeValid(code))
        throw invalid_argument("Invalid value for code.");
    if (!this->isDescriptionValid(description))
        throw invalid_argument("Invalid value for description.");

    this->code = code;
    this->description = description;
}

const wstring &Category::getCode() const {
    return this->code;
}

const wstring &Category::getDescription() const {
    return this->description;
}

Result Category::changeDescription(const wstring &newDescription) {
    if (this->isDescriptionValid(newDescription)) {
        this->description = newDescription;
        return Result::OK();
    }
    return Result::NOK(L"Invalid category description.");
}

bool Category::isCodeValid(const wstring &code) {
    return !(code.empty() || code.length() < 5);
}

bool Category::isDescriptionValid(const wstring &description) {
    return !(description.empty());
}

bool Category::operator==(const Category &param) const {
    if (&param == this) return true;
    return (this->code == param.code);
}

bool Category::operator<(const Category &param) const {
    return (this->code < param.code);
}

bool Category::hasCode(const wstring &code) const {
    return this->code == code;
}