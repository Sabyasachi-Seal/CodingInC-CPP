// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l1temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* l2temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1temp = l1;
    l2temp = l2;
    int sum, temp;
    struct ListNode* final = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* head = &final;
    while (l1temp!=NULL || l2temp!=NULL){
        l1temp->val = (l1temp != NULL)?l1temp->val:0;
        l2temp->val = (l2temp != NULL)?l2temp->val:0;
        sum = l1temp->val + l2temp->val + temp;
        head->next = malloc(sizeof(struct ListNode));
        head->next->next = NULL;
        temp = 0;
        if(sum<10){
            head->next->val = sum;
        }
        else{
            temp = sum - 10;
            head->next->val=temp;
            temp = 1;
        }
        head = head->next;
    }
    return final;
}