#include "../../headers/views/NoAuthMenuView.h"
#include <vector>

using namespace std;

NoAuthMenuView::NoAuthMenuView() {
    this->headers = {L"Anonymous User Options!"};

    this->menuOptions = {
            L"Application Goal",
            L"Credits"
    };

    this->cancelMenuMsg = L"Return";
}

int NoAuthMenuView::processMenuOption(int option) {
    int result = 0;
    vector<wstring> lines;
    utils.printEmptyLine();
    switch (option) {
        case 1:
            lines = {
                    L"This application was developed within the scope of LETI-ESOFT lectured at ISEP.",
                    L"It is intended to be used by students:",
                    L"\t- to recap their competencies presumably acquired in previous course units (e.g. APROG, FSOFT);",
                    L"\t- as a starting point for acquiring new competencies."
            };
            utils.printLines(lines);
            utils.readEnterToContinue();
            break;
        case 2:
            lines = {
                    L"LETI-ESOFT Faculty Members:",
                    L"\tAlexandre Gouveia (aas@isep.ipp.pt)",
                    L"\tPaulo Maio (ex-member)"
            };
            utils.printLines(lines);
            utils.readEnterToContinue();
            break;
        default:
            result = -1;
            break;
    }

    return result;
}