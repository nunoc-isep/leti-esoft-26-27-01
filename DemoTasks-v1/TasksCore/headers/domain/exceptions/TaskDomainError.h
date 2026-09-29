#ifndef TASKS_TASKDOMAINERROR_H
#define TASKS_TASKDOMAINERROR_H

#include <stdexcept>

using namespace std;

// Base class for any other domain error regarding the Tasks domain
class TaskDomainError : public domain_error {
public:
    TaskDomainError(const string &what_arg);
};

#endif //TASKS_TASKDOMAINERROR_H