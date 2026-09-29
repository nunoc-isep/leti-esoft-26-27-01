#include "headers/domain/model/CategoryContainer.h"

using namespace std;

CategoryContainer::CategoryContainer() {
}

shared_ptr<Category> CategoryContainer::create(const wstring &code, const wstring &description) {
    //return shared_ptr<Category>(new Category(code, description));
    return make_shared<Category>(code, description);
}

optional<shared_ptr<Category>> CategoryContainer::findObject(shared_ptr<Category> obj) {
    if (!obj)
        return nullopt;
    for (std::list<shared_ptr<Category>>::iterator it = container.begin(); it != container.end(); ++it) {
        shared_ptr<Category> obj2 = *it;
        if (obj2 == obj)
            return make_optional<shared_ptr<Category>>(obj2);
    }
    return nullopt;
}

Result CategoryContainer::save(shared_ptr<Category> obj) {
    if (!obj)
        return Result::NOK(L"Category object not provided!");
    optional<shared_ptr<Category>> exists = this->findObject(obj);
    if (!exists.has_value()) {
        // Aims to add a new object
        exists = this->findById(obj->getCode());
        if (!exists.has_value()) {
            // No duplicate object exists, so it can be added
            this->container.push_back(obj);
            return Result::OK();
        } else
            return Result::NOK(L"Trying to add a duplicate category.");
    } else {
        // Aims to Update the object
        // Since object is in memory nothing is required to be done
        return Result::OK();
    }
}

Result CategoryContainer::remove(shared_ptr<Category> obj) {
    if (!obj)
        return Result::NOK(L"Category object not provided!");
    optional<shared_ptr<Category>> exists = this->findObject(obj);
    if (exists.has_value()) {
        this->container.remove(obj);
        return Result::OK();
    }
    return Result::NOK(L"Category not found!");
}

list<shared_ptr<Category>> CategoryContainer::getAll() {
    list<shared_ptr<Category>> newList;
    newList.insert(newList.end(), container.begin(), container.end());
    return newList;
}

optional<shared_ptr<Category>> CategoryContainer::findById(const wstring &code) {
    for (list<shared_ptr<Category>>::iterator it = container.begin(); it != container.end(); ++it) {
        shared_ptr<Category> obj = *it;
        if (obj->hasCode(code))
            return make_optional<shared_ptr<Category>>(obj);
    }
    return nullopt;
}

bool CategoryContainer::isEmpty() {
    return this->container.empty();
}

long CategoryContainer::count() {
    return this->container.size();
}