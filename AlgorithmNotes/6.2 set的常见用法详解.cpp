/**
*  set：翻译为集合，是一个内部自动有序且不含重复元素的容器
**/
#include <cstdio>
#include <set>
using namespace std;


//set的定义
set<int> name;
set<double> name;
set<char> name;
set<node> name; //node是结构体的类型
set<typename> Arrayname[arraySize]; //set数组的定义


//set容器内元素的访问（只能通过迭代器iterator访问）
{
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    //注意，不支持it < st.end()的写法
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d ", *it); //2 3 5
    return 0;
}


//set常用函数实例解析
//insert()
//示例参见“set容器内元素的访问”
//find()
{
    set<int> st;
    for (int i = 1; i <= 3; i++)
        st.insert(i);
    set<int>::iterator it = st.find(2); //在set中查找2，返回其迭代器
    printf("%d\n", *it);
    //以上两句也可以直接写成printf("%d\n",*(st.find(2)))
    return 0;
}
//erase()
//删除单个元素
{
    set<int> st;
    st.insert(100);
    st.insert(200);
    st.insert(100);
    st.insert(300);
    st.erase(st.find(100)); //利用find()函数找到100，然后用erase删除它
    st.erase(st.find(200)); //利用find()函数找到200，然后用erase删除它
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d\n", *it); //300
    return 0;
}
{
    set<int> st;
    st.insert(100);
    st.insert(200);
    st.erase(100); //删除set中值为100的元素
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d\n", *it); //200
    return 0;
}
//删除一个区间内的所有元素
{
    set<int> st;
    st.insert(20);
    st.insert(10);
    st.insert(40);
    st.insert(30);
    set<int>::iterator it = st.find(30);
    st.erase(it, st.end()); //删除元素30至set末尾之间的元素，即30和40
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d\n", *it); //10 20
    return 0;
}
//size()
{
    set<int> st;
    st.insert(2);
    st.insert(5);
    st.insert(4);
    printf("%d\n", st.size()); //输出set内元素的个数
    return 0;
}
//clear()
{
    set<int> st;
    st.insert(2);
    st.insert(5);
    st.insert(4);
    st.clear(); //清空set
    printf("%d\n", st.size()); // 0
    return 0;
}


//set的常见用途
//最主要的作用是自动去重并按升序排序，因此碰到需要去重但是却不方便直接开数组的情况，可以尝试用set解决
//延伸：set中元素是唯一的，如果需要处理不唯一的情况，则需要使用multiset
//      另外C++11标准中还增加了unordered_set，以散列代替set内部的红黑树(Red Black Tree)实现，用来处理只去重但不排序的需求，速度比set快得多
