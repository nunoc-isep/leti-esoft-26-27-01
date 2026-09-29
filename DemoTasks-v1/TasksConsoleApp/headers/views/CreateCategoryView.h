#ifndef TASKS_CREATECATEGORYVIEW_H
#define TASKS_CREATECATEGORYVIEW_H

#include <memory>
#include "BaseAuthView.h"
#include <headers/controllers/ui/CreateCategoryController.h>

class CreateCategoryView : public BaseAuthView {
private:
    unique_ptr<CreateCategoryController> ctrl;

protected:
    int renderBody();

public:
    CreateCategoryView(const wstring &userToken);
};

#endif //TASKS_CREATECATEGORYVIEW_H