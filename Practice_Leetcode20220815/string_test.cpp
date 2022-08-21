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

string a = "asd";
for (int i = 0; i<a.size(); i++){}

char a[5] = "asd";
for(int i=0; a[i]!='\0'; i++){}

void reverseString(vector<char>& s){
    for(int i=0, j=s.size()-1;i<s.size()/2;i++,j--){
        swap(s[i],s[j]);
        [int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;]
    }
}

char a[5] = "asd";
for(int i=0; a[i]!='\0'; i++){

}

string a = "asd";
for(int i=0; i<a.size(); i++){
    
}

//替换空格
// #include <string>
class Solution {
public:
    string replaceSpace(string s) {
        string str2 = "%20";
        // string::iterator it;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                s.replace(i,1,str2);
                // s.insert(i,'%20');
                // s.insert(0,1,'c');
            }
        }
        return s;
    }
};

// 剑指Offer05.替换空格
class Solution {
public:
    string ReplaceSpace(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        int old_size = s.size();
        s.resize(old_size + count*2);
        int new_size = s.size();
        for (int i = new_size-1, j = old_size-1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i]=s[j];
            } else {
                s[i]='0';
                s[i-1]='2';
                s[i-2]='%';
                i-=2;
            }
        }
        return s;
    }
};

int ORBSLAM3::ORBMatch(int a, int b) {
    Hello();
}

int ORBSLAM3::ORBExactor(int a,
                         int b,
                         int c) {
    HelloWorld();
)

int ORBSLAM3::ORBAccellrate(
        int a,
        int b,
        int c) {
    HelloWorld();
}

// 151. 颠倒字符串中的单词
class Solution{
public:
    string SwapString(string& s, int start, int end) {
        if (start < 0 || end >= s.size()) {
            return;
        }
        for (int i = start, j = end; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
        return s;
    }

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

    string ReverseWords(string& s) {
        int count = s.size();
        for (int i = 0; i < count; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        SwapString(s, 0, s.size()-1);
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (s[j] == ' ' || j == s.size()-1) {
                SwapString(s, i, j-1);
                i = j+1;
            } 
        }

        return s;

    }
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
        // return s;
    }

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
        // 删掉多余空格即可
        // int count = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == ' ') {
        //         count++;
        //     }
        // }

        RemoveExtraSpaces(s);

        // s.resize(s.size()-count)；
        return s;
    }
};

void RemoveExtraSpaces(string& s) {
    int slow_index = 0, fast_index = 0;
    // 去掉字符串前面的空格
    while (s.size() > 0 
            && fast_index < s.size() 
            && s[fast_index] == ' ') {
        fast_index++;    
    }
    for (; fast_index < s.size(); fast_index++) {
        // 去掉字符串中间部分的冗余空格
        if (fast_index - 1 > 0 
                && s[fast_index - 1] == s[fast_index] 
                && s[fast_index] == ' ') {
            continue;
        } else {
            s[slow_index++] = s[fast_index];
        }
    }
    // 去掉字符串末尾的空格
    if (slow_index - 1 > 0 && s[slow_index - 1] == ' ') {
        s.resize(slow_index - 1);
    } else {
        s.resize(slow_index);
    }    
}

// 数组二分法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (end >= 1) {
            if (target < nums[end/2]) {
                end = end/2 - 1;
            } else if (target == nums[end/2]) {
                return end/2;
            } else {
                start = end/2;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle -1;    
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};





