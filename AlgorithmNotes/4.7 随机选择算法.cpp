/**
* 随机选择算法
* 对任何输入都可以达到O(n)的期望时间复杂度
**/

/**
* 问题：给定一个由整数组成的集合，集合中的整数各不相同，现在要将它分为两个子集合，
*       使得这两个子集合的并为原集合、交为空集，
*       同时在两个子集合的元素个数n1与n2之差的绝对值|n1-n2|尽可能小的前提下，
*       要求它们各自的元素之和S1和S2之差的绝对值|S1-S2|尽可能大，求|S1-S2|等于多少
**/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int A[maxn], n; //A存放所有整数，n为其个数

//选取随机主元，对区间[left,right]进行划分
int randPartition(int A[], int left, int right) {
    int p = round(1.0 * rand() / RAND_MAX * (right - left) + left); //生成[left,right]内的随机数p
    swap(A[p], A[left]); //交换A[p]和A[left]
    //以下为原先Partition函数的划分过程，不需要改变任何东西
    int temp = A[left]; //将A[left]存放至临时变量temp
    //只要left与right不相遇
    while (left < right) {
        while (left < right && A[right] > temp)
            right--; //反复左移right
        A[left] = A[right]; //将A[right]挪到A[left]
        while (left < right && A[left] <= temp)
            left++; //反复右移left
        A[right] = A[left]; //将A[left]挪到A[right]
    }
    A[left] = temp; //把temp放到left与right相遇的地方
    return left; //返回相遇的下标
}

//随机选择算法，从A[left,right]中找到第K大的数，并进行切分
void randSelect(int A[], int left, int right, int K) {
    if (left == right)
        return; //边界
    int p = randPartition(A, left, right); //划分后主元的位置为p
    int M = p - left + 1; //A[p]是A[left,right]中的第M大
    if (K == M)
        return; //找到第K大的数
    if (K < M)
        randSelect(A, left, p - 1, K); //第K大的数在主元左侧，往主元左侧找第K大
    else
        randSelect(A, p + 1, right, K - M); //第K大的数在主元右侧，往主元右侧找第K-M大
}

int main() {
    srand((unsigned)time(NULL)); //初始化随机数种子
    int sum = 0, sum1 = 0; //sum和sum1记录所有整数之和与切分后前n/2个元素之和
    scanf("%d", &n); //整数个数
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); //输入整数
        sum += A[i]; //累计所有整数之和
    }
    randSelect(A, 0, n - 1, n / 2); //寻找第n/2大的数，并进行切分
    for (int i = 0; i < n / 2; i++)
        sum1 += A[i]; //累计较小的子集合中元素之和
    printf("%d\n", (sum - sum1) - sum1); //求两个子集合的元素和之差
    return 0;
}
