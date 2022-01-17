#include"isomorphic.h"

bool error_(string a, string b)
{
    bool flag1 = 0, flag2 = 0;
    if (a.length() % 2 == 1)
    {
        flag1 = 1;
    }
    if (b.length() % 2 == 1)
    {
        flag2 = 1;
    }
    string str = a;
    int n = a.length(), count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            count++;
        }
        else if (str[i] == '0')
        {
            count--;
        }
        if (count < 0)
        {
            flag1 = 1;
            break;
        }

    }
    if (count != 0)
    {
        flag1 = 1;
    }
    str = b;
    n = b.length();
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            count++;
        }
        else if (str[i] == '0')
        {
            count--;
        }
        if (count < 0)
        {
            flag2 = 1;
            break;
        }

    }
    if (count != 0)
    {
        flag2 = 1;
    }
    if (re0(a, 0) != a.length() - 1)
    {
        flag1 = 1;
    }
    if (re0(b, 0) != b.length() - 1)
    {
        flag2 = 1;
    }

    return (flag1 + flag2);
}

int re0(string str, int n)
{
    int count = 0;
    if (str[n] == '0')
    {
        return n;
    }
    for (int i = n; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            count++;
        }
        else if (str[i] == '0')
        {
            count--;
        }
        if (str[i] == '0' && count == 0)
            return i;
    }
    return -1;
}
int re1(string str, int n)
{
    int count = 0;
    count = re0(str, n);
    if (str[n] == '1')
    {
        return n;
    }
    for (int i = count; i > 0; i--)
    {
        if (str[i] == '0')
        {
            count++;
        }
        else if (str[i] == '1')
        {
            count--;
        }

        if (str[i] == '1' && count == re0(str, n))
        {
            return i;
        }
    }

    return-1;
}

int compare(string a, string b, int a_1, int a_0, int b_1, int b_0, int flag)
{
    int a1, a0, b1, b0;
    if ((a_0 - a_1) != (b_0 - b_1) || a[a_1] != '1' || a[a_0] != '0' || b[b_1] != '1' || b[b_0] != '0')
    {
        return 1;
    }
    else
        if ((a_0 - a_1) == 1)
            return 0;
        else
        {

            a1 = re1(a, a_1 + 1);
            a0 = re0(a, a_1 + 1);
            b1 = re1(b, b_1 + 1);
            b0 = re0(b, b_1 + 1);
            if (a0 == b0 && flag == 0)
            {

                if (compare(a, b, a1, a0, b1, b0, 1) == 1)
                {
                    return 1;
                }
                if (compare(a, b, a0 + 1, a_0 - 1, b0 + 1, b_0 - 1, 1) == 1)
                {
                    return 1;
                }

            }
            else if (a0 != b0 && flag == 0)
            {
                if (compare(a, b, a1, a0, b0 + 1, re0(b, b0 + 1), 1) == 1)
                {
                    return 1;
                }
                if (compare(a, b, a0 + 1, re0(a, a0 + 1), b1, re0(b, b1), 1) == 1)
                {
                    return 1;
                }
            }
            else
                if (a0 == b0 && flag == 1)
                {
                    if (compare(a, b, a1, a0, b1, b0, 1) == 1)
                    {
                        return 1;
                    }
                    if (compare(a, b, a0 + 1, re0(a, a0 + 1), b0 + 1, re0(b, b0 + 1), 1) == 1)
                    {
                        return 1;
                    }

                }



        }
    return 0;
}

bool isomorphic_(string a, string b)
{
    if (error_(a, b) == 0)
    {
        if (a == b)
        {
            return true;
        }
        else
            if (compare(a, b, 0, a.length() - 1, 0, b.length() - 1, 0) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}