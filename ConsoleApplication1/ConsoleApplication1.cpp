// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

union myun
{
    struct { int x; int y; int z; }u;
    int k;
}a;

/// <summary>
/// 给你一个 升序排列的数组nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
/// 由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
/// 
/// 更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。
/// 将最终结果插入 nums 的前 k 个位置后返回 k
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return 1;
    }
    int numIndex = 1;
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            nums[numIndex++] = nums[i];
        }
    }

    return numIndex;
}


/// <summary>
/// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
/// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。你也可以先购买，然后在 同一天 出售。
/// 返回 你能获得的 最大 利润 。
/// </summary>
/// <param name="prices"></param>
/// <returns></returns>
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }

    int curIndex = 0;

    int sum = 0;
    while (curIndex < n - 1) {
        if (prices[curIndex + 1] > prices[curIndex])
        {
            sum += prices[curIndex + 1] - prices[curIndex];
        }
        curIndex++;
    }
    return sum;
}

/// <summary>
/// 旋转数组
/// 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
/// </summary>
/// <param name="nums"></param>
/// <param name="k"></param>
void rotate1(vector<int>& nums, int k) {

    int n = nums.size();
    k = k % n;
    vector<int> orgNums;

    for (int val : nums)
    {
        orgNums.push_back(val);
    }

    for (size_t i = 0; i < n; i++)
    {
        nums[(i + k) % n] = orgNums[i];
    }
}

void reverseArr(vector<int>& nums, int startIndex, int endIndex) {
    while (startIndex < endIndex) {
        swap(nums[startIndex], nums[endIndex]);
        startIndex++;
        endIndex--;
    }
}

/// <summary>
/// 数组翻转方式实现
/// </summary>
/// <param name="nums"></param>
/// <param name="k"></param>
void rotate2(vector<int>& nums, int k) {

    int n = nums.size();
    k = k % n;
    reverseArr(nums, 0, n - 1);
    reverseArr(nums, 0, k - 1);
    reverseArr(nums, k, n - 1);
}

void rotate3(vector<int>& nums, int k) {

    int len = nums.size();
    k %= len;
    if (k == 0 || len == 1) return;
    int temp;
    temp = nums[0];
    int count = 0;
    for (int i = k, cnt = 0; cnt < len; i += k, cnt++)
    {
        int t = nums[i % len];
        nums[i % len] = temp;
        temp = t;
        if (i % len == count)
        {
            count++;
            i = count;
            temp = nums[(i) % len];
        }
    }
}

/// <summary>
/// 判断同一数组中任意个元素是否出现至少两次则返回true,
/// 否则返回false
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// 异或
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int singleNumber(vector<int>& nums) {
    int val = 0;
    for (int num : nums)
    {
        val ^= num;
    }
    return val;
}

/// <summary>
/// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
/// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
/// 你可以假设除了整数 0 之外，这个整数不会以零开头。
/// </summary>
/// <param name="digits"></param>
/// <returns></returns>
vector<int> plusOne(vector<int>& digits) {
    int cnt = digits.size();

    int sum = 0;
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i] += 1;
            return digits;
        }
        else {
            digits[i] = 0;
        }
    }

    //没有return表示数组中所有的数都为9
    vector<int> newVec(cnt + 1);
    newVec[0] = 1;

    return newVec;
}

/// <summary>
/// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
/// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
/// </summary>
/// <param name="nums"></param>
void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

/// <summary>
/// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
/// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
/// 你可以按任意顺序返回答案。
/// </summary>
/// <param name="nums"></param>
/// <param name="target"></param>
/// <returns></returns>
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hashmap;
    for (int i = 0; i < nums.size(); ++i)
        if (hashmap.count(target - nums[i]))
            return { hashmap[target - nums[i]], i };
        else
            hashmap[nums[i]] = i;
    return {};
}

/// <summary>
/// 判断9*9的9宫格是否是有效的数独
/// </summary>
/// <param name="board"></param>
/// <returns></returns>
bool isValidSudoku(vector<vector<char>>& board) {
    int cnt = board.size();

    //每行每个单元格的二维数组
    vector<vector<int>> line(cnt, vector<int>(cnt));
    //每列每个单元格的二维数组
    vector<vector<int>> column(cnt, vector<int>(cnt));
    //每个九宫格的每个单元格的二维数组
    vector<vector<int>> group(cnt, vector<int>(cnt));

    //遍历每行
    for (int i = 0; i < cnt; i++)
    {
        //遍历每列
        for (int j = 0; j < cnt; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            //计算得到当前单元格属于哪一个九宫格
            int k = i / 3 * 3 + j / 3;
            //计算得到当前单元格数值,在上述3格二维数组中的下标,
            //用于统计是否含有这个数字了
            int num = board[i][j] - '0' - 1;

            //如果当前下标中的数字不是0,这表示该行or该列or该单元格包含了这个数值
            if (line[i][num] != 0 || column[j][num] != 0 || group[k][num] != 0)
            {
                return false;
            }

            line[i][num] = column[j][num] = group[k][num] = 1;
        }
    }
    return true;
}

/// <summary>
/// 判断9*9的9宫格是否是有效的数独, 位运算解法
/// </summary>
/// <param name="board"></param>
/// <returns></returns>
bool isValidSudoku2(vector<vector<char>>& board) {

    int line[9] = { 0 };
    int column[9] = { 0 };
    int group[9] = { 0 };

    //遍历每行
    for (int i = 0; i < 9; i++)
    {
        //遍历每列
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            //计算得到当前单元格属于哪一个九宫格
            int k = i / 3 * 3 + j / 3;
            //计算得到当前单元格数值,在上述3格二维数组中的下标,
            //用于统计是否含有这个数字了
            int num = 1 << (board[i][j] - '0');

            //如果当前下标中的数字不是0,这表示该行or该列or该单元格包含了这个数值
            if ((line[i] & num) != 0 || (column[j] & num) != 0 || (group[k] & num) != 0)
            {
                return false;
            }

            line[i] |= num;
            column[j] |= num;
            group[k] |= num;

        }
    }
    return true;
}

/// <summary>
/// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
/// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像
/// </summary>
/// <param name="matrix"></param>
void rotate(vector<vector<int>>& matrix) {

    int size = matrix.size();
    for (size_t i = 0; i < size / 2; i++)
    {
        for (size_t j = i; j < size - i - 1; j++)
        {
            int temp = matrix[i][j];

            //矩阵当前单元格对角的元素的下标位置
            int m = size - j - 1;
            int n = size - i - 1;

            matrix[i][j] = matrix[m][i];
            matrix[m][i] = matrix[n][m];
            matrix[n][m] = matrix[j][n];
            matrix[j][n] = temp;
        }

    }


}

/// <summary>
/// 反转字符串
/// </summary>
/// <param name="s"></param>
void reverseString(vector<char>& s) {

    for (size_t i = 0; i < s.size() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;

    }
}

/// <summary>
/// 整数反转
/// 1323 3231
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
int reverse(int x) {

    long ret = 0;
    while (x != 0) {

        int num = x % 10;

        if ((x /= 10) != 0) {
            ret = (ret + num) * 10;
        }
        else {
            ret += num;
        }
    }

    if ((int)ret != ret)
    {
        return 0;
    }

    return ret;
}

/// <summary>
/// 找到字符串中第一个不重复的字符。
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
int firstUniqChar(string s) {

    //map<int, int> hashmap;

    //for (char c : s)
    //{
    //    hashmap[c]++;
    //}

    //for (size_t i = 0; i < s.length(); i++)
    //{
    //    if (hashmap[s[i]] == 1) {
    //        return i;
    //    }
    //}
    //return -1;

    int a[26] = { 0 };
    int index[26];
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        a[s[i] - 'a']++;
        index[s[i] - 'a'] = i;
    }
    for (int i = 0; i < size; i++)
    {
        if (a[s[i] - 'a'] == 1)
        {
            return index[s[i] - 'a'];
        }
    }
    return -1;
}

/// <summary>
/// 判断两个字符串是不是异位字符串:出现的字母及字母的个数相同
/// </summary>
/// <param name="s"></param>
/// <param name="t"></param>
/// <returns></returns>
bool isAnagram(string s, string t) {
    if (s.length() != t.length())
    {
        return false;
    }
    map<int, int> sMap;
    map<int, int> tMap;

    for (char c : s) {
        sMap[c]++;
    }

    for (char c : t) {
        tMap[c]++;
    }

    for (auto it : sMap) {
        if (tMap.find(it.first) == tMap.end())
        {
            return false;
        }
        else {
            if (tMap.find(it.first)->second != it.second)
            {
                return false;
            }
        }
    }

    return true;
}

/// <summary>
/// 是否是回文字符串
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool isPalindrome(string s) {
    
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            left++;
        while (left < right && !isalnum(s[right]))
            right--;

        if (toupper(s[left]) != toupper(s[right]))
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int myAtoi(string s) {

}

int main()
{
    //cout << "Hello World!\n";
    //int var = 20;
    //int* ip;
    //ip = &var;
    //cout << "Value of val varible:";
    //cout << var << endl;

    //cout << "Address stored in ip variable:";
    //cout << ip << endl;

    //cout << "Value of *ip variable:";
    //cout << *ip << endl;

    //a.u.x =4;
    //a.u.y =5; 
    //a.u.z =6; 
    //a.k = 0; //覆盖掉第一个int空间值
    //printf("%d %d %d %d\n",a.u.x,a.u.y,a.u.z,a.k);

    //int age = 19;
    //int* p_age = &age;
    //*p_age = 20;

    //printf("age = %d\n", *p_age);
    //printf("age = %d\n", age);

    //vector<int> nums = { 1,0,0,4,5,0,7,1 };
    //bool bRet = containsDuplicate(nums);
    //rotate3(nums, 3);
    //moveZeroes(nums);

    //vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };

    //rotate(matrix);


    //reverse(-123);

    isPalindrome(" ");

    return 0;


}

