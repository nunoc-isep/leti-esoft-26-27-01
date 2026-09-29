#include "../../headers/views/WelcomeView.h"
#include "../../headers/views/NoAuthMenuView.h"
#include "../../headers/views/AuthMenuView.h"
#include "../../headers/views/AdminMenuView.h"

using namespace std;

WelcomeView::WelcomeView() : MenuView() {
    this->headers = {
            L"Welcome to the Tasks Console App!", L"",
            L"\t Please notice that no real user authentication process is implemented.",
            L"\t Thus, the authentication process is being simulated by a user role selection."
    };

    this->menuOptions = {
            L"Anonymous (unregistered)",
            L"Registered (regular one)",
            L"App Administrator"
    };

    this->cancelMenuMsg = L"Exit App";
}

int WelcomeView::processMenuOption(int option) {
    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            view = new NoAuthMenuView();
            view->show();
            break;
        case 2:
            // Put here some logic if you want to authenticate the user
            view = new AuthMenuView(L"USER");
            view->show();
            break;
        case 3:
            // Put here some logic if you want to authenticate the admin
            view = new AdminMenuView(L"ADMIN");
            view->show();
            break;
        default:
            result = -1;
            break;
    }
    return result;
}