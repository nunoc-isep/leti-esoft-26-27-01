#include "../../headers/views/AdminMenuView.h"
#include "../../headers/views/CategoriesMenuView.h"

AdminMenuView::AdminMenuView(const wstring &userToken) {
    this->userToken = userToken;
    this->headers = {L"Registered User Options!"};

    this->menuOptions = {
            L"Categories Management"
    };

    this->cancelMenuMsg = L"Return";
}

int AdminMenuView::processMenuOption(int option) {
    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            view = new CategoriesMenuView(this->userToken);
            view->show();
            break;
        default:
            result = -1;
            break;
    }
    return result;
}