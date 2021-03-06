/**
* 关键路径：AOE网中的最长路径
*          （强调：关键路径就是AOE网的最长路径）
**/

//顶点活动(AOV)网：用顶点表示活动，而用边集表示活动间优先关系的有向图
//边活动(AOE)网：用带权的边集表示活动，而用顶点表示事件的有向图，其中边权表示完成活动需要的时间

//关键活动：关键路径上的活动

//最长路径问题：即Longest Path Problem，寻求的是图中的最长简单路径

//求解有向无环图(DAG)中最长路径的方法“先求点，再夹边”
//关键路径，不是有向无环图返回-1，否则返回关键路径长度
int CriticalPath() {
    memset(ve, 0, sizeof(ve)); //ve数组初始化
    if (topologicalSort() == false)
        return -1; //不是有向无环图，返回-1
    fill(vl, vl + n, ve[n - 1]); //vl数组初始化，初始值为汇点的ve值
    //直接使用topOrder出栈即为逆拓扑序列，求解vl数组
    while (!topOrder.empty()) {
        int u = topOrder.top(); //栈顶元素为u
        topOrder.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].v; //u的后继结点v
            //用u的所有后继结点v的vl值来更新vl[u]
            if (vl[v] - G[u][v].w < vl[u])
                vl[u] = vl[v] - G[u][v].w;
        }
    }
    //遍历邻接表的所有边，计算活动的最早开始时间e和最迟开始时间l
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].v, w = G[u][v].w;
            int e = ve[u], l = vl[v] - w; //活动的最早开始时间e和最迟开始时间i
            //如果e==1，说明活动u->v是关键活动
            if (e == 1)
                printf("%d->%d\n", u, v); //输出关键活动
        }
    }
    return ve[n - 1]; //返回关键路径长度
}
