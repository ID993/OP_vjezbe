

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Board {
private:
    int rows, columns;
    char** pos;
    char edge = '#';

public:  
    Board() 
    { 
        rows = 10; 
        columns = 20; 

        pos = new char* [rows];
        for (int i = 0; i < rows; i++)
            pos[i] = new char[columns];
        
        cout << "def ctor" << endl; 
    }  
    Board(int r, int c) 
    { 
        rows = r; 
        columns = c; 

        pos = new char* [r];
        for (int i = 0; i < r; i++)
            pos[i] = new char[c];

        cout << "arg ctor" << endl; 
    }
    
    Board(const Board& other)                                                                      
    {
        pos = new char* [rows = other.rows];
        *pos = new char[columns = other.columns];
        memcpy(pos, other.pos, rows * sizeof(int));
        memcpy(*pos, other.pos, columns * sizeof(int));
        cout << "cpy ctor" << endl;
    }
    
    Board(Board&& other)
    {
        pos = other.pos;
        other.pos = nullptr;
        other.rows = 0;
        other.columns = 0;
        cout << "move ctor" << endl;
    }
    
    ~Board()
    {
        delete pos;      
        cout << "del" << endl;
    }

    struct Point
    {
        double x, y;
    };

    
    void draw_char(Point p, char c)
    {
       pos[(int)p.x][(int)p.y] = c;
    }

    void draw_up_line(Point p, char c)
    {
        for (int i = (int)p.y; i < columns; i++)
                pos[(int)p.x][i] = c;
    }

    void draw_line(Point p1, Point p2, char c)
    {   
        int j = (int)p1.x;
        if (p1.y != p2.y)
        {
            for (int i = (int)p1.y; i <= (int)p2.y; i++)
                for (j; j < 20;)
                {
                    pos[j][i] = c;
                    j += round(abs(p2.x - p1.x)) / round(abs(p2.y - p1.y));
                    break;
                }
        }
        else
        {
            for (int i = (int)p1.y; i <= (int)p2.y; i++)
                for (j = (int)p1.x; j < p2.x; j++)
                    pos[j][i] = c;
        }

    }

    void display()
    {
        for (int i = 0; i < columns; i++)
            for (int j = 0; j < rows; j++)
                if (j == 0 || j == rows - 1 || i == 0 || i == columns - 1)
                    pos[j][i] = edge;

  
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
                cout << pos[j][i];
            cout << endl;
        }

    }
};


int main()
{
    Board b(20, 10);
    Board::Point p1 = { 2, 2 }, p2 = { 8, 8 }, p3 = { 2, 8 }, p4 = { 16, 8 }, p5 = { 17, 2 };
    
    
    
    b.draw_line(p1, p2, 'x');
    b.draw_line(p3, p4, 'x');
    b.draw_char(p1, 'o');
    b.draw_up_line(p5, '+');


    b.display();




    /*
    Board b;
    Board a(5,10);
    Board c(a);
    Board d = (move(b));
    */


}


