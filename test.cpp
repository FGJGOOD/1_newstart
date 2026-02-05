#include <iostream>
#include <vector>
#include <string>

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

cout << " this is the new test for new branch " << endl;

for(int i = 0; i < 4; i++){
    cout << i*i ;
}
cout << endl;

/**************************************************/
int arr[] = {1,2,3,4,5,6,7};
int n = sizeof(arr)/sizeof(arr[0]);
ListNode * head = buildlist(arr,n);

printlist(head);

Solution solution;
ListNode * result = solution.swapPairs(head);

printlist(result);
/**************************************************/



    return 0;
}
