#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};

ListNode* buildlist(int arr[],int n){
    if(n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i = 1;i < n;i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printlist(ListNode* head){
    ListNode* cur = head;
    while(cur != NULL){
        cout << cur->val;
        if(cur->next)cout << "->";
        cur = cur->next;
    }
    cout << endl;
}

class Solution {
public:
    /*
    the shortest subarray that confirms to the sum
    */
    int minSubArrayLen(int s ,vector<int> & nums){ 
        int res = INT32_MAX;
        int length = 0;
        int sum = 0;
        int j = 0; //begin
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            while(sum >= s){
                length = i-j+1;
                res = res < length ? res:length;
                sum -= nums[j];
                j++; 
            }
        }
        return res == INT32_MAX ? 0: res;
    }

    ListNode * swapPairs(ListNode* head){
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode * cur = dummyhead;

        while(cur->next != NULL && cur->next->next != NULL){
            ListNode * temp = cur->next->next->next;
            ListNode * temp1 = cur->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            temp1->next = temp;

            cur = cur->next->next;
        }
        return dummyhead->next;
    }

    /*移除倒数第n个节点*/
    ListNode * removeNthfromEnd(ListNode* head,int n){
        ListNode * dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode * slow = dummyhead;
        ListNode * fast = dummyhead;

        while(n-- && fast){  //注意这里不是fast->next
            fast = fast->next;
        }
        fast = fast->next; //remove more a step ，slow指向删除节点的上一个

        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return dummyhead->next;

    }

    /*找到相交节点*/
    ListNode * getintersectionNode(ListNode* headA, ListNode* headB){
        ListNode* curA = headA;
        ListNode* curB = headB;

        int lenA = 0, lenB = 0;

        while(curA){
            lenA++;
            curA = curA->next;
        }
        while(curB){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;

        if(lenB > lenA){          //保证A是大的，gap为正
            swap(lenA, lenB);
            swap(curA,curB);
        }

        int gap = lenA-lenB;

        while(gap--){            // ?这是对的
            curA = curA->next;  
        }

        while(curA){   //一直往下找，直到结束
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }

        return NULL;
    }

    /*判断链表环并找入口*/
    ListNode * detectCycle(ListNode * head){
        ListNode * fast = head;
        ListNode * slow = head;

        while(fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                ListNode* cur1 = head;
                ListNode* cur2 = fast;
                
                while(cur1 != cur2){
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }

                return cur1;
            }

            return NULL;
        }

    }

    /***************************************************** */
    
    /*数组哈希，判断是否为异位词*/
    bool isAnagram(string s, string t){
        int c[26] = {0};
        for(int i = 0;i < s.size();i++){
            c[s[i]-'a']++;
        }
        for(int i = 0;i < t.size();i++){
            c[t[i]-'a']--;
        }

        for(int i = 0;i < 26;i++){
            if(c[i] != 0) return false;
        }

        return true;
    }

    /*两数组交集*/
    vector<int> intersection(vector<int>&nums1,vector<int>&nums2){
        unordered_set<int> nums2_set(nums2.begin(),nums2.end());//begin()end()
        unordered_set<int> result_set;
        for(int num: nums1){
            if(nums2_set.find(num) != nums2_set.end())
            result_set.insert(num);
        }
        return vector<int>(result_set.begin(),result_set.end());//begin()end()
    }

    /*判断是否为happy数，一直找或进入循环*/
    int getSum(int n){
        int ret = 0;
        while(n){
            ret += (n%10)*(n%10);
            n /= 10;
        }
        return ret;
    }

    bool isHappy(int n){
        unordered_set<int> sum_set;

        while(1){
            int sum = getSum(n);
            if(sum == 1) return true;
            
            else if(sum_set.find(sum) != sum_set.end()) return false;

            else sum_set.insert(sum);

            n = sum;
        }
    }

};

int main()
{
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }


// ***************************************************
    // int s ;

    // cin >> s;
    // int n;
    // cin >> n;
    // vector<int> nums(n);
    // for(int i = 0; i < n;i++){
    //     cin >> nums[i];
    // }

    // Solution slu;

    // int ret = slu.minSubArrayLen(s,nums);

    // cout << ret;
//****************************************************

/**************************************************/
int arr[] = {1,2,3,4,5,6,7};
int n = sizeof(arr)/sizeof(arr[0]);
ListNode * head = buildlist(arr,n);

int arr1[]  = {1,2,3,6};
int n1 = sizeof(arr1)/sizeof(arr1[0]);
ListNode * head1 = buildlist(arr1,n1);

// ListNode * cur = head1;
// int curnum = n1 - 1;
// while(curnum--){         //指向最后一个节点
//     cur = cur->next;
// }

// ListNode * cur1 = head;
// for(int i = 0;i < 3;i++){
//     cur1 = cur1->next;
// }
// cur ->next = cur1;

// printlist(head);
// printlist(head1);

printlist(head);

Solution solution;
// ListNode * result = solution.swapPairs(head);
// ListNode* result = solution.removeNthfromEnd(head,4);
// ListNode* result = solution.getintersectionNode(head,head1);
// cout << result->val << endl;
// printlist(result);
/**************************************************/



    return 0;
}
