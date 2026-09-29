#include "../../headers/views/CreateCategoryView.h"

using namespace std;

CreateCategoryView::CreateCategoryView(const wstring &userToken) : BaseAuthView(userToken) {
    this->headers = {L"Create Category View!"};
    this->ctrl = make_unique<CreateCategoryController>(userToken);
}

int CreateCategoryView::renderBody() {
    bool exit = false;
    do {
        wstring code = utils.readNonEmptyLine(L"Category Code");
        wstring description = utils.readNonEmptyLine(L"Category Description");
        try {
            ctrl->createCategory(code, description);
            utils.printLine(L"Creating Category with data:");
            utils.printLine(L"\tCode: " + code);
            utils.printLine(L"\tDescription: " + description);
            bool ok = utils.readBoolean(L"Do you confirm?");
            if (ok) {
                Result result = ctrl->saveCreatedCategory();
                if (result.isOK()) {
                    utils.printLine(L"Successfully created!");
                    utils.readEnterToContinue();
                    exit = true;
                } else
                    utils.printLine(L"Error:" + result.getMessage() + L" Please try again.");
            } else {
                utils.printLine("Operation cancelled!");
                exit = true;
            }
        }
        catch (invalid_argument e) {
            string strMsg = "Error: ";
            strMsg.append(e.what());
            utils.printLine(strMsg);
            exit = !utils.readBoolean(L"Do you want to retry?");
        }
    } while (!exit);

    return 0;
}