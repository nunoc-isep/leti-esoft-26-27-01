#ifndef TASKS_PERSON_H
#define TASKS_PERSON_H

#include <string>

using namespace std;

class Person {
private:
    wstring name;

    bool isNameValid(const wstring &name);

public:
    Person(const wstring &name);

    const wstring &getName() const;
};

#endif //TASKS_PERSON_H