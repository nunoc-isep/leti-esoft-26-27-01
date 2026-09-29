#ifndef TASKS_BASEVIEW_H
#define TASKS_BASEVIEW_H

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

class BaseView {
protected:
    Utils utils;
    vector<wstring> headers;

    void renderHeader();

    virtual int renderBody() = 0;

public:
    BaseView();

    int show();
};

#endif //TASKS_BASEVIEW_H