//
#include "BarChart.h"
#include <string>
#include "Simple_window.h"
BarChart::BarChart(int n,string x_l,string y_l)
{
    num = n;
    x_label = x_l;
    y_label = y_l;
    count = 0;
}

Graph_lib::Closed_polyline BarChart::add(double data,string label,Color c)
{
    string str;
    str = to_string(data);
    if (data>0)
    {

        //Rectangle r1(Point((2*count+1)*15,10), 15, data);
        Graph_lib::Closed_polyline poly;
        poly.add(Point((2 * count + 1) * 15, 10));
        poly.add(Point((2 * count + 1) * 15+15, 10));
        poly.add(Point((2 * count + 1) * 15+15, 10+data));
        poly.add(Point((2 * count + 1) * 15, 10+data));
        Text t(Point((2*count+1)*15,10+data+2),str);
        Text t2(Point((2*count+1)*15+7,9),label);
        poly.set_fill_color(c);
        count = count + 1;
    }
    /*else 
    {
        Rectangle r(Point((2*count+1)*15,50-data), 15, data);
        Text t(Point((2*count+1)*15,50-data-2),str);
        Text t2(Point((2*count+1)*15+7,49),label);
        r.set_fill_color(c);
        count = count + 1;
        win.attach(r);
    }*/


}