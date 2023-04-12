#include "../Headers/DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    ptr = new Node_type;
    strcpy(ptr->name, "0");
    ptr->left_link = ptr;
    ptr->right_link = ptr;
    head = ptr;
    ptr_prev = nullptr;
    prev = nullptr;
    current = nullptr;
    next = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    prev = head;
    current = head->right_link;
    while (current != head) {
        delete prev;
        prev = current;
        current = current->right_link;
    }
}

void DoublyLinkedList::insert_student() {
    char score_temp[4];
    ptr = new Node_type;
    std::cout << "Student's name : ";
    std::cin >> ptr->name;
    std::cout << "Student's score : ";
    std::cin >> score_temp;
    ptr->score = atoi(score_temp);
    prev = head;
    current = head->right_link;
    while ((current != head)) {
        prev = current;
        current = current->right_link;
    }
    ptr->right_link = current;
    ptr->left_link = prev;
    prev->right_link = ptr;
    current->left_link = ptr;
}

void DoublyLinkedList::delete_student() {
    char del_name[20];
    if (has_records()) {
        std::cout << "Delete student's name: ";
        std::cin >> del_name;
        prev = head;
        current = head->right_link;
        while ((current != head) && (strcmp(current->name, del_name) != 0)) {
            prev = current;
            current = current->right_link;
        }
        if (is_student_in_record(del_name)) {
            prev->right_link = current->right_link;
            current->right_link->left_link = prev;
            delete current;
            std::cout << " " << del_name << " student's record deleted!\n";
        }
    }
}

void DoublyLinkedList::modify_student() {
    char name_temp[20], score_temp[4];
    if (has_records()) {
        std::cout << "Modify student's name: ";
        std::cin >> name_temp;
        prev = head;
        current = head->right_link;
        while ((current != head) && (strcmp(current->name, name_temp) != 0)) {
            prev = current;
            current = current->right_link;
        }
        if (is_student_in_record(name_temp)) {
            std::cout << "\nStudent's name: " << current->name;
            std::cout << "\nStudent's score: " << current->score;
            std::cout << "\nPlease enter new score: ";
            std::cin >> score_temp;
            current->score = atoi(score_temp);
        }
    }
}


void DoublyLinkedList::display_students() {
    int student_count = 0;
    if (has_records()) {
        std::cout << "---------------------------\n"
                  << std::setw(15) << "NAME"
                  << std::setw(7) << "SCORE"
                  << "\n---------------------------\n";
        current = head->right_link;
        while (current != head) {
            std::cout << std::setw(15) << current->name
                      << std::setw(7) << current->score
                      << "\n";
            student_count++;
            current = current->right_link;
        }
        std::cout << "---------------------------\n"
                  << "~Total " << student_count << " record(s) found~\n";
    }
}

void DoublyLinkedList::reverse_students() {
    prev = head->left_link;
    current = head;
    do {
        next = current->right_link;
        prev->left_link = current;
        current->right_link = prev;
        prev = current;
        current = next;
    } while (current != head);
}

void DoublyLinkedList::sort_students_by_score() {
    ptr = head->right_link;
    while (ptr != head) {
        ptr_prev = ptr->left_link;
        current = ptr->right_link;
        while ((current != head) && (ptr->score >= current->score)) {
            current = current->right_link;
        }
        if (current != head) {
            prev = current->left_link;
            next = current->right_link;
            prev->right_link = next;
            next->left_link = prev;
            ptr_prev->right_link = current;
            current->left_link = ptr_prev;
            ptr->left_link = current;
            current->right_link = ptr;
            ptr = current;
        } else ptr = ptr->right_link;
    }
}

bool DoublyLinkedList::has_records() {
    if (head->right_link != head) return true;
    std::cout << "No student record!\n";
    return false;

}

bool DoublyLinkedList::is_student_in_record(char *name) {
    if (current != head)return true;
    std::cout << "Student " << name << " not found!\n";
    return false;
}




