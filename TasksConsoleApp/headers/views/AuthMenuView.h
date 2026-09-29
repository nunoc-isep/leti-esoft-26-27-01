#ifndef TASKS_AUTHMENUVIEW_H
#define TASKS_AUTHMENUVIEW_H

#include "MenuView.h"

class AuthMenuView : public MenuView {
protected:
    wstring userToken;

    virtual int processMenuOption(int option);

public:
    AuthMenuView(const wstring &userToken);
};

#endif //TASKS_AUTHMENUVIEW_H