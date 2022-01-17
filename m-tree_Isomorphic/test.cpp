#include "Tree.h"
#include "Loaddata.h"
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<stack>
#include<Windows.h>
#include"Graph.h"
#include"Simple_window.h"
#include"isomorphic.h"
using namespace Graph_lib;
#define dis 500;
#define r 12
#define x1_root 450
#define x2_root 1100
#define y_ 100
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //检测鼠标点击
//将树可视化
bool visual(PTree* p, Simple_window* win, int x_init, int y_init); //可视化主函数
void draw_node(string str, Simple_window* win, int x, int y); //画结点
void draw_edge(Simple_window* win, int x_parent, int y_parent, int x_son, int y_son); //画边
void pt_color(PTree* p1, PTree* p2, int x, int y,Simple_window *win,int &color); //染色


//实现两颗同构树的结点的映射
bool pt_f(PTree* p1, PTree* p2,int root1,int root2);  //映射主函数
bool f(PTree* p1, PTree* p2, int root1, int root2);  //实现子树的映射
int main(int argc, char* argv[])
{
    cout << "Input 1 for default path , input 2 for inputing path" << endl;
    int choice;
    //cin >> choice;
    choice = 2;
    string filename1, filename2;
    if (choice == 1) //自由输入路径
    {
        cout << "input first filename:" << endl;
        cin >> filename1;
        cout << "input second filename:" << endl;
        cin >> filename2;    
    }
    else  //默认路径
    {
        filename1 = "";
        filename2 = "";
    }


    string temp[MAX_SIZE];
    string left[MAX_SIZE], right[MAX_SIZE];
    PTree* ptree1, * ptree2;
    ptree1 = new PTree;
    ptree2 = new PTree;
    int cnt1,cnt2;


    cnt1=load_data(filename1, temp);
    if (cnt1 == 0) { cout << "the tree is NULL" << endl; return 0; }
    //提取每一行中包含的父节点和子节点，父节点保存在left中，right保存在子节点中
    deal_data(temp, left, right, cnt1);

    //建立起双亲表达法的树，并判断其是否合法
    if (!pt_init(ptree1, left, right, cnt1)) return 0;

    //对第二棵树做出相同的处理
    cnt2 = load_data(filename2, temp);
    if (cnt2 == 0) { cout << "the tree is NULL" << endl; return 0; }
    deal_data(temp, left, right, cnt2);
    if (!pt_init(ptree2, left, right, cnt2)) return 0;
    

    //可视化
    
    Simple_window* win;
    win=new Simple_window(Point(0, 0), 1200, 800, "Canvas"); // make a window
    visual(ptree1, win,x1_root,y_);
    visual(ptree2, win, x2_root, y_);
   

    //获得括号序列
    string t1, t2;
    int root1 = pt_find_root(ptree1, ptree1->nodes[0].data);
    int root2 = pt_find_root(ptree2, ptree2->nodes[0].data);
    pt_brackets(ptree1, t1, root1);
    pt_brackets(ptree2, t2, root2);

    //判断同构
    /*if (isomorphic_(t1, t2)) { cout << "1" << endl; }
    else
    {
        cout << "the two trees are not isomorphic" << endl;
        return 0;
    }*/

    //实现映射
    if (pt_f(ptree1, ptree2, root1, root2)) cout << "the two tress are isomorphic" << endl;
    else
    {
        cout << "the two trees are not isomorphic" << endl;
        return 0;
    }
    //遍历映射关系
    /*for (int i=0;i < ptree1->length;i++)
    {
        int c = ptree1->nodes[i].data_isomorphic;
        cout << ptree1->nodes[i].data << " " <<ptree2->nodes[c].data  << endl;
    }*/

    POINT p;
    HWND h = GetForegroundWindow();
    int color = 60;
    while (true)
    {
        //win->show();
        if (KEY_DOWN(VK_LBUTTON)) {  //鼠标左键按下
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(h, &p);               //获取鼠标在窗口上的位置
            //printf("key down (%d,%d)\n", p.x, p.y);
            pt_color(ptree1, ptree2, p.x, p.y, win,color);
            color = color % 255;
            Fl::wait(1);
            Fl::redraw();
        }
        Sleep(100);
    }

    return 0;
}



//防重合
bool visual(PTree* p, Simple_window* win,int x_init,int y_init)
{
    int x = x_init;
    int y = y_init;
    int b = dis;
    int root = pt_find_root(p, p->nodes[0].data);
    queue<int> q;
    stack<int> s;
    int current;//parent用于找子节点，parent_last则是用于存储上一个出队的元素的父节点
    q.push(root);


    while (!q.empty())
    {
        current = q.front();
        q.pop();

        if (p->nodes[current].parent==-1)
        {
            //先把根节点画上去
            
            draw_node(p->nodes[current].data,win,x,y);
            for (int i = 0; i < p->length; i++)
            {
                if (p->nodes[i].parent == current)
                    q.push(i);
            }
            //记录位置
            pos(p,current,x,y);
        }
        else
        {

            int parent = p->nodes[current].parent;
            int n = p->nodes[parent].son;
            int x_parent = p->nodes[parent].x;
            int y_parent = p->nodes[parent].y;
            int x_left = x_parent - (n) / 2 * (2.5*r);
            int y_left = y_parent + 100; 
            
            
            if (pt_depth(p, current) == 1 && n>1)
            {
                x_left = x_parent - b / (n - 1);
            }
            pos(p, current, x_left, y_left);

            //防止重合
            while(!pt_check(p, current, x_left, y_left,2*r))
            {
             
                x_left = x_left + (2.5 * r);
                pos(p, current, x_left, y_left);
            }
            draw_node(p->nodes[current].data, win, x_left, y_left);
            draw_edge(win, x_parent, y_parent, x_left, y_left);

            //把当前节点的子节点入队
            for (int i = 0; i < p->length; i++)
            {
                if (p->nodes[i].parent == current)
                    q.push(i);
            }

            // 对当前节点的兄弟节点进行处理
            for (int i = 0;i < n - 1;i++)
            {

                current = q.front();
                q.pop();

                //把当前节点的子节点入队
                for (int j = 0; j < p->length; j++)
                {
                    if (p->nodes[j].parent == current)
                        q.push(j);
                }

                //画节点

                //x_left = x_parent - (n + 1) / 2 * 40;
                if (pt_depth(p, current) == 1 && n>1 )
                {
                    x_left = x_left + b/(n-1);
                }
                pos(p, current, x_left, y_left);

                //防止重合
                while(!pt_check(p, current, x_left, y_left,r))
                {
                    x_left = x_left + (2.5 * r);
                    pos(p, current, x_left, y_left);
                }
                draw_edge(win, x_parent, y_parent, x_left, y_left);
                draw_node(p->nodes[current].data, win, x_left,y_left);
            }


        }
    }
    return true;
}

void draw_node(string str,Simple_window* win, int x, int y)
{
    Circle* cir;
    Text* t;
    cir = new Circle(Point(x, y), r);
    cir->set_color(Color::black);
    if (str.length() == 1)
    {
        t = new Text(Point(x - r / 3, y + r / 3), str);
        t->set_font_size(13);
    }
    else
    {
        t = new Text(Point(x - r / 2, y + r / 3), str);
        t->set_font_size(11);
    }
    t->set_color(Color::black);
    t->set_font(4);
    win->attach(cir);
    win->attach(t);
}

void draw_edge(Simple_window* win, int x_parent, int y_parent, int x_son, int y_son)
{
    Line* l;
    l = new Line(Point(x_parent, y_parent + 20), Point(x_son, y_son - 20));
    l->set_color(Color::black);
    win->attach(l);
}

bool pt_f(PTree* p1, PTree* p2, int root1, int root2)
{
    p1->nodes[root1].data_isomorphic = root2;
    p2->nodes[root2].data_isomorphic = root1;
    return f(p1, p2, root1,root2);
}

bool f(PTree* p1, PTree* p2, int root1,int root2)
{
    int n1 = p1->nodes[root1].son;
    int n2 = p2->nodes[root2].son;
    if (n1 != n2) return false;
    if (n1 == 0 && n2==0)
    {
        p1->nodes[root1].data_isomorphic = root2;
        p2->nodes[root2].data_isomorphic = root1;
        return true;
    }
    int visited_num=0;
    int *visited;
    visited = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        visited[i] = 0;
    }
    //每个循环确定一个子树的同构情况
    for (int i = 0; i < n1; i++)
    {
        bool visited_i = 0;
        int a = p1->nodes[root1].child[i];

        //对比子树
        for (int j = 0; j < n2; j++)
        {
            int b = p2->nodes[root2].child[j];
            //cout << visited[j] << " " << visited_i <<" "<<p1->nodes[a].data<<" "<<p2->nodes[b].data<<endl;
            if (visited[j]==0 && f(p1, p2,a,b) && visited_i==0)
            {
                visited[j] = 1;
                visited_i = 1;
                p1->nodes[a].data_isomorphic = b;
                p2->nodes[b].data_isomorphic = a;
            }
        }

        //如果经过一次循环，没有任何一个子树匹配 那就退出
        if (visited_i == 0)
        {
            return false;
        }
    }
  
    return true;
    
}

void pt_color(PTree* p1, PTree* p2, int x, int y,Simple_window *win,int &color)
{
    int x1, y1, x2, y2;
    for (int i = 0; i < p1->length; i++)
    {
        x1 = p1->nodes[i].x;
        y1 = p1->nodes[i].y;
        x2 = p2->nodes[i].x;
        y2 = p2->nodes[i].y;
        if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r*r)
        {
            Color col(color);
            Circle* cir1;
            for (int j = 0; j < 4; j++)
            {
                cir1 = new Circle(Point(x1, y1), r - j);
                cir1->set_color(col);
                win->attach(cir1);
            }
            int x11, y11,c;
            c = p1->nodes[i].data_isomorphic;
            x11 = p2->nodes[c].x;
            y11 = p2->nodes[c].y;
            for (int j = 0; j < 4; j++)
            {
                cir1 = new Circle(Point(x11, y11), r - j);
                cir1->set_color(col);
                win->attach(cir1);
            }
            color=color+6;
        }
        else if ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) <= r*r)
        {
            Color col(color);
            Circle* cir1;
            for (int j = 0; j < 4; j++)
            {
                cir1 = new Circle(Point(x2, y2), r - j);
                cir1->set_color(col);
                win->attach(cir1);
            }
            int x22, y22,c;
            c = p2->nodes[i].data_isomorphic;
            x22 = p1->nodes[c].x;
            y22 = p1->nodes[c].y;
            for (int j = 0; j < 4; j++)
            {
                cir1 = new Circle(Point(x22, y22), r - j);
                cir1->set_color(col);
                win->attach(cir1);
            }
            color = color + 6;
           
        }
    }
}