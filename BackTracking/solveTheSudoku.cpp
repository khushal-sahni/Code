#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];

bool isValid(int val, int r, int c){
  int i,j;
  for(i = 0; i < 9; i++)if(sudoku[r][i] == val) return false;
  for(i = 0; i < 9; i++)if(sudoku[i][c] == val) return false;
  int a = (r/3) * 3, b = (c/3) * 3;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(sudoku[a+i][b+j] == val) return false;
    }
  }
  return true;
}

bool vacantPath(int &r,int &c)
{
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			if(sudoku[r][c]==0)
			return true;
		}
	}
	return false;
}

void printGrid()
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("%d ", sudoku[row][col]);
    }
}

bool func(){

  int row,col;
	if(!vacantPath(row,col)){
			printGrid();
		return true;
	}
    for(int i = 1; i <= 9; i++){
      if(isValid(i, row,col)){
        sudoku[row][col] = i;
        if(func()) return true;
        sudoku[row][col] = 0;
      }
    }
    return false;

}

int main(){
  int t;
  cin >> t;
  while(t--){
    int i,j;
    for(i = 0; i < 9; i++) for(j = 0; j < 9; j++)cin >> sudoku[i][j];
    func();
    cout << endl;
  }
  return 0;
}
