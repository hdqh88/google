//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples:
//    "1 + 1" = 2
//    " 2-1 + 2 " = 3
//    "(1+(4+5+2)-3)+(6+8)" = 23
//Note: Do not use the eval built-in library function.

#include <iostream>
#include <stack>

using namespace std;

class Solution_224 {
public:
    // Exp: https://discuss.leetcode.com/topic/22359/16-ms-solution-in-c-with-stacks
    // Time:	O(n)
    // Space:	O(n)
    int calculate(string s) {
        stack<int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};