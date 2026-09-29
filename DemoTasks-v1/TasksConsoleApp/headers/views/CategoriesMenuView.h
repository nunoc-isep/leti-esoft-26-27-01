#ifndef TASKS_CATEGORIESMENUVIEW_H
#define TASKS_CATEGORIESMENUVIEW_H

#include "AuthMenuView.h"

class CategoriesMenuView : public AuthMenuView {
protected:
    int processMenuOption(int option);

public:
    CategoriesMenuView(const wstring &userToken);
};

#endif //TASKS_CATEGORIESMENUVIEW_H