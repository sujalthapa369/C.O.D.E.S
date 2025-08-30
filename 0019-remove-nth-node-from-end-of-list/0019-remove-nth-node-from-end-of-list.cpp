class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int N) {
        if (!head) return nullptr;

        // Step 1: count total nodes
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Step 2: if we need to delete head
        if (count == N) {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        // Step 3: find (count - N)-th node
        temp = head;
        for (int i = 1; i < count - N; i++) {
            temp = temp->next;
        }

        ListNode* delnode = temp->next;
        temp->next = temp->next->next;
        delete delnode;

        return head;
    }
};
