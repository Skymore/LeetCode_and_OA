#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* findLeftMiddle(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // fast只能走到链表末尾, slow走到链表中点, 如果链表长度为奇数, slow指向中点,
    // 如果链表长度为偶数, slow指向左中点
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow现在指向偶数长度链表的左中点
    return slow;
}

ListNode* findRightMiddle(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // fast可以走到末尾的下一个节点, slow走到右中点
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    // 创建示例链表：1->2->3->4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* leftMid = findLeftMiddle(head);
    std::cout << "The left middle element is: " << leftMid->val << std::endl;
    ListNode* rightMid = findRightMiddle(head);
    std::cout << "The right middle element is: " << rightMid->val << std::endl;


    // 清理内存
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
