#include "Tree.h"
bool pt_checkrepeat(PTree *p, string str)
{
    for (int i = 0; i < p->length; i++)
    {
        if (p->nodes[i].data==str)
        {
            return false;
        }    
    }
    return true;
}

void pt_insert(PTree *p, string str)
{
    if (pt_checkrepeat(p,str)==true)
    {
        p->nodes[p->length].data = str;
        p->length++;
    }
    
}

int pt_find(PTree *p, string str)
{
    for (int i = 0; i < p->length; i++)
    {
        if (p->nodes[i].data == str)
            return i;
    }
    return -3;
}

int pt_find_root(PTree *p, string str)
{
    int i_node = pt_find(p, str); //�ҵ��±�
    int count = 0;
    while (p->nodes[i_node].parent >= 0)
    {
        if (count > p->length) return -2; //-2��������ѭ��
        count++;
        i_node = p->nodes[i_node].parent;
    }
    return i_node;
}
bool pt_build(PTree *p, string left[], string right[],int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        int i_child = pt_find(p, right[i]);   //找到孩子结点下标
        int i_parent = pt_find(p, left[i]);   //找到父亲结点下标
        if (p->nodes[i_child].parent == -1)
        {
            p->nodes[i_child].parent = i_parent;  //把孩子结点指向父亲结点
            p->nodes[i_parent].child[p->nodes[i_parent].son] = i_child;
            p->nodes[i_parent].son++;
        }
        else
        {
            cout << left[i]<<" and "<< p->nodes[p->nodes[i_child].parent].data<<" are " <<p->nodes[i_child].data <<"'s parent node,the tree is illegal"<< endl;
            return false;
        }//存在结点有两个父亲
    }
    /*
    for (int i = 0; i < p->length; i++)
    {
        pt_find_childs(p, i);  //统计每个节点的孩子节点数目
    }*/
    return true;
}

bool pt_check_error(PTree *p)
{
    int i = 0;
    int count = 0; //��������ѭ����������length��������length����˵�������Ϸ�
    int root = pt_find_root(p, p->nodes[0].data);
    if (root==-2)
    {
        cout << "existing loop,the tree is illegal" << endl;
        return false;
    }
    while (i<p->length)
    {
        //��i���ڵ��Ӧ�ĸ�
        int root_i = pt_find_root(p, p->nodes[i].data);
        
        if (root_i == -2)  //存在循环
        {
            cout << "existing loop,the tree is illegal" << endl;
            return false;
        }
        else if (root!=root_i)
        {
            cout << "The tree is disconnected,the tree is illegal" << endl; //不连通
        }
        i++;
    }
    return true;
}

bool pt_init(PTree* p, string left[], string right[], int cnt)
{
    for (int i = 0;i < cnt;i++)
    {
        pt_insert(p, right[i]);  //����
        pt_insert(p, left[i]);   //����
    }

    if (pt_build(p, left, right, cnt) == false)  //有环
    {
        return 0;
    }
    else if (pt_check_error(p) == false)  return 0; //�ж��Ƿ��л�·���߲���ͨ��

    cout << "the tree is legal" << endl;
    return 1;

}

void pt_find_childs(PTree* p, int x)
{

    for (int i = 0; i < p->length; i++)
    {
        if (p->nodes[i].parent == x)
        {
            p->nodes[x].son++;
        }

    }
}

void pos(PTree* p, int i, double x, double y)
{
    p->nodes[i].x = x;
    p->nodes[i].y = y;
}

int pt_depth(PTree* p, int i)
{
    int depth = 0;
    while (p->nodes[i].parent>=0)
    {
        i = p->nodes[i].parent;
        depth++;
    }
    return depth;
}
bool pt_check(PTree* p,int current, int x_left,int y_left,int r)
{
    for (int j = 0; j < p->length; j++)
    {
        float a = p->nodes[j].x - x_left;
        float b = p->nodes[j].y - y_left;
        float c = a * a + b * b;
        if (p->nodes[j].x!=-1 && c<r*r && j!=current)
        {
            return false;
        }

    }
    return true;

}
void pt_enqueue_child(PTree* p, queue<int> *q, int current)
{
    for (int i = 0; i < p->length; i++)
    {
        if (p->nodes[i].parent == current)
            q->push(i);
    }
}

void pt_brackets(PTree* p, string& str,int current)
{
    //str = str + p->nodes[current].data;
    str = str + "0";
    for (int i = 0; i < p->nodes[current].son; i++)
    {
        pt_brackets(p, str, p->nodes[current].child[i]);
    }
    str = str + "1";
}

