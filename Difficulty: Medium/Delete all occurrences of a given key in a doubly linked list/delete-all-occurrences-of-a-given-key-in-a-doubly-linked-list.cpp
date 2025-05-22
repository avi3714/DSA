class Solution {
public:
    Node* nextin(Node* temporary, int x) {
        while (temporary != NULL && temporary->data == x) {
            Node* toDelete = temporary;
            temporary = temporary->next;
            delete toDelete;
        }
        return temporary;
    }

    void deleteAllOccurOfX(Node** head_ref, int x) {
        if (head_ref == NULL || *head_ref == NULL) return;

        // FIX: Use default constructor
        Node* dummy = new Node();
        dummy->data = -1;
        dummy->next = *head_ref;
        dummy->prev = NULL;
        if (*head_ref)
            (*head_ref)->prev = dummy;

        Node* temp = dummy;

        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data != x) {
                temp = temp->next;
            } else {
                Node* nexti = nextin(temp->next, x);
                temp->next = nexti;
                if (nexti != NULL)
                    nexti->prev = temp;
            }
        }

        *head_ref = dummy->next;
        if (*head_ref != NULL)
            (*head_ref)->prev = NULL;

        delete dummy;
    }
};
