#ifndef TASKS_CATEGORY_H
#define TASKS_CATEGORY_H

#include <string>
#include "../shared/Result.h"

using namespace std;

class Category {
private:
    wstring code;
    wstring description;

    Category();

    bool isCodeValid(const wstring &code);

    bool isDescriptionValid(const wstring &description);

public:
    Category(const wstring &code, const wstring &description);

    const wstring &getCode() const;

    const wstring &getDescription() const;

    Result changeDescription(const wstring &newDescription);

    bool hasCode(const wstring &code) const;

    bool operator==(const Category &param) const;

    bool operator<(const Category &param) const;
};

#endif //TASKS_CATEGORY_H