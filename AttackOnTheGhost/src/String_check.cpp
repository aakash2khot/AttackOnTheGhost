#include "../include/String_check.hpp"

String_check::String_check(int length_)
{
    length = length_;
}

vector<string> String_check::produce_string(int x)
{
    string test = "words/";
    string s = ""+test + to_string(length) + "letters.txt";
    // const char *c = s.c_str();
    // cout << s << endl;
    ifstream file;
    file.open(s);
    srand((unsigned)time(NULL));

    vector<string> all;

    while (!file.eof())
    {
        string p;
        file >> p;
        all.push_back(p);
    }
    int random = rand() % all.size();

    for (int i = 0; i < x; i++)
    {
        random_s.push_back(all[random%all.size()]);
        random += 100;
    }

    return random_s;
}

bool String_check::check_string(string s)
{
    for(auto it:random_s)
    {
        if(it == s)
        {
            return true;
        }
    }

    return false;
}

// int main()
// {
//     String_check *sc = new String_check(3);
//     vector<string> s = sc->produce_string(15);
    
//     for(auto it:s)
//     {
//         cout<<it<<endl;
//     }
//     return 0;
// }