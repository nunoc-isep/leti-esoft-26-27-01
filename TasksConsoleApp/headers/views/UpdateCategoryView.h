#ifndef TASKS_UPDATECATEGORYVIEW_H
#define TASKS_UPDATECATEGORYVIEW_H

#include <memory>
#include "BaseAuthView.h"
#include <headers/controllers/ui/UpdateCategoryController.h>

class UpdateCategoryView : public BaseAuthView {
private:
    unique_ptr<UpdateCategoryController> ctrl;

protected:
    int renderBody();

public:
    UpdateCategoryView(const wstring &userToken);
};

#endif //TASKS_UPDATECATEGORYVIEW_H