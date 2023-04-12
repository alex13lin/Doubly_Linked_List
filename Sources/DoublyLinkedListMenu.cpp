#include "../Headers/DoublyLinkedListMenu.h"

DoublyLinkedListMenu::DoublyLinkedListMenu() {
    doubleLinkedList = new DoublyLinkedList;
    is_continuing = true;
}

DoublyLinkedListMenu::~DoublyLinkedListMenu() {
    delete doubleLinkedList;
}

void DoublyLinkedListMenu::show_options() {
    std::cout << std::setw(5)
              << "***************************\n"
              << "1.insert\n"
              << "2.delete\n"
              << "3.modify\n"
              << "4.display\n"
              << "5.reverse\n"
              << "6.sort by score\n"
              << "7.quit\n"
              << "***************************\n"
              << "Enter your choice (1~6): ";
}

void DoublyLinkedListMenu::select_option(const char* option) {
    switch (option[0]) {
        case '1':
            doubleLinkedList->insert_student();
            break;
        case '2':
            doubleLinkedList->delete_student();
            break;
        case '3':
            doubleLinkedList->modify_student();
            break;
        case '4':
            doubleLinkedList->display_students();
            break;
        case '5':
            doubleLinkedList->reverse_students();
            break;
        case '6':
            doubleLinkedList->sort_students_by_score();
            break;
        case '7':
            std::cout << "Goodbye!!!";
            is_continuing = false;
            break;
        default:
            std::cout << "INVALID OPTION!!!\n";
            break;
    }
}

bool DoublyLinkedListMenu::can_continue() const {
    if (is_continuing)return true;
    return false;
}


