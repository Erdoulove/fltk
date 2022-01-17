#include<iostream>
#include<string>
#include<fstream>
#include<queue>
using namespace std;
#define MAX_SIZE 150
#define MAX_SIZE_SON 20

//双亲表示法

struct PTNode
{
    string data; //自身数据
    int parent=-1;  //指向父母下标
    int x = -1;
    int y = -1; //维护自己的位置
    int son = 0; //记录子节点数目
    int child[MAX_SIZE_SON]; //保存孩子下标
    int data_isomorphic = -1; //记录同构的结点位置
};
struct PTree
{
    PTNode nodes[MAX_SIZE];  //树
    int length=0; //结点数
    PTree() {};
};


//以下为双亲表示法涉及的函数
//检查树中是否有重复节点
bool pt_checkrepeat(PTree* p, string str);
//向双亲表示的树中加入新节点
void pt_insert(PTree* p, string str);
//找到对应节点的下标
int pt_find(PTree* p, string str);
//找到根节点
int pt_find_root(PTree* p, string str);
//建立起父子关系，并简单判断是否存在节点有两个父节点
bool pt_build(PTree* p, string left[], string right[],int cnt);
//判断构建的树中是否有环，是否为连通
bool pt_check_error(PTree* p);
//建立起双亲表达法的树，并判断其是否合法
bool pt_init(PTree* p, string left[], string right[], int cnt);
//维护结点位置信息
void pos(PTree *p,int i, double x, double y);
//返回当前节点的深度 根节点深度为0
int pt_depth(PTree* p, int i);
//检查在画节点时，所占位置是否已经被占据
bool pt_check(PTree* p, int current, int x_left, int y_left,int r);
//把当前结点的孩子结点入队
void pt_enqueue_child(PTree* p, queue<int> *q, int current);
//把当前树表示成括号序列
void pt_brackets(PTree* p, string& str, int current);
//找到某结点的儿子
void pt_find_childs(PTree* p, int x);
