// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

union myun
{
    struct { int x; int y; int z; }u;
    int k;
}a;

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

    /*

    */
    return 0;


}

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
void rotate(vector<int>& nums, int k) {

    int firstVal;

    for (size_t i = 0; i < k; i++)
    {
        firstVal = nums[0];
        for (size_t j = 0; j < nums.size(); j++)
        {

        }
    }
}

