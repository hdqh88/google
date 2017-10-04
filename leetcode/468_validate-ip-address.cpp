//Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
//
//IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
//
//Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
//
//IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
//
//However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
//
//Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
//
//Note: You may assume there is no extra space or special characters in the input string.
//
//Example 1:
//    Input: "172.16.254.1"
//
//    Output: "IPv4"
//
//    Explanation: This is a valid IPv4 address, return "IPv4".
//Example 2:
//    Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
//
//    Output: "IPv6"
//
//    Explanation: This is a valid IPv6 address, return "IPv6".
//Example 3:
//    Input: "256.256.256.256"
//
//    Output: "Neither"
//
//    Explanation: This is neither a IPv4 address nor a IPv6 address.

#include <iostream>
#include <vector>

using namespace std;

class Solution_468 {
public:
    // 2 Pointers
    // Exp: https://discuss.leetcode.com/topic/74888/c-simple-solution
    // Time:	O(n)
    // Space:	O(1)
    string validIPAddress(string IP) {
        if (validIPv4(IP)) return "IPv4";
        if (validIPv6(IP)) return "IPv6";
        return "Neither";
    }

    bool validIPv4(string &IP) {
        int begin = 0, end = 0, cnt = 0;
        while (end < IP.size()) {
            int leadingZeroCount = 0, num = 0;
            while (end < IP.size() && isdigit(IP[end])) {
                num = num * 10 + IP[end] - '0';
                if (IP[end] == '0' && num == 0) leadingZeroCount++;
                if ((leadingZeroCount > 0 && num != 0)
                    || leadingZeroCount > 1
                    || end - begin + 1 > 3
                    || num > 255) return false;
                ++end;
            }
            if (end == begin) return false;
            ++cnt;
            if (cnt <= 3) {
                if (end >= IP.size() || IP[end] != '.') return false;
                begin = ++end;
            } else if (end != IP.size()) return false;
        }
        return cnt == 4;
    }

    bool validIPv6(string &IP) {
        int cnt = 0, begin = 0, end = 0;
        while (end < IP.size()) {
            while (end < IP.size() && isalnum(IP[end])) {
                if ((IP[end] > 'f' && IP[end] <= 'z')
                    || (IP[end] > 'F' && IP[end] <= 'Z')
                    || end - begin + 1 > 4) return false;
                ++end;
            }
            if (begin == end) return false;
            ++cnt;
            if (cnt <= 7) {
                if (end >= IP.size() || IP[end] != ':') return false;
                begin = ++end;
            } else if (end != IP.size()) return false;
        }
        return cnt == 8;
    }
};