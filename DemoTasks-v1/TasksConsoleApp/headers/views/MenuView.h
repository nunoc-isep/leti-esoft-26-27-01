#ifndef TASKS_MENUVIEW_H
#define TASKS_MENUVIEW_H

#include "BaseView.h"

class MenuView : public BaseView {
protected:
    vector<wstring> menuOptions;
    wstring cancelMenuMsg;

    int renderBody();

    void renderMenuOptions();

    virtual int processMenuOption(int option) = 0;

public:
    MenuView();
};

#endif //TASKS_MENUVIEW_H