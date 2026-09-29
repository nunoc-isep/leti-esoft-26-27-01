#ifndef TASKS_LISTCATEGORIESVIEW_H
#define TASKS_LISTCATEGORIESVIEW_H

#include <memory>
#include "BaseAuthView.h"
#include <headers/controllers/ui/ListCategoriesController.h>

class ListCategoriesView : public BaseAuthView {
private:
    unique_ptr<ListCategoriesController> ctrl;

protected:
    int renderBody();

public:
    ListCategoriesView(const wstring &userToken);
};

#endif //TASKS_LISTCATEGORIESVIEW_H