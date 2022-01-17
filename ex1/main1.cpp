
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "BarChart.h"
#include <fstream>
#include <string>
#include <sstream>
#include<iostream>
using namespace Graph_lib;

//------------------------------------------------------------------------------
Simple_window win(Point(100,100),1000,1000,"Canvas");
void barchart(double data[], double data1[]);
int main()
{  
    ifstream fp("C:\\Users\\Administrator.DESKTOP-2RFB03T\\Desktop\\wenti\\9\\Austin.csv"); //绝对路径
    ifstream fp1("C:\\Users\\Administrator.DESKTOP-2RFB03T\\Desktop\\wenti\\9\\NewYork.csv");//绝对路径
    string line;
    getline(fp,line);
    getline(fp1,line);
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    double data[12]={0},data1[12]={0};
    double day[366],day1[366];
    int count = 0;
    while (getline(fp,line)){ 
        string number;
        istringstream readstr(line); 
        for(int j = 0;j < 2;j++){ 
            getline(readstr,number,',');
            if(j==1)
                {
                    day[count] = atof(number.c_str());
                }
        }
        count++;
    }
    count = 0;
    while (getline(fp1,line)){ 
        string number;
        istringstream readstr(line); 
        for(int j = 0;j < 2;j++){ 
            getline(readstr,number,',');
            if(j==1)
                {
                    day1[count] = atof(number.c_str());
                }
        }
        count++;
    }
    count = 0;
    for (int j = 0; j < 12; j++)
    {
        for (int i = 0; i < month[j]; i++)
        {
            data[j] = data[j] + day[count];
            data1[j] = data1[j] + day1[count];
            count++;
        }
        
    }
    for (int i = 0; i < 12; i++)
    {
        data[i] = data[i] / month[i];
        data1[i] = data1[i] / month[i];
    }
    //BarChart b(24, "temperature", "date");
    win.wait_for_button();
    int n = 24;
    Axis xa(Axis::x, Point(100, 500), (n + 3) * 15, (n + 3),"month");
    xa.label.move(100, 20);
    Axis ya(Axis::y, Point(100, 500), 400, 8,   "temperature" );
    win.attach(xa);
    win.attach(ya);
    win.wait_for_button();
    barchart(data, data1);
    
}
void barchart(double data[],double data1[])
{

    int i = 0;
    Text t1(Point(80, 505), "0");
    win.attach(t1);
    Text t2(Point(80, 455), "5");
    win.attach(t2);
    Text t3(Point(80, 405), "10");
    win.attach(t3);
    Text t4(Point(80, 355), "15");
    win.attach(t4);
    Text t5(Point(80, 305), "20");
    win.attach(t5);
    Text t6(Point(80, 255), "25");
    win.attach(t6);
    Text t7(Point(80, 205), "30");
    win.attach(t7);
    Text t8(Point(80, 155), "35");
    win.attach(t8);
    Text t9(Point(80, 105), "40");
    win.attach(t9);
    win.wait_for_button();

    Text r1(Point(130, 515), "1");
    win.attach(r1);
    Text r2(Point(160, 515), "2");
    win.attach(r2);
    Text r3(Point(190, 515), "3");
    win.attach(r3);
    Text r4(Point(220, 515), "4");
    win.attach(r4);
    Text r5(Point(250, 515), "5");
    win.attach(r5);
    Text r6(Point(280, 515), "6");
    win.attach(r6);
    Text r7(Point(310, 515), "7");
    win.attach(r7);
    Text r8(Point(340,515), "8");
    win.attach(r8);
    Text r9(Point(370, 515), "9");
    win.attach(r9);
    Text r10(Point(400, 515), "10");
    win.attach(r10);
    Text r11(Point(430, 515), "11");
    win.attach(r11);
    Text r12(Point(460, 515), "12");
    win.attach(r12);
    win.wait_for_button();

    Closed_polyline aus1, ny1;
    aus1.add(Point((2 * i + 1) * 15 + 100, 500));
    aus1.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus1.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus1.add(Point((2 * i + 1) * 15 + 115, 500));
    aus1.set_fill_color(Color::blue);
    win.attach(aus1);
    win.wait_for_button();
    ny1.add(Point((2 * i + 1) * 15 + 115, 500));
    ny1.add(Point((2 * i + 1) * 15 + 115, 500 - data1[i] * 10));
    ny1.add(Point((2 * i + 1) * 15 + 130, 500 - data1[i] * 10));
    ny1.add(Point((2 * i + 1) * 15 + 130, 500));
    ny1.set_fill_color(Color::cyan);
    win.attach(ny1);
    win.wait_for_button();
    i++;

    Closed_polyline aus2, ny2;
    aus2.add(Point((2 * i + 1) * 15 + 100, 500));
    aus2.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus2.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus2.add(Point((2 * i + 1) * 15 + 115, 500));
    aus2.set_fill_color(Color::blue);
    win.attach(aus2);
    win.wait_for_button();
    ny2.add(Point((2 * i + 1) * 15 + 115, 500));
    ny2.add(Point((2 * i + 1) * 15 + 115, 500 - data1[i] * 10));
    ny2.add(Point((2 * i + 1) * 15 + 130, 500 - data1[i] * 10));
    ny2.add(Point((2 * i + 1) * 15 + 130, 500));
    ny2.set_fill_color(Color::cyan);
    win.attach(ny2);
    win.wait_for_button();
    i++;

    Closed_polyline aus3, ny3;
    aus3.add(Point((2 * i + 1) * 15 + 100, 500));
    aus3.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus3.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus3.add(Point((2 * i + 1) * 15 + 115, 500));
    aus3.set_fill_color(Color::blue);
    win.attach(aus3);
    win.wait_for_button();
    ny3.add(Point((2 * i + 1) * 15 + 115, 500));
    ny3.add(Point((2 * i + 1) * 15 + 115, 500 - data1[i] * 10));
    ny3.add(Point((2 * i + 1) * 15 + 130, 500 - data1[i] * 10));
    ny3.add(Point((2 * i + 1) * 15 + 130, 500));
    ny3.set_fill_color(Color::cyan);
    win.attach(ny3);
    win.wait_for_button();
    i++;

    Closed_polyline aus4, ny4;
    aus4.add(Point((2 * i + 1) * 15 + 100, 500));
    aus4.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus4.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus4.add(Point((2 * i + 1) * 15 + 115, 500));
    aus4.set_fill_color(Color::blue);
    win.attach(aus4);
    win.wait_for_button();
    ny4.add(Point((2 * i + 1) * 15 + 115, 500));
    ny4.add(Point((2 * i + 1) * 15 + 115, 500 - data1[i] * 10));
    ny4.add(Point((2 * i + 1) * 15 + 130, 500 - data1[i] * 10));
    ny4.add(Point((2 * i + 1) * 15 + 130, 500));
    ny4.set_fill_color(Color::cyan);
    win.attach(ny4);
    win.wait_for_button();
    i++;

    Closed_polyline aus5, ny5;
    aus5.add(Point((2 * i + 1) * 15 + 100, 500));
    aus5.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus5.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus5.add(Point((2 * i + 1) * 15 + 115, 500));
    aus5.set_fill_color(Color::blue);
    win.attach(aus5);
    win.wait_for_button();
    ny5.add(Point((2 * i + 1) * 15+115, 500));
    ny5.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny5.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny5.add(Point((2 * i + 1) * 15+130, 500));
    ny5.set_fill_color(Color::cyan);
    win.attach(ny5);
    win.wait_for_button();
    i++;


    Closed_polyline aus6, ny6;
    aus6.add(Point((2 * i + 1) * 15 + 100, 500));
    aus6.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus6.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus6.add(Point((2 * i + 1) * 15 + 115, 500));
    aus6.set_fill_color(Color::blue);
    win.attach(aus6);
    win.wait_for_button();
    ny6.add(Point((2 * i + 1) * 15+115, 500));
    ny6.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny6.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny6.add(Point((2 * i + 1) * 15+130, 500));
    ny6.set_fill_color(Color::cyan);
    win.attach(ny6);
    win.wait_for_button();
    i++;

    Closed_polyline aus7, ny7;
    aus7.add(Point((2 * i + 1) * 15 + 100, 500));
    aus7.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus7.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus7.add(Point((2 * i + 1) * 15 + 115, 500));
    aus7.set_fill_color(Color::blue);
    win.attach(aus7);
    win.wait_for_button();
    ny7.add(Point((2 * i + 1) * 15+115, 500));
    ny7.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny7.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny7.add(Point((2 * i + 1) * 15+130, 500));
    ny7.set_fill_color(Color::cyan);
    win.attach(ny7);
    win.wait_for_button();
    i++;

    Closed_polyline aus8, ny8;
    aus8.add(Point((2 * i + 1) * 15 + 100, 500));
    aus8.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus8.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus8.add(Point((2 * i + 1) * 15 + 115, 500));
    aus8.set_fill_color(Color::blue);
    win.attach(aus8);
    win.wait_for_button();
    ny8.add(Point((2 * i + 1) * 15+115, 500));
    ny8.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny8.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny8.add(Point((2 * i + 1) * 15+130, 500));
    ny8.set_fill_color(Color::cyan);
    win.attach(ny8);
    win.wait_for_button();
    i++;

    Closed_polyline aus9, ny9;
    aus9.add(Point((2 * i + 1) * 15 + 100, 500));
    aus9.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus9.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus9.add(Point((2 * i + 1) * 15 + 115, 500));
    aus9.set_fill_color(Color::blue);
    win.attach(aus9);
    win.wait_for_button();
    ny9.add(Point((2 * i + 1) * 15+115, 500));
    ny9.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny9.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny9.add(Point((2 * i + 1) * 15+130, 500));
    ny9.set_fill_color(Color::cyan);
    win.attach(ny9);
    win.wait_for_button();
    i++;

    Closed_polyline aus10, ny10;
    aus10.add(Point((2 * i + 1) * 15 + 100, 500));
    aus10.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus10.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus10.add(Point((2 * i + 1) * 15 + 115, 500));
    aus10.set_fill_color(Color::blue);
    win.attach(aus10);
    win.wait_for_button();
    ny10.add(Point((2 * i + 1) * 15+115, 500));
    ny10.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny10.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny10.add(Point((2 * i + 1) * 15+130, 500));
    ny10.set_fill_color(Color::cyan);
    win.attach(ny10);
    win.wait_for_button();
    i++;

    Closed_polyline aus11, ny11;
    aus11.add(Point((2 * i + 1) * 15 + 100, 500));
    aus11.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus11.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus11.add(Point((2 * i + 1) * 15 + 115, 500));
    aus11.set_fill_color(Color::blue);
    win.attach(aus11);
    win.wait_for_button();
    ny11.add(Point((2 * i + 1) * 15+115, 500));
    ny11.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny11.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny11.add(Point((2 * i + 1) * 15+130, 500));
    ny11.set_fill_color(Color::cyan);
    win.attach(ny11);
    win.wait_for_button();
    i++;

    Closed_polyline aus12, ny12;
    aus12.add(Point((2 * i + 1) * 15 + 100, 500));
    aus12.add(Point((2 * i + 1) * 15 + 100, 500 - data[i] * 10));
    aus12.add(Point((2 * i + 1) * 15 + 115, 500 - data[i] * 10));
    aus12.add(Point((2 * i + 1) * 15 + 115, 500));
    aus12.set_fill_color(Color::blue);
    win.attach(aus12);
    win.wait_for_button();
    ny12.add(Point((2 * i + 1) * 15+115, 500));
    ny12.add(Point((2 * i + 1) * 15+115, 500-data1[i]*10));  
    ny12.add(Point((2 * i + 1) * 15+130, 500-data1[i]*10));      
    ny12.add(Point((2 * i + 1) * 15+130, 500));
    ny12.set_fill_color(Color::cyan);
    win.attach(ny12);
    win.wait_for_button();
    i++;

}


//------------------------------------------------------------------------------
