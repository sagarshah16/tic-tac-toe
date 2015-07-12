#include<iostream>
#include<string>
#include<vector>
#include <sstream>


using namespace std;
vector<vector<char>>GameBoard(3,vector<char>(3));
void DisplayBoard();

bool placeisvalid(int r , int c);
int whowon();
string columnin;
string rowin;
int row;
int column;




void main()
{
	string Player1;
	string Player2;

	int PlayerTurn = 1;
	int totalSteps = 0;


	cout << "lets play tic tac toe" << endl;
	cout << "X for Player1" << endl;
	cout << "O for Player2" << endl;


	 GameBoard[0][0] = ' ';
	 GameBoard[0][1] = ' ';
	 GameBoard[0][2] = ' ';
	 GameBoard[1][0] = ' ';
	 GameBoard[1][1] = ' ';
	 GameBoard[1][2] = ' '; 
	 GameBoard[2][0] = ' ';
	 GameBoard[2][1] = ' ';
	 GameBoard[2][2] = ' '; 

	  DisplayBoard();

	  while (whowon()==0 && totalSteps < 9)
	  {

		  do
		  {


			  if (PlayerTurn == 1)
			  {
				  cout << "Player1 Its your turn" << endl;

			  }
			  else
			  {
				  cout << "Player2 Its your turn" << endl;
			  }
			  cout << "slelect Row and Column where you have to place your symbol" << endl;
			  
			  getline(cin, rowin);
			  getline(cin, columnin);

			  			  
			  while (!((columnin == "1" || columnin == "2" || columnin == "3") && (rowin == "1" || rowin == "2" || rowin == "3")))
			  {
				  
				  
				  cout << "enter valid value for row and column" << endl;
				  DisplayBoard();
				  cin >> rowin;
				  cin >> columnin;
				 
			  }

			  stringstream(rowin) >> row;
			  stringstream(columnin) >> column;

			
		  } while (placeisvalid(row-1,column - 1) != true);

		  switch (PlayerTurn)
		  {
		  case(1) :
		  {
					  GameBoard[row - 1][column - 1] = 'x';
					  PlayerTurn = 2;

					  break;

		  }
		  case(2) :
		  {
					  GameBoard[row - 1][column - 1] = 'o';
					  PlayerTurn = 1;

		  }
		  }

		  totalSteps++;

		  DisplayBoard();

		
	  }

		  if (whowon() == 1)
		  {
			  cout << "player1 won the game" << endl;
		  }
		  else if (whowon() == 2)
		  {
			  cout << "player2 won the game" << endl;
		  }
		  else
		  {
			  cout << "game draw" << endl;
		  }

	  


}

void DisplayBoard()
{
	
	
	cout << endl;
	cout <<"  1   2   3 "<< endl;
	cout <<"1 "<< GameBoard[0][0] << " | " << GameBoard[0][1] << " | " << GameBoard[0][2] << endl;
	cout << "  --+---+--" << endl;
	cout <<"2 "<< GameBoard[1][0] << " | " << GameBoard[1][1] << " | " << GameBoard[1][2] <<endl;
	cout << "  --+---+--" << endl;
	cout << "3 "<< GameBoard[2][0] << " | " << GameBoard[2][1] << " | " << GameBoard[2][2] <<endl;
	
	cout << endl;
}

bool placeisvalid(int r,int c)
{
	
	

		if (GameBoard[r][c] != 'x' && GameBoard[r][c] != 'o')
		{
			
			return true; 
			
		}
		else
		{
			cout << "enter different slot no."<<endl;
			return false;
		}
	
}

int whowon()
{
	
	if (GameBoard[0][0]!=' ' && GameBoard[0][0] == GameBoard[0][1] && GameBoard[0][1] == GameBoard[0][2])
	{
		if (GameBoard[0][0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (GameBoard[1][0]!=' ' && GameBoard[1][0] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[1][2])
	{
		if (GameBoard[1][0] == 'x')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (GameBoard[2][0] != ' ' && GameBoard[2][0] == GameBoard[2][1] && GameBoard[2][1] == GameBoard[2][2])
		{
			if (GameBoard[2][0] == 'x')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	if (GameBoard[0][0] != ' ' && GameBoard[0][0] == GameBoard[1][0] && GameBoard[1][0] == GameBoard[2][0])
		{
			if (GameBoard[0][0] == 'x')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	if (GameBoard[0][1] != ' ' && GameBoard[0][1] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[2][1])
		{
			if (GameBoard[0][1] == 'x')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	if (GameBoard[0][2] != ' ' && GameBoard[0][2] == GameBoard[1][2] && GameBoard[1][2] == GameBoard[2][2])
		{
			if (GameBoard[0][2] == 'x')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	if (GameBoard[0][0] != ' ' && GameBoard[0][0] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[2][2])
		{
			if (GameBoard[0][0] == 'x')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	if (GameBoard[0][2] != ' ' && GameBoard[0][2] == GameBoard[1][1] && GameBoard[1][1] == GameBoard[2][0])
		{
			if (GameBoard[0][2] == 'x')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}

	return 0;
}