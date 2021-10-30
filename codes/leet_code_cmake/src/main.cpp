#include "subject.h"

Solution* solution_ptr = new Solution;

void test_isMatch(Solution* solution_ptr)
{
    string s = "aa";
    string p = "a";

    solution_ptr->isMatch(s, p);
}

void test_letterCombinations(Solution* solution_ptr)
{
    string s = "23";

    solution_ptr->letterCombinations(s);
}

int main()
{
    //test_isMatch(solution_ptr);

    test_letterCombinations(solution_ptr);

    return 0;
}