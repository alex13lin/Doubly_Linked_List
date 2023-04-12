#include <iostream>
#include "Headers/DoublyLinkedListMenu.h"


int main() {
    auto *menu = new DoublyLinkedListMenu;
    char *option = new char[80];
    while (menu->can_continue()) {
        menu->show_options();
        std::cin >> option;
        menu->select_option(option);
    }
    delete menu;
    delete[] option;
    return 0;
}
