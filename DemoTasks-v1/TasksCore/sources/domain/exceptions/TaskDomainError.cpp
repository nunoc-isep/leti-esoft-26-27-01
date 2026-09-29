#include "headers/domain/exceptions/TaskDomainError.h"

TaskDomainError::TaskDomainError(const string &what_arg) : domain_error(what_arg) {
}