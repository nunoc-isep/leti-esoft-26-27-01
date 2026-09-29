#ifndef TASKS_WELCOMEVIEW_H
#define TASKS_WELCOMEVIEW_H

#include "MenuView.h"

class WelcomeView : public MenuView {
public:
    WelcomeView();

    int processMenuOption(int option);
};

#endif //TASKS_WELCOMEVIEW_H