#include "Common.h"

void deleteList(ListNode *&head) {
    if (head) {
        if (head->next) {
            deleteList(head->next);
        }
        delete head;
        head = nullptr;
    }
}