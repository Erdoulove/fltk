
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include <windows.h>
#include<math.h>
#include<string>
//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(1000,1000);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas"); 
    win.wait_for_button();
    Circle r(Point(500, 500), 100);
    Line a1(Point(500, 400), Point(500, 405));
    Line a2(Point(550, 500-86), Point(547, 500-82));
    Line a3(Point(450, 500-86), Point(500-47, 500-82));
    Line a4(Point(586, 450), Point(582, 500-47));
    Line a5(Point(414, 450), Point(416, 500-47));
    Line a6(Point(400,500), Point(405, 500));
    Line a7(Point(600, 500), Point(595, 500));
    Line a8(Point(500+86, 550), Point(500+82, 500+47));
    Line a9(Point(500-86, 550), Point(500-82, 500+47));
    Line a10(Point(500+50, 500+86), Point(500+47, 500+82));
    Line a11(Point(500-50, 500+86), Point(500-47, 500+82));
    Line a12(Point(500, 600), Point(500, 595));

    Text t1(Point(540, 500-76+5), "1");
    win.attach(t1);
    Text t2(Point(586-13, 460), "2");
    win.attach(t2);
    Text t3(Point(585, 503), "3");
    win.attach(t3);
    Text t4(Point(586-13, 545), "4");
    win.attach(t4);
    Text t5(Point(540, 500+76+5), "5");
    win.attach(t5);
    Text t6(Point(495, 590), "6");
    win.attach(t6);
    Text t7(Point(456, 500+76+5), "7");
    win.attach(t7);
    Text t8(Point(500-86+10, 545), "8");
    win.attach(t8);
    Text t9(Point(407, 505), "9");
    win.attach(t9);
    Text t10(Point(500-86+10, 465), "10");
    win.attach(t10);
    Text t11(Point(455, 500-76+5), "11");
    win.attach(t11);
    Text t12(Point(492, 420), "12");
    win.attach(t12);

    win.attach(r);
    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
    win.attach(a4);
    win.attach(a5);
    win.attach(a6);
    win.attach(a7);
    win.attach(a8);
    win.attach(a9);
    win.attach(a10);
    win.attach(a11);
    win.attach(a12);
    // give control to the display engine
    SYSTEMTIME st = { 0 };
    GetLocalTime(&st);
    double hour,minute,second;
    hour = st.wHour % 12;
    minute = st.wMinute;
    second = st.wSecond;
    string year, month, day;
    while(1)
    {
        GetLocalTime(&st);
        double hour, minute, second;
        hour = st.wHour % 12;
        minute = st.wMinute;
        second = st.wSecond;
        year = to_string(st.wYear);
        month =to_string(st.wMonth);
        day = to_string(st.wDay);

        Text t1(Point(470, 520), year);
        Text t2(Point(505, 520), "/");
        Text t3(Point(510, 520), month);
        Text t4(Point(530, 520), "/");
        Text t5(Point(535, 520), day);

        win.attach(t1);
        win.attach(t2);
        win.attach(t3);
        win.attach(t4);
        win.attach(t5);

        double s1, s2,m1,m2,h1,h2;
        s1 = 80 * sin((second / 60) * 2 * 3.1415926) + 500;
        s2 = -80 * cos((second / 60) * 2 * 3.1415926) + 500;
        m1 = 60 * sin((minute / 60) * 2 * 3.1415926) + 500;
        m2 = -60 * cos((minute / 60) * 2 * 3.1415926) + 500;
        h1 = 40 * sin((hour /12+ minute/60/12) * 2 * 3.1415926) + 500;
        h2 = -40 * cos((hour /12 +minute/60/12) * 2 * 3.1415926) + 500;
        Line l1(Point(500, 500), Point(s1, s2));
        l1.set_color(Color::blue);
        Line l2(Point(500, 500), Point(m1, m2));
        l2.set_color(Color::yellow);
        Line l3(Point(500, 500), Point(h1, h2));
        l3.set_color(Color::green);
        //Line l2(Point(500, 500), Point(500 +  int(60 * sin((minute / 60) * 2 * 3.1415926)), 500 + int(60 * cos((minute / 60) * 2 * 3.1415926))));
        //Line l3(Point(500, 500), Point(500 +  int(40*sin((hour / 60) * 2 * 3.1415926)), 500 +  int(40 * cos((hour / 60) * 2 * 3.1415926))));
        win.attach(l1);
        win.attach(l2);
        win.attach(l3);
        win.show();
        Fl::wait(1);
        Sleep(999);
        /*second++;
        if (second>=60)
        {
            second = 0;
            minute++;
        }
        if (minute>=60)
        {
            minute = 0;
            hour++;
        }
        if (hour>=12)
        {
            hour = 0;
        }*/
        
        
        win.detach(l1);
        win.detach(l2);
        win.detach(l3);
        win.show();
        Fl::redraw();
    }
    win.wait_for_button();
    
}

//g++ -I/usr/local/include -I/usr/local/include/FL/images -mwindows -DWIN32 -DUSE_OPENGL32 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -o 'main' 'main2.cpp' 'Window.cpp' 'Simple_window.cpp' 'Graph.cpp' 'GUI.cpp' -mwindows /usr/local/lib/libfltk.a -lole32 -luuid -lcomctl32 -L/usr/local/lib -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg -lfltk
