
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int isMoreThan500(int i)
{
    return (i > 500);
}

vector<int> function()
{
    ifstream file;
    file.open("numbers.txt");
    if (!file.is_open())
        std::cout << "Error opening file";
    istream_iterator<int> it(file);
    istream_iterator<int> eos;
    vector<int> v;
    copy(it, eos, back_inserter(v));
    int cnt = count_if(v.begin(), v.end(), isMoreThan500);
    cout << cnt << endl;
    cout << *min_element(v.begin(), v.end()) << endl;
    cout << *max_element(v.begin(), v.end()) << endl;
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++)
        if (v[i] >= 300)
        {
            v.erase(v.begin(), v.begin() + i);
            break;
        }
    sort(v.rbegin(), v.rend());
    return v;
}

int main()
{
    vector<int> v;
    v = function();
    return 0;
}


