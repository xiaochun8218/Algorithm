#pragma once

#include "leet_code_common.h"

class Solution 
{
public:
    Solution() {};
    ~Solution() {};

    //1.两数之和
    vector<int> twoSum(vector<int>& nums, int target);

    //2.两数相加
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    //3.无重复字符的最长子串
    int lengthOfLongestSubstring(string s);

    //4.寻找两个正序数组的中位数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    //5.最长回文子串
    string longestPalindrome(string s);

    //6.Z字形变换
    string convert(string s, int numRows);

    //7.整数反转
    int reverse(int x);

    //8.字符串转换整数(atoi)
    int myAtoi(string s);

    //9.回文数
    bool isPalindrome(int x);

    //10.正则表达式匹配
    bool isMatch(string s, string p);

    //11.盛最多水的容器
    int maxArea(vector<int>& height);

    //12.整数转罗马数字
    string intToRoman(int num);

    //13.罗马数字转整数
    int romanToInt(string s);

    //14.最长公共前缀
    string longestCommonPrefix(vector<string>& strs);

    //15.三数之和
    vector<vector<int>> threeSum(vector<int>& nums);

    //16.最接近的三数之和
    int threeSumClosest(vector<int>& nums, int target);

    //17.电话号码的字母组合
    vector<string> letterCombinations(string digits);

    //18.四数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target);

    //19.删除链表的倒数第N个结点
    ListNode* removeNthFromEnd(ListNode* head, int n);

    //20.有效的括号
    bool isValid(string s);

    //21.合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.括号生成
    vector<string> generateParenthesis(int n);

    //23.合并K个升序链表
    ListNode* mergeKLists(vector<ListNode*>& lists);
};
