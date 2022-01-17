#include "Stack.hpp"

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    Stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');

    cout << "Elements present in stack : ";
    while (!s.isEmpty())
    {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}