#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string.h>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() :val(0), next(nullptr){}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};