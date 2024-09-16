#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class code {
    private:
        int key;
    public:
        code()=delete;
        code(int skey);
        string encrypt(string &text);
        string decrypt(string &text);
};
