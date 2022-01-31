#include <bits/stdc++.h>
using namespace std;

class String_check
{
private:
    int length;
    vector<string> random_s;

public:
    String_check(int length_);
    vector<string> produce_string(int x);
    bool check_string(string s);
};