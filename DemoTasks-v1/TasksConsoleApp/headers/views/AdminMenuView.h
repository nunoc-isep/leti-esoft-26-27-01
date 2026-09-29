#ifndef TASKS_ADMINMENUVIEW_H
#define TASKS_ADMINMENUVIEW_H

#include "MenuView.h"

class AdminMenuView : public MenuView {
protected:
    wstring userToken;

    virtual int processMenuOption(int option);

public:
    AdminMenuView(const wstring &userToken);
};

#endif //TASKS_ADMINMENUVIEW_H