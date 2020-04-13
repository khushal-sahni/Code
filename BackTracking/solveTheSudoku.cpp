//correct solution below

#include <bits/stdc++.h>
using namespace std;

bool vacantPath(vector<vector<int> > &mat, int &r,int &c)
{
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			if(mat[r][c]==0)
			return true;
		}
	}
	return false;
}

void printGrid(vector<vector<int> > &grid)
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("%d ", grid[row][col]);
    }
}

bool isValid(vector<vector<int> > &mat,int row,int col ,int val)
{
 int i,j;
  for(i = 0; i < 9; i++)if(mat[row][i] == val) return false;
  for(i = 0; i < 9; i++)if(mat[i][col] == val) return false;
  int a = (row/3) * 3, b = (col/3) * 3;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(mat[a+i][b+j] == val) return false;
    }
  }
  return true;
}

bool solve(vector<vector<int> > &mat)
{

	int row,col;
	if(!vacantPath(mat,row,col)){
			printGrid(mat);
		return true;
	}

		for(int i=1;i<=9;i++)
		{

			if(isValid(mat,row,col,i)){
				mat[row][col]=i;

				if(solve(mat))
				return true;
				mat[row][col]=0;
			}
		}

	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		vector<vector<int> > mat(90);


		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
		{
			int k;
			cin>>k;
			mat[i].push_back(k);
		}
		}
		solve(mat);
		cout<<endl;
	}
	// your code goes here
	return 0;
}



//below code is not fast enough //////////////////////////************************
#include <iostream>
#include <vector>
using namespace std;

bool isValid(int val, int r, int c, vector <vector <int>> sudoku){
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

bool vacantPath(vector<vector<int> > &mat, int &r,int &c)
{
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			if(mat[r][c]==0)
			return true;
		}
	}
	return false;
}

void printGrid(vector<vector<int> > &grid)
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("%d ", grid[row][col]);
    }
}

bool func(vector <vector <int>> sudoku){

  int row,col;
	if(!vacantPath(sudoku,row,col)){
			printGrid(sudoku);
		return true;
	}



    for(int i = 1; i <= 9; i++){
      if(isValid(i, row,col, sudoku)){
        sudoku[row][col] = i;
        if(func(sudoku)) return true;
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
    vector <vector <int>>sudoku(9, vector <int> (9,0));
    for(i = 0; i < 9; i++) for(j = 0; j < 9; j++)cin >> sudoku[i][j];
    if(!func(sudoku)) cout << "-1";
    cout << "\n";
  }
}
