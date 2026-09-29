#ifndef TASKS_BASEAUTHVIEW_H
#define TASKS_BASEAUTHVIEW_H

#include "BaseView.h"

class BaseAuthView : public BaseView {
protected:
    wstring userToken;

    virtual int renderBody() = 0;

public:
    BaseAuthView(const wstring &userToken);
};

#endif //TASKS_BASEAUTHVIEW_H