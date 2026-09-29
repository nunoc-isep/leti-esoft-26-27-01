#ifndef TASKS_CATEGORYCONTAINER_H
#define TASKS_CATEGORYCONTAINER_H

#include <list>
#include <optional>
#include <memory>
#include "Category.h"

using namespace std;

class CategoryContainer {
private:
    list<shared_ptr<Category>> container;

    optional<shared_ptr<Category>> findObject(shared_ptr<Category> obj);

public:
    CategoryContainer();

    shared_ptr<Category> create(const wstring &code, const wstring &description);

    Result save(shared_ptr<Category> obj);

    Result remove(shared_ptr<Category> obj);

    list<shared_ptr<Category>> getAll();

    optional<shared_ptr<Category>> findById(const wstring &code);

    bool isEmpty();

    long count();
};

#endif //TASKS_CATEGORYCONTAINER_H