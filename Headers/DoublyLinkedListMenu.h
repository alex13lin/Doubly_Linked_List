#ifndef DOUBLELINKEDLIST_DOUBLYLINKEDLISTMENU_H
#define DOUBLELINKEDLIST_DOUBLYLINKEDLISTMENU_H

#include <iostream>
#include <iomanip>
#include "DoublyLinkedList.h"

class DoublyLinkedListMenu {
public:
    DoublyLinkedListMenu();

    ~DoublyLinkedListMenu();

    void show_options();

    void select_option(const char *);

    bool can_continue() const;

private:
    DoublyLinkedList *doubleLinkedList;
    bool is_continuing;
};


#endif //DOUBLELINKEDLIST_DOUBLYLINKEDLISTMENU_H
