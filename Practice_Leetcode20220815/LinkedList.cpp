struct LinkedNode
{
    /* data */
    int val;
    LinkedNode* next;
    LinkedNode(int x):val(x),next(nullptr){}
};


class MyLinkedList{
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };

    MyLinkedList(){
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index > ( _size - 1 ) || index<0 ){
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val){
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val){
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr ){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;

    }

    void addAtIndex(int index, int val){
        if(index>_size){
            return;
        }

        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;

    }

    void deleteAtIndex(int index){
        if(index >= _size || index<0 ){
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    void printLinkedList(){
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cout << cur->next->val << "";
            cur = cur->next;
        }
        cout << endl;

    }

private:
    int _size;
    LinkedNode* _dummyHead;

}

// 移除元素
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while( cur->next != NULL ){
            if( cur->next->val ==val ){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
}

// 判断链表是否存在环，返回环入口
class solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while( fast!=nullptr && fast->next!=nullptr ){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
}