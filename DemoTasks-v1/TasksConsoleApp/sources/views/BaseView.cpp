#include "../../headers/views/BaseView.h"
#include <iostream>

using namespace std;

BaseView::BaseView() {
    locale::global(locale(""));
    wcout.imbue(locale());
}

void BaseView::renderHeader() {
    this->utils.printEmptyLine();
    this->utils.printLines(headers);
    this->utils.printEmptyLines(2);
}

int BaseView::show() {
    this->renderHeader();
    this->renderBody();
    return 0;
}