#include "../../headers/views/ListCategoriesView.h"
#include <string>

using namespace std;

ListCategoriesView::ListCategoriesView(const wstring &userToken) : BaseAuthView(userToken) {
    this->headers = {L"Listing Categories View!"};
    this->ctrl = make_unique<ListCategoriesController>(userToken);
}

int ListCategoriesView::renderBody() {
    list<shared_ptr<Category>> list = ctrl->getAll();
    if (list.empty())
        utils.printLine(L"No categories to present.");
    else {
        utils.printLine(L"Code\t Description");
        for (shared_ptr<Category> cat: list) {
            utils.printLine(cat->getCode() + L"\t " + cat->getDescription());
        }
    }
    utils.readEnterToContinue();

    return 0;
}