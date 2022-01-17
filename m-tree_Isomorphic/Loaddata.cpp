#include"Loaddata.h"

int load_data(string filename, string temp[])
{
    ifstream infile;
    infile.open(filename, ios::in);
    int cnt = 0;
    while (!infile.eof())                   // 若未到文件结束一直循环 
    {
        getline(infile, temp[cnt], '\n');   //读取一行，以换行符结束，存入 temp[] 中
        cnt++;                              //下一行
    }
    infile.close();
    return cnt;
}

//提取每一行中包含的父节点和子节点，父节点保存在left中，right保存在子节点中
void deal_data(string temp[], string left[], string right[],int cnt)
{
    for (int i = 0;i < cnt;i++)
    {
        int length = temp[i].find('-');
        left[i] = temp[i].substr(0, length);
        right[i] = temp[i].substr(length + 2, temp[i].length());
    }

}