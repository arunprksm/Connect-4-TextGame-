#include <iostream>
using namespace std;

const int ROW = 6;
const int COLUMN = 7;

class Player
{
public:
	char name;
};

class Array
{
public:
	Player p1, p2;
	char arr[9][10];
	int playerChoice, retry, full;
	bool win;

	void WelcomeFunction()
	{
		cout << "\n------------------------------\n";
		cout << "Welcome to the Connect 4 Game\n";
		cout << "Rules:\nConnect 4 is the Two players Game\nPlayer 1 will be always RED, then Player 2 is BLUE\n";
		cout << "How To Play...?\nThere are 6Rows and 7Columns\nEach Player Should select the Column between 1 and 7\nIf one of the player Conncts the 4 points Horizontally, Vertically or Diagnolly that player Wins";
		cout << "\n------------------------------\n";

	}
	void SelectPlayer()
	{
		p1.name = 'R';
		p2.name = 'B';
		win = false;
		full = 0;
		retry = 0;
	}

	int playerInput(char arr[][10], Player player)
	{
		int playerChoice;
		do
		{
			cout <<player.name <<" Enter a number between 1 and 7: ";
			cin >> playerChoice;

			while (arr[1][playerChoice] == 'R' || arr[1][playerChoice] == 'B')
			{
				cout << "Row is full, please enter a new row: ";
				cin >> playerChoice;
			}
		} while (playerChoice < 1 || playerChoice > 7);
		return playerChoice;
	}
	void CheckArray(char arr[][10], Player player, int playerChoice)
	{
		int len, chance;
		len = ROW;
		chance = 0;
		do
		{
			if (arr[len][playerChoice] != 'R' && arr[len][playerChoice] != 'B')
			{
				arr[len][playerChoice] = player.name;
				chance = 1;
			}
			else
				--len;
		} while (chance != 1);
	}

	void DisplayArray(char arr[][10])
	{
		cout << "\n------------------------------\n";
		for (int i = 1; i <= ROW; i++)
		{
			for (int j = 1; j <= COLUMN; j++)
			{
				if (arr[i][j] != 'R' && arr[i][j] != 'B')
				{
					arr[i][j] = '*';
				}
				cout << "|" << arr[i][j];
			}
			cout << "|" << endl;
		}
		for (int k = 1; k <= COLUMN; k++)
		{
			cout << " " << k << "";
		}
		cout << "\n------------------------------\n";
	}

	bool CheckFour(char arr[][10], Player player)
	{
		char ans;
		bool win;

		ans = player.name;
		win = false;

		for (int i = 8; i >= 1; --i)
		{
			for (int j = 9; j >= 1; --j)
			{

				if (arr[i][j] == ans &&
					arr[i - 1][j - 1] == ans &&
					arr[i - 2][j - 2] == ans &&
					arr[i - 3][j - 3] == ans)
				{
					win = true;
				}


				if (arr[i][j] == ans &&
					arr[i][j - 1] == ans &&
					arr[i][j - 2] == ans &&
					arr[i][j - 3] == ans)
				{
					win = true;
				}

				if (arr[i][j] == ans &&
					arr[i - 1][j] == ans &&
					arr[i - 2][j] == ans &&
					arr[i - 3][j] == ans)
				{
					win = true;
				}

				if (arr[i][j] == ans &&
					arr[i - 1][j + 1] == ans &&
					arr[i - 2][j + 2] == ans &&
					arr[i - 3][j + 3] == ans)
				{
					win = 1;
				}

				if (arr[i][j] == ans &&
					arr[i][j + 1] == ans &&
					arr[i][j + 2] == ans &&
					arr[i][j + 3] == ans)
				{
					win = true;
				}
			}
		}

		return win;
	}

	int FullArray(char arr[][10])
	{
		int full;
		full = 0;
		for (int i = 1; i <= COLUMN; ++i)
		{
			if (arr[1][i] != '*')
				++full;
		}
		return full;
	}
	int restartGame(char arr[][10])
	{
		int restart;

		cout << "Retry...? Yes(1) No(2): ";
		cin >> restart;
		if (restart == 1)
		{
			for (int i = 1; i <= ROW; i++)
			{
				for (int j = 1; j <= COLUMN; j++)
				{
					arr[i][j] = '*';
				}
			}
		}
		else
		{
			restart = 2;
			cout << "EXIT" << endl;
		}
		return restart;
	}
	void PlayerWin(Player player)
	{
		cout << endl << player.name << " Connected Four " << player.name << " Won" << endl;
	}
		
	void GameManager()
	{
		do
		{
			SelectPlayer();
			DisplayArray(arr);

			playerChoice = playerInput(arr, p1);
			CheckArray(arr, p1, playerChoice);
			DisplayArray(arr);
			win = CheckFour(arr, p1);
			if (win == true)
			{
				PlayerWin(p1);
				retry = restartGame(arr);
				if (retry == 2)
				{
					break;
				}
			}

			playerChoice = playerInput(arr, p2);
			CheckArray(arr, p2, playerChoice);
			DisplayArray(arr);
			win = CheckFour(arr, p2);
			if (win == true)
			{
				PlayerWin(p2);
				retry = restartGame(arr);
				if (retry == 2)
				{
					break;
				}
			}

			full = FullArray(arr);
			if (full == 7)
			{
				cout << "Draw..." << endl;
				retry = restartGame(arr);
			}
		} while (retry != 2);
	}
};

int main()
{
	Array* a = new Array();
	a->WelcomeFunction();
	a->GameManager();
}