#include"Loaddata.h"

int load_data(string filename, string temp[])
{
    ifstream infile;
    infile.open(filename, ios::in);
    int cnt = 0;
    while (!infile.eof())                   // ��δ���ļ�����һֱѭ�� 
    {
        getline(infile, temp[cnt], '\n');   //��ȡһ�У��Ի��з����������� temp[] ��
        cnt++;                              //��һ��
    }
    infile.close();
    return cnt;
}

//��ȡÿһ���а����ĸ��ڵ���ӽڵ㣬���ڵ㱣����left�У�right�������ӽڵ���
void deal_data(string temp[], string left[], string right[],int cnt)
{
    for (int i = 0;i < cnt;i++)
    {
        int length = temp[i].find('-');
        left[i] = temp[i].substr(0, length);
        right[i] = temp[i].substr(length + 2, temp[i].length());
    }

}