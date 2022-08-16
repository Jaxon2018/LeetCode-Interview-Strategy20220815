struct LinkedNode{
    int val;
    LinkedNode* next;
    LinkedNode(int x):val(x),next(nullptr){}
}

LinkedNode* head = new LinkedNode(5);

class solution{
public:
    LinkedNode* deleteval( LinkedNode* head, int val ){
        LinkedNode* _dummyHead = new LinkedNode(0);
        LinkedNode* cur = _dummyHead;
        
        

    }
}

//翻转链表
class solution{
public:
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* temp;
        while( cur != nullptr )
        {
            temp = cur->next;
            cur->next = pre;

            pre = cur;
            cur = temp;
        }
        return pre;
    }
}

//移除元素
class solution{
public:
    ListNode* deleteElem( ListNode* head, int val ){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        //while(cur!=nullptr)
        while(cur->next!=nullptr)
        {
            //if(cur->next == val){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }            
        }
        // return dummyHead->next;
        // delete dummyHead;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
}


//两两交换链表节点
class solution{
public:
    // ListNode* reversedoubleNode(ListNode* head){
    ListNode* swapPairs(ListNode* head){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* tmp;
        ListNode* tmp1;
        ListNode* cur = dummyHead;
        while( cur->next != nullptr && cur->next->next != nullptr ){
            tmp = cur->next;
            tmp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            cur = cur->next->next;
        }
        // delete dummyHead;
        // return head;
        // head ListNode 已经被调换位置了，没有删除虚拟头结点；
        
        // head = dummyHead->next;
        // delete dummyHead;
        // return head;
        // 这样可能更好一些

        return dummyHead->next;
    }
}

// 删除倒数第N个节点
class solution{
public:
    ListNode* delelteNnNode(ListNode* head, int n){
        // if( n<0 || n>size)
        // {
        //     return nullptr;
        // }
        // 这里不知道链表的节点数量n
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while(n--)
        while(n--)
        {
            fast = fast->next;            
        }
        while(fast->next!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
}

// 链表相交
class solution{
public:
    ListNode* sameNode(ListNode* headA,ListNode* headB){
        ListNode* curA = headA;
        ListNode* curB = headB;
        // int numA;
        // int numB;
        // 定义变量要初始化，否则后面自加运算结果就乱了
        int numA=0;
        int numB=0;
        while(curA!=nullptr)
        {
            numA++;
            curA=curA->next;
        }
        curA = headA;
        while(curB!=nullptr)
        {
            numB++;
            curB=curB->next;
        }
        curB = headB;
        if(numB>numA)
        {
            swap(numA, numB);
            swap(curA, curB);
        }
        int gap = numA - numB;
        
        while(gap--){
            curA = curA->next;
        }
        while(curA!=nullptr){
            // if(curA->val == curB->val){
            // 要求是指针相同
            if(curA == curB){
                return curA;
            }
            //增加
            curA = curA->next;
            curB = curB->next;
            //
        }
        return nullptr;
    }
}


// 判断链表是否存在环，返回环入口
class solution{
Public:
    ListNode* detectCycle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while( fast!=nullptr && fast->next->next!=nullptr ){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                ListNode* index1=fast;
                ListNode* index2=head;
                while(index1 != index2){
                    index1=index->next;
                    index2=index->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
}