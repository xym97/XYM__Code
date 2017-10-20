#include<iostream>
#include<time.h>

#include<stdlib.h>

using namespace std;

const int N = 15;//���̴�С
const char ChessBoardFlag = ' ';
const char flag1 = 'O';
const char flag2 = 'X';

typedef struct Coordinate
{
	int x;
	int y;
}ChessCoordi;

class FiveChess
{
public:
	FiveChess()
	{
		InitChessBoard();
	}

	void Play()
	{
		ChessCoordi Pos1;
		ChessCoordi Pos2;
		while (1){
			int mode = ChoseMode();
			while (1){
				if (mode == 1){//���VS����
					static size_t count = 1;
					PalyerGo(Pos1, 1, flag1);
				    if (count++ >= 9 && GetWiner(Pos1, 1, flag1))
						break;
					ComputerGo(Pos2, flag2);
					if (count >= 10 && GetWiner(Pos2, 0, flag2))
					   break;
				}
				else if (mode == 2){//���VS���
					static size_t count = 1;
					PalyerGo(Pos1, 1, flag1);
					if (count++ >= 9 && GetWiner(Pos1,1, flag1))
						break;
					PalyerGo(Pos2,2 ,flag2);
					if (count++ >= 10 && GetWiner(Pos2,2, flag2))
						break;
				}
			}
			cout << "����һ�� y or no" << endl;
			char chose = 'y';
			cin >> chose;
			if (chose == 'n')
				break;
		}
	}

	void PrintChessBoard()
	{
		system("cls");
		for (size_t i = 0; i < N + 1; ++i)
		{
			for (size_t j = 0; j < N + 1; ++j)
			{
				if (i == 0){
					if (j != 0)
						printf("%d   ", j);
					else if (j == 0)
						printf("  ");
				}
				else if (j == 0){
					if (i != 0)
						printf("%2d", i);
				}
				else{
					printf("%c  |", ChessBoard[i][j]);
				}

			}
			cout << endl;
			cout << "  ";
			for (size_t i = 1; i < N + 1; ++i){
				cout << "---+";
			}
			cout << endl;
		}
	}

	void InitChessBoard()
	{
		for (size_t i = 0; i < N + 1; ++i){
			for (size_t j = 0; j < N + 1; ++j){
				ChessBoard[i][j] = ChessBoardFlag;
			}
		}
	}
	
protected:
	
	int ChoseMode()
	{
		system("cls");
		InitChessBoard();
		cout << "��ѡ�� 1.���VS���� 2.���VS��� 3.�Ƴ�" << endl;
		int chose = 0;
		cin >> chose;
		while (1){
			if (chose == 1)
				return chose;
			else if (chose == 2)
				return chose;
			else if (chose == 3)
				exit(1);
			else
				cout << "�Բ��� �����������󡣡�" << endl;
		}
	}

	void PalyerGo(ChessCoordi& Pos, int player, char flag)
	{
		PrintChessBoard();
		int x = 0;
		int y = 0;
		while (1){
			cout << "�����" << player << "��һ����" << endl;
			cin >> Pos.x >> Pos.y;
			if (JudgePos(Pos))
				break;
			else
				cout << "���������� ! ����������" << endl;
		}
		ChessBoard[Pos.x][Pos.y] = flag;
	}

	void ComputerGo(ChessCoordi& Pos, char flag)
	{
		PrintChessBoard();
		int x = 0;
		int y = 0;
		while (1){
			x = rand() % N + 1;
			srand((unsigned int)time(NULL));
			y = rand() % N + 1;
			srand((unsigned int)time(NULL));//���ַ�ʽ�����ɵ�x��yһ����������
			if (ChessBoard[x][y] == ChessBoardFlag)
				break;
		}
		Pos.x = x;
		Pos.y = y;
		ChessBoard[Pos.x][Pos.y] = flag;
	}

	int GetVictory(ChessCoordi Pos, char flag)//�ж��Ƿ���Ӯ��
	{
		int begin = 0;//�ڼ��Խ���ʱ ��Ϊ������Ŀ�ʼ ����
		int end = 0;
		//������Ƿ�����5����
		int beginl = 0;//�ڼ��Խ���ʱ ��Ϊ������Ŀ�ʼ ����
		int endl = 0;
		(Pos.y - 4) > 0 ? begin = Pos.y - 4 : begin = 1;
		(Pos.y + 4) < N ? end = Pos.y + 4 : end = N;
		for (size_t i = Pos.x, j = begin; j + 4 <= end; ++j)
		{
			if (flag == ChessBoard[i][j] && flag == ChessBoard[i][j + 1] && \
				flag == ChessBoard[i][j + 2] && flag == ChessBoard[i][j + 3] && \
				flag == ChessBoard[i][j + 4])
				return 1;
		}
		//������Ƿ�����5����
		(Pos.x - 4) > 0 ? begin = Pos.x - 4 : begin = 1;
		(Pos.x + 4) > N ? end = Pos.x + 4 : end = N;
		for (size_t j = Pos.y, i = begin; i + 4 <= end; ++i)
		{
			if (flag == ChessBoard[i][j] && flag == ChessBoard[i + 1][j] && \
				flag == ChessBoard[i + 2][j] && flag == ChessBoard[i + 3][j] && \
				flag == ChessBoard[i + 4][j])
				return 1;
		}

		int len = 0;
		//������Խ����Ƿ��������
		(Pos.x > Pos.y) ? len = Pos.y - 1 : len = Pos.x - 1;
		if (len > 4)//�����ӵ㵽�� �����ߵĴ�ֱ����϶̵ĵط� ��������4 ȡ4 ������4 ȡ�䱾��
			len = 4;
		begin = Pos.x - len;//���� ���ƶ��ʵ������ҿ��ܵ������ӵ���ʼλ��
		beginl = Pos.y - len;
		(Pos.x > Pos.y) ? len = N - Pos.x : len = N - Pos.y;
		if (len > 4)
			len = 4;
		end = Pos.x + len;//���� ���ƶ��ʵ������ҿ��ܵ������ӵ���ֹλ��
		endl = Pos.y + len;
		for (size_t i = begin, j = beginl; i + 4 <= end && j + 4 <= endl; ++i, ++j)
		{
			if (flag == ChessBoard[i][j] && flag == ChessBoard[i + 1][j + 1] && \
				flag == ChessBoard[i + 2][j + 2] && flag == ChessBoard[i + 3][j + 3] && \
				flag == ChessBoard[i + 4][j + 4])
				return 1;
		}
		//��鸱�Խ����Ƿ��������
		(Pos.x - 1 > N - Pos.y) ? len = N - Pos.y : Pos.x - 1;
		if (len > 4)//�����ӵ㵽�� �����ߵĴ�ֱ����϶̵ĵط� ��������4 ȡ4 ������4 ȡ�䱾��
			len = 4;
		begin = Pos.x - len;//���� ���ƶ��ʵ������ҿ��ܵ������ӵ���ʼλ��
		beginl = Pos.y + len;
		(N - Pos.x > Pos.y - 1) ? len = Pos.y - 1 : len = N - Pos.x;
		end = Pos.x + len;//���� ���ƶ��ʵ������ҿ��ܵ������ӵ�����λ��
		endl = Pos.y - len;
		for (size_t i = begin, j = beginl; i + 4 <= end && j - 4 >= endl; ++i, ++j)
		{
			if (flag == ChessBoard[i][j] && flag == ChessBoard[i + 1][j - 1] && \
				flag == ChessBoard[i + 2][j - 2] && flag == ChessBoard[i + 3][j - 3] && \
				flag == ChessBoard[i + 4][j - 4])
				return 1;
		}
		//��������Ƿ�����
		for (size_t i = 1; i < N + 1; ++i){
			for (size_t j = 1; j < N + 1; ++j){
				if (ChessBoard[i][j] == ChessBoardFlag)
					return 0;//��ʾ����û��
			}
		}
		//����
		return -1;
	}

	bool GetWiner(ChessCoordi& Pos, int player, char flag)//�ж���˭Ӯ��
	{
		int n = 0;
		n = GetVictory(Pos, flag);
		PrintChessBoard();
		if (1 == n){
			if (0 == player)
				cout << "���1��ʤ" << endl;
			else if (1 == player)
				cout << "���1��ʤ" << endl;
			else
				cout << "���Ի�ʤ"<<endl;
			return true;
		}
		else if (-1 == n){
			cout << "����" << endl;
			return true;
		}
		else{
			//��δ�ֳ�ʤ��
			return false;
		}
		
	}

	bool JudgePos(const ChessCoordi& Pos)
	{
		if (Pos.x < N + 1 && Pos.x > 0 && Pos.y < N + 1 && Pos.x > 0\
			&& ChessBoard[Pos.x][Pos.y] == ChessBoardFlag)
			return true;
		
		return false;
	}

private:
	char ChessBoard[N + 1][N + 1];
};

//#include"FiveChess.cpp"
int main()
{
	//char a[] = "exit";
	//for (size_t i = 0; i < sizeof(a) / sizeof(char);++i)
	//printf(":%d", a[i]);
	FiveChess a;
	a.InitChessBoard();
	a.PrintChessBoard();
	a.Play();
	system("pause");
	return 0;
}