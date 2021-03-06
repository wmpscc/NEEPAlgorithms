/**
* KMP算法：解决字符串的匹配问题
**/

//next数组
//求解长度为len的字符串s的next数组
void getNext(char s[], int len) {
    int j = -1;
    next[0] = -1; //初始化j=next[0]=-1
    for (int i = 1; i < len; i++) {
        //求解next[1]-next[len-1]
        while (j != -1 && s[i] != s[j + 1])
            j = next[j]; //反复令j=next[j]，直到j回退到-1，或是s[i]==s[j+1]
        //如果s[i]==s[j+1]
        if (s[i] == s[j + 1])
            j++; //则next[i]=j+1，先令j指向这个位置
        next[i] = j; //令next[i]=j
    }
}

//KMP算法
//判断pattern是否是text的子串
bool KMP(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern); //字符串长度
    getNext(pattern, m); //计算pattern的next数组
    int j = -1; //初始化j为-1，表示当前还没有任意一位被匹配
    for (int i = 0; i < n; i++) {
        while (j != -1 && text[i] != pattern[j + 1])
            j = next[i]; //不断回退，直到j回到-1或text[i]==pattern[j+1]
        if (text[i] == pattern[j + 1])
            j++; //text[i]与pattern[j+1]匹配成功，令j加1
        if (j == m - 1)
            return true; //pattern完全匹配，说明pattern是text的子串
    }
    return false; //执行完text还没匹配成功，说明pattern不是text的子串
}

//从有限状态自动机的角度看待KMP算法
