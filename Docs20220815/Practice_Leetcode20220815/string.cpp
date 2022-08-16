//滑动窗口/双指针法，时间复杂度O(n^2)，空间复杂度O(1)
int lengthOfLongestSubstring(string s) {
    if(s.size() < 2) return s.size();
    int maxSlidingWinLen = 0;
    int head = 0, tail = 0;
    for(; tail < s.size(); ++tail) {
        //获取左边与s[tail]相同且相邻的下标
        int sameCharLoc = inSlidingWin(s, tail - head + 1, tail);
        if(sameCharLoc == -1) 
            //若是不存在，则结果取当前滑动窗口和历史滑动窗口长度最大值中的较大值
            maxSlidingWinLen = max(maxSlidingWinLen, tail - head + 1);
        else {
            //若是存在，则结果取除去相同字母区间后窗口长度和历史滑动窗口长度最大值中的较大值
            maxSlidingWinLen = max(maxSlidingWinLen, tail - sameCharLoc);
            //更新head的值
            head = sameCharLoc + 1;
        }
    }
    return maxSlidingWinLen;
}

//根据滑动窗口大小和当前tail的位置，找出tail前相邻的s[tail]的字母位置
//若是存在，则返回字母的位置下标；若是不存在，返回-1；
int inSlidingWin(const string& s, int slidingWinLen, int tail) {
    int head = tail - slidingWinLen + 1;
    while(head < tail && s[head] != s[tail]) head++;
    return head == tail ? -1 : head;
    return head == tail ? -1 : head;
}

// 151. 颠倒字符串中的单词
class Solution {
public:
    void SwapString(string& s, int start, int end) {
        if (start < 0 || end >= s.size()) {
            return;
        }
        for (int i = start, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

    // 自己没写出来，重点复习
    void RemoveExtraSpaces(string& s) {
        int slow_index = 0, fast_index = 0;
        while (s.size() > 0 && fast_index < s.size() && s[fast_index] == ' ') {
            fast_index++;
        }
        for (; fast_index < s.size(); fast_index++) {
            if (fast_index - 1 > 0 
                    && s[fast_index - 1] == s[fast_index] 
                    && s[fast_index] == ' ') {
                continue;
            } else {
                s[slow_index++] = s[fast_index];
            }
        }
        if (slow_index - 1 > 0 && s[slow_index - 1] == ' ') {
            s.resize(slow_index - 1);
        } else {
            s.resize(slow_index);
        }
    }

    string reverseWords(string& s) {
        SwapString(s, 0, s.size()-1);
        for (int i = 0, j = 0; j <= s.size(); j++) {
            if (s[j] == ' ' || j == s.size()) {
                SwapString(s, i, j-1);
                i = j+1;
            }
        }
        
        RemoveExtraSpaces(s);

        return s;
    }
};

// 0541反转字符串II
class Solition{
public:
    void Reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    string ReverseStringII(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                Reverse(s, i, i + k - 1);
                continue;
            }
            Reverse(s, i, s.size() - 1);
        }
        return s;
    }
}

// 27.移除元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                count++;
            }
        }

        int slow_index = 0, fast_index = 0;
        for (; fast_index < nums.size(); fast_index++) {
            if (nums[fast_index] == val) {
                continue;
            } else {
                nums[slow_index++] = nums[fast_index];
            }
        }
        nums.resize(nums.size() - count); 
        return nums.size();
    }
};

// 剑指 Offer 58 - II. 左旋转字符串
class Solution {
public:
    void ReverseString(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    string reverseLeftWords(string s, int n) {
        ReverseString(s, 0, n - 1);
        ReverseString(s, n, s.size() - 1);
        ReverseString(s, 0, s.size() - 1);
        return s;
    }
};

// KMP字符串匹配算法
class Solution {
public:
    void GetNext(int* next, const string& s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        GetNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

// 459.重复的子字符串
class Solution {
public:
    void GetNext(int* next, const string& s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        GetNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0) {
            return true;
        }
        return false;
    }
};
