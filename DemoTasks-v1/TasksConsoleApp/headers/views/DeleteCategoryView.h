#ifndef TASKS_DELETECATEGORYVIEW_H
#define TASKS_DELETECATEGORYVIEW_H

#include <memory>
#include "BaseAuthView.h"
#include <headers/controllers/ui/DeleteCategoryController.h>

class DeleteCategoryView : public BaseAuthView {
private:
    unique_ptr<DeleteCategoryController> ctrl;

protected:
    int renderBody();

public:
    DeleteCategoryView(const wstring &userToken);
};

#endif //TASKS_DELETECATEGORYVIEW_H