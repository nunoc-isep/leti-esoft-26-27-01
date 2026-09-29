#ifndef TASKS_NOAUTHMENUVIEW_H
#define TASKS_NOAUTHMENUVIEW_H

#include "MenuView.h"

class NoAuthMenuView : public MenuView {
protected:
    int processMenuOption(int option);

public:
    NoAuthMenuView();
};

#endif //TASKS_NOAUTHMENUVIEW_H