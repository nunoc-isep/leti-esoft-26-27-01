#include <vector>
#include "../../headers/views/DeleteCategoryView.h"

DeleteCategoryView::DeleteCategoryView(const wstring &userToken) : BaseAuthView(userToken) {
    this->headers = {L"Delete Category View!"};
    this->ctrl = make_unique<DeleteCategoryController>(userToken);
}

int DeleteCategoryView::renderBody() {
    vector<shared_ptr<Category>> categories = ctrl->getAll();
    if (categories.empty())
        utils.printLine(L"There are no categories to delete.");
    else {
        vector<wstring> catsAsString;
        // Create a vector of string from the vector of categories
        for (shared_ptr<Category> cat: categories)
            catsAsString.push_back(cat->getCode() + L"\t  " + cat->getDescription());
        //
        optional<int> selectedIndex = utils.doSelection(L"Select category to delete:", catsAsString, true, L"Cancel");
        if (selectedIndex.value() >= 0) {
            shared_ptr<Category> cat = categories[selectedIndex.value()];

            vector<wstring> confirmMsg{L"Deleting category with...",
                                       L"\tCode: " + cat->getCode(),
                                       L"\tDescription: " + cat->getDescription(),
            };
            utils.printLines(confirmMsg);
            bool confirm = utils.readBoolean(L"Do you confirm deleting?");
            if (confirm) {
                Result result = ctrl->deleteCategory(cat->getCode());
                if (result.isOK())
                    utils.printLine(L"Successfully deleted!");
                else
                    utils.printLine(L"Error:" + result.getMessage());
            } else
                utils.printLine(L"Operation cancelled.");
        }
    }
    utils.readEnterToContinue();
    return 0;
}