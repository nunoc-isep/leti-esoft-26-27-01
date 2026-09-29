#include "../../headers/views/UpdateCategoryView.h"
#include <iterator>
#include <algorithm>

UpdateCategoryView::UpdateCategoryView(const wstring &userToken) : BaseAuthView(userToken) {
    this->headers = {L"Update Category View!"};
    this->ctrl = make_unique<UpdateCategoryController>(userToken);
}

int UpdateCategoryView::renderBody() {
    list<shared_ptr<Category>> list = ctrl->getAll();
    if (list.empty())
        utils.printLine(L"There are no categories to update.");
    else {
        vector<wstring> categories;
        // Create a vector of string from the list of categories
        for (shared_ptr<Category> cat: list)
            categories.push_back(cat->getCode() + L"\t  " + cat->getDescription());
        //
        optional<int> selectedIndex = utils.doSelection(L"Select category to update:", categories, true, L"Cancel");
        if (selectedIndex.value() >= 0) {
            std::list<shared_ptr<Category>>::iterator it = std::next(list.begin(), selectedIndex.value());

            Category *cat = it->get();
            utils.printLine(L"\tCurrent Description: " + cat->getDescription());

            wstring newDescription = utils.readNonEmptyLine(L"\tEnter New Description");

            Result result = ctrl->updateCategory(cat->getCode(), newDescription);
            if (result.isOK())
                utils.printLine(L"Successfully updated!");
            else
                utils.printLine(L"Error:" + result.getMessage());
        }
    }
    utils.readEnterToContinue();
    return 0;
}