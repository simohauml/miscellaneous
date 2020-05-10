#include <iostream>

using std::cout;
using std::endl;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry {0};
        auto p1 = l1;
        auto p2 = l2;
        ListNode* pResult = new ListNode(0);
        ListNode* pNode = pResult;
        while( NULL != p1 || NULL != p2) {
            int a1 = NULL == p1 ? 0 : p1->val;
            int a2 = NULL == p2 ? 0 : p2->val;
            int sum = a1 + a2 + carry;
            carry = sum / 10;
            pNode->next = new ListNode(sum % 10);
            pNode = pNode->next;
            p1 = NULL == p1 ? NULL : p1->next;
            p2 = NULL == p2 ? NULL : p2->next;
        }
        if(carry > 0) {
            pNode->next = new ListNode(carry);
        }
        auto result = pResult->next;
        delete(pResult);
        return result;
    }
    };
int main() {
    // First number
    ListNode s1_0 { 2 };
    ListNode s1_1 { 4 };
    ListNode s1_2 { 3 };
    s1_0.next = &s1_1;
    s1_1.next = &s1_2;
    ListNode* ps1 = &s1_0;

    // Second number
    ListNode s2_0 { 5 };
    ListNode s2_1 { 6 };
    ListNode s2_2 { 4 };
    s2_0.next = &s2_1;
    s2_1.next = &s2_2;
    ListNode* ps2 = &s2_0;

    ListNode* r = Solution::addTwoNumbers(ps1, ps2);

    while(r != NULL) {
        cout << r->val;
        r = r->next;
    }

    cout << endl;

    return 0;
}


//class Solution {
//public:
//    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        int carry { 0 };
//        int add { 0 };
//        ListNode* pResult = new ListNode(0);
//        ListNode* pNode = pResult;
//        // Loop for adding numbers in each link list
//        while( (NULL != l1) || (NULL != l2)) {
//            if((NULL == l1) && (NULL != l2)) {
//                add = l2->val + carry;
//                if(add < 10) {
//                    carry = 0;
//                    pNode->val = add;
//                    if(NULL == l2->next) {
//                        pNode->next = NULL;
//                    } else {
//                        pNode->next = new ListNode(0);
//                        pNode = pNode->next;
//                    }
//                } else {
//                    carry = 1;
//                    pNode->val = add - 10;
//                    if(NULL == l2->next) {
//                        pNode->next = new ListNode(1);
//                        pNode = pNode->next;
//                    }
//                    else {
//                        pNode->next = new ListNode(0);
//                        pNode = pNode->next;
//                    }
//                }
//                l2 = l2->next;
//            } else if((NULL != l1) && (NULL == l2)) {
//                add = l1->val + carry;
//                if(add < 10) {
//                    carry = 0;
//                    pNode->val = add;
//                    if(NULL == l1->next) {
//                        pNode->next = NULL;
//                    } else {
//                        pNode->next = new ListNode(0);
//                        pNode = pNode->next;
//                    }
//                } else {
//                    carry = 1;
//                    pNode->val = add - 10;
//                    if(NULL == l1->next) {
//                        pNode->next = new ListNode(1);
//                        pNode = pNode->next;
//                    } else {
//                        pNode->next = new ListNode(0);
//                        pNode = pNode->next;
//                    }
//                }
//                l1 = l1->next;
//            } else {
//                add = l1->val + l2->val + carry;
//                if(add < 10) {
//                    carry = 0;
//                    pNode->val = add;
//                    if((NULL == l1->next) && (NULL == l2->next)) {
//                        pNode->next = NULL;
//                    } else {
//                        pNode->next = new ListNode(0);
//                        pNode = pNode->next;
//                    }
//                } else {
//                    carry = 1;
//                    pNode->val = add - 10;
//                    if((NULL == l1->next) && (NULL == l2->next)) {
//                        pNode->next = new ListNode(1);
//                        pNode = pNode->next;
//                    } else {
//                        pNode->next = new ListNode(0);
//                        pNode = pNode->next;
//                    }
//                }
//                l1 = l1->next;
//                l2 = l2->next;
//            }
//        }
//
//        return pResult;
//    }
//};

