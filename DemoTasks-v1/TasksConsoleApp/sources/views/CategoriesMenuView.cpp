#include "../../headers/views/CategoriesMenuView.h"
#include "../../headers/views/CreateCategoryView.h"
#include "../../headers/views/ListCategoriesView.h"
#include "../../headers/views/UpdateCategoryView.h"
#include "../../headers/views/DeleteCategoryView.h"

CategoriesMenuView::CategoriesMenuView(const wstring &userToken) : AuthMenuView(userToken) {
    this->headers = {L"Categories Management Options!"};

    this->menuOptions = {
            L"Create a category",
            L"List all categories",
            L"Update category description",
            L"Delete a category",
    };

    this->cancelMenuMsg = L"Return";
}

int CategoriesMenuView::processMenuOption(int option) {
    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            view = new CreateCategoryView(this->userToken);
            view->show();
            break;
        case 2:
            view = new ListCategoriesView(this->userToken);
            view->show();
            break;
        case 3:
            view = new UpdateCategoryView(this->userToken);
            view->show();
            break;
        case 4:
            view = new DeleteCategoryView(this->userToken);
            view->show();
            break;
        default:
            result = -1;
            break;
    }
    return result;
}