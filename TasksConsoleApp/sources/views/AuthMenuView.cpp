#include "../../headers/views/AuthMenuView.h"

AuthMenuView::AuthMenuView(const wstring &userToken) {
    this->userToken = userToken;
    this->headers = {L"Registered User Options!"};

    this->menuOptions = {
            L"Tasks Management"
    };

    this->cancelMenuMsg = L"Return";
}

int AuthMenuView::processMenuOption(int option) {
    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            result = -1;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}