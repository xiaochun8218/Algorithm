#pragma once

#include "leet_code_common.h"

class Solution 
{
public:
    Solution() {};
    ~Solution() {};

    //1.����֮��
    vector<int> twoSum(vector<int>& nums, int target);

    //2.�������
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    //3.���ظ��ַ�����Ӵ�
    int lengthOfLongestSubstring(string s);

    //4.Ѱ�����������������λ��
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    //5.������Ӵ�
    string longestPalindrome(string s);

    //6.Z���α任
    string convert(string s, int numRows);

    //7.������ת
    int reverse(int x);

    //8.�ַ���ת������(atoi)
    int myAtoi(string s);

    //9.������
    bool isPalindrome(int x);

    //10.������ʽƥ��
    bool isMatch(string s, string p);

    //11.ʢ���ˮ������
    int maxArea(vector<int>& height);

    //12.����ת��������
    string intToRoman(int num);

    //13.��������ת����
    int romanToInt(string s);

    //14.�����ǰ׺
    string longestCommonPrefix(vector<string>& strs);

    //15.����֮��
    vector<vector<int>> threeSum(vector<int>& nums);

    //16.��ӽ�������֮��
    int threeSumClosest(vector<int>& nums, int target);

    //17.�绰�������ĸ���
    vector<string> letterCombinations(string digits);

    //18.����֮��
    vector<vector<int>> fourSum(vector<int>& nums, int target);

    //19.ɾ������ĵ�����N�����
    ListNode* removeNthFromEnd(ListNode* head, int n);

    //20.��Ч������
    bool isValid(string s);

    //21.�ϲ�������������
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.��������
    vector<string> generateParenthesis(int n);

    //23.�ϲ�K����������
    ListNode* mergeKLists(vector<ListNode*>& lists);
};
