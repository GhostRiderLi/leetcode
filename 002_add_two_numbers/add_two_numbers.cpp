#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtest/gtest.h>
struct ListNode {
     int val;
     struct ListNode *next;
};

void printList(struct ListNode* list) {
    struct ListNode* lst = list;
    while(lst != NULL) {
        printf("%d", lst->val);
        if (lst->next == NULL) {
            printf("\n");
        } else {
            printf(",");
        }
        lst = lst->next;
    }
}

struct ListNode* creatList(int* array, int len) {
    struct ListNode* result = NULL;
    struct ListNode* ret = NULL;
    if (len == 0) {
        return ret;
    }
    ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = array[0];
    result = ret;
    for (int i = 1; i < len; ++i) {
        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result = result->next;
        result->val = array[i];
    }
    result->next = NULL;
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0;
    int carry = 0;
    struct ListNode head;
    struct ListNode *ret = &head;
    struct ListNode* tmp;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = sum % 10;
        tmp->next = NULL;
        carry = sum / 10;
        ret->next = tmp;

        ret = ret->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return head.next;
}

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//     int carry = 0;
//     int sum = 0;
//     struct ListNode head1;
//     struct ListNode head2;
//     struct ListNode* preNode1 = &head1;
//     struct ListNode* preNode2 = &head2;
//     struct ListNode* ret = l1;
//     preNode1->val = 0;
//     preNode1->next = l1;
//     preNode2->val = 0;
//     preNode2->next = l2;

//     while (preNode1->next != NULL && preNode2->next != NULL){
//         sum = preNode1->val + preNode2->val + carry;
//         preNode1->val = sum % 10;
//         carry = sum / 10;

//         preNode1 = preNode1->next;
//         preNode2 = preNode2->next;
//     }
//     sum = preNode1->val + preNode2->val + carry;
//     preNode1->val = sum % 10;
//     carry = sum / 10;

//     if (preNode1->next == NULL) {
//         preNode1->next = preNode2->next;
//     }

//     while (carry != 0) {
//         if (preNode1->next == NULL) {
//             preNode1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//             preNode1->next->next = NULL;
//             preNode1->next->val = 0;
//         }
//         sum = carry + preNode1->next->val;
//         preNode1->next->val = sum % 10;
//         carry = sum / 10;

//         preNode1 = preNode1->next;
//     }
//     return ret;
// }


int main(int argc, char**argv) {
    int num_a[] = {1,2,3};
    int num_b[] = {1,2,3,4};
    struct ListNode* l1 = creatList(num_a, sizeof(num_a)/sizeof(int));
    struct ListNode* l2 = creatList(num_b, sizeof(num_b)/sizeof(int));

    printList(l1);
    printList(l2);

    printList(addTwoNumbers(l1,l2));

    return 0;

}


