#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int load_data(string filename, string temp[]);

//提取每一行中包含的父节点和子节点，父节点保存在left中，right保存在子节点中
void deal_data(string temp[], string left[], string right[],int cnt); 

