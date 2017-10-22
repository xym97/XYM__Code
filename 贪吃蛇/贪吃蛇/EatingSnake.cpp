#include<iostream>
#include<vector>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

using namespace std;

enum
{
	Up,
	Down,
	Left,
	Right
};

typedef struct Coordi
{
	int _x;
	int _y;
	Coordi(int x = 0, int y = 0)
		:_x(x)
		,_y(y)
	{}

	Coordi& operator = (const Coordi& s)
	{
		_x = s._x;
		_y = s._y;
		return *this;
	}

	bool operator == (const Coordi& s)
	{
		return (_x == s._x && _y == s._y);
	}

}Coordi ;



void movehandle(int x, int y)//运用windows系统调用将光标移动到（x, y）这个坐标位置上
{
	COORD cd;//windows中表示光标位置的结构体变量
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
	//从标准输出中找到光标的位置 重新设置为cd；
}

class Snake
{
public:
	Snake(int row, int col)
		:_row(row)
		,_col(col)
	{
		_map = new char*[_row];
		for (size_t i = 0; i < _row; i++)
		{ 
			_map[i] = new char[_col];
		}
	}

	~Snake()
	{
		for (size_t i = 0; i < _row; ++i)
		{
			delete[] _map[i];
		}
		delete[] _map;
	}
private:
	void Setmap()
	{
		for (size_t i = 0; i < _row; ++i)
		{
			for (size_t j = 0; j < _col; ++j)
				_map[i][j] = ' ';
		}

		/*for (size_t i = 0; i < _row; ++i)
		{
			for (size_t j = 0; j < _col; ++j){
				if (i == 0 || i == _row - 1)
					_map[i][j] = '#';
				if (j == 0 || j == _col - 1)
					_map[i][j] = '#';
			}
		}*/
		for (size_t i = 0; i < _row; ++i){
			_map[i][_col - 1] = '#';
			_map[i][0] = '#';
		}
		for (size_t i = 0; i < _col; ++i){
			_map[0][i] = '#';
			_map[_row - 1][i] = '#';
		}
	}

	bool CheckAccess()
	{
		if (_snake[0]._x > 0 && _snake[0]._y > 0 && _snake[0]._x < _row \
			&& _snake[0]._y < _col)
		{
			for (size_t i = 1; i < _snake.size(); ++i){
				if (_snake[0] == _snake[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}

	void Setfood()
	{
		int x = 0;
		int y = 0;
		while (_map[x][y] != ' ')
		{
			srand((unsigned int)time(NULL));
			x = rand() % _row;
			srand((unsigned int)time(NULL));
			y = rand() % _col;
		}
		movehandle(x, y);
		printf("%c", 5);
		_food._x = x;
		_food._y = y;
	}

	void Printmap()
	{
		Setmap();
		for (size_t i = 0; i < _row; ++i){
			for (size_t j = 0; j < _col; ++j)
				cout << _map[i][j];
		cout << endl;
		}
		size_t x = 1;
		size_t y = 1;
		movehandle(x, y);
		cout << 'O';
		_snake.push_back(Coordi(x, y));
		status = Right;
	}

	void DrawSnake(int status)
	{
		for (size_t i = 0; i < _snake.size(); ++i){
			movehandle(_snake[i]._x, _snake[i]._y);
			cout << ' ';
		}

		switch (status)
		{
		case Up:
			for (size_t i = _snake.size() - 1; i > 0;--i){
				_snake[i] = _snake[i - 1];
			}
			_snake[0]._y -= 1;
			break;
		case Down:
			for (size_t i = _snake.size() - 1; i > 0; --i){
				_snake[i] = _snake[i - 1];
			}
			_snake[0]._y += 1;
			break;
		case Left:
			for (size_t i = _snake.size() - 1; i > 0; --i){
				_snake[i] = _snake[i - 1];
			}
			_snake[0]._x -= 1;
			break;
		case Right:
			for (size_t i = _snake.size() - 1; i > 0; --i){
				_snake[i] = _snake[i - 1];
			}
			_snake[0]._x += 1;
			break;
		}

		if (!CheckAccess())
			exit(1);

		for (size_t i = 0; i < _snake.size(); ++i){
			movehandle(_snake[i]._x, _snake[i]._y);
			cout << 'O';
		}
			
	}
public:
	void Play()
	{
		Printmap();
		Setfood();
		while (1)
		{
			if (GetAsyncKeyState(VK_UP) && status != Up)
				status = Up;
			if (GetAsyncKeyState(VK_DOWN) && status != Down)
				status = Down;
			if (GetAsyncKeyState(VK_LEFT) && status != Left)
				status = Left;
			if (GetAsyncKeyState(VK_RIGHT) && status != Right)
				status = Right;
			if (_snake[0] == _food){
				_snake.push_back(_snake.back());//STL的迭代器是左闭右开的
				Setfood();
			}
			DrawSnake(status);
			Sleep(200);
		}
	}
private:
	Coordi _food;
	char** _map;
	unsigned int _row;
	unsigned int _col;
	int status;
	vector<Coordi> _snake;
};




int main()
{
	Snake s(20,40);
	s.Play();
	system("pause");
	return 0;
}