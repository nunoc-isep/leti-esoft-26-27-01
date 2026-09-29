#include "../../headers/views/BaseAuthView.h"

using namespace std;

BaseAuthView::BaseAuthView(const wstring &userToken) : BaseView() {
    this->userToken = userToken;
}