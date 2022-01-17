//
#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
struct BarChart
{
    int num;
    int count;
    //double x_min, x_max;
    //double y_min, y_max;
    //Color x_color, y_color;
    string x_label, y_label;
    //double data[1000];
    BarChart(int n, string x_l, string y_l);
    Graph_lib::Closed_polyline add(double data,string label,Color c) ;
};
