//SYED MUHAMMAD ALI MUSA RAZA JAFFRI
//COMPUTER SCIENCE-B PF LAB (A) 
//19I-0684
#include<iostream>
#include<iomanip> //library for mathematical operations
#include <fstream> // library for file handling
#include <string> // using string
#include <stdlib.h> // library for exiting function

using namespace std;

void start(); // 1. function to start the game
int starting_pattern(int**); // 2. function to initialize the array with a starting pattern
void numberofgenerations( int , int** ); // 3. function to be called as per generations to be implemented
void show_board( int** ); // 4. function for showing the board or grid
void display(); // 5. function for showing the borders of the board
void neighbour_check(int** ); // 6. function to check whether a cell is alive or dead by counting the neighbours
void array_initialization(int**); // 7. To initialize the array with zeros so no garbage value appears
void deletion_of_arrays(int** , int* , int*); // 8. For deleting all the arrays once they have been used
void file_writing(int** , int ); // 9. For writing co-ordinates in a file
void menu(); // 10. A menu before the start of the game
void rules(); //11. function to call the rules of the game
int exiting(int); // 12. function to exit the game

const int g = 20 ; //size of rows or columns or grids
int **board ;
int *sec;
int *nei;
int s=100;
int n=300;
int total;

///////////////////////////////////// The main function//////////////////////////////////////////////////////////////////////////////////////
int main()
{
menu();
return 0;
}
///////////////////////////////////// 1. The starting of the game ///////////////////////////////////////////////////////////////////////////
void start()
{
int gen;

board = new int*[g];
for(int z=0 ; z<g ; z++)
{
board[z] = new int[g];
}

sec = new int [s];
nei = new int [n];

array_initialization(board);

gen = starting_pattern( board ); 

numberofgenerations( gen , board );

deletion_of_arrays(board , sec , nei); //deletion of all these arrays used in the program 

}
///////////////////////////////////// 2. The starting or given pattern of the board /////////////////////////////////////////////////////////
int starting_pattern ( int ** board )
{
int generations ;

string file_name; // variable for filename
fstream file; //variable for fstream

cout << "Enter file name (For example: filname.txt) : "; 
cin >> file_name;  // taking the filename from user

file.open(file_name); //  opening the file
	
file >>generations>>total; // reading from the file

int x , y ;

	for (int i = 0; i <total; i++) // loop for saving cordinates in 1st arrays
	{
		file >> x >> y; // saving x , y cordinates in the board array
		board[x][y] = 1; 
	}

file.close(); // closing the file

return generations;
}
///////////////////////////////////// 3. The number of generations the pattern will run for /////////////////////////////////////////////////
void numberofgenerations( int gens , int** board )
{
for(int a=0 ; a<=gens ; a++)
{
cout<<"Generation number : "<<a<<endl<<endl;

show_board ( board );
neighbour_check( board );
if(a==gens-1)
{
file_writing(board , gens );
}
}
}
//////////////////////////////////// 4. The displaing of the board /////////////////////////////////////////////////////////////////////////
void show_board ( int** board)
{

for(int x=0 ; x<g ; x++)
{

display();
	for(int y=0 ; y<g ; y++)
	{
	 cout<<board[x][y];
	}
display();
cout<<endl;

}
cout<<endl;
}
///////////////////////////////////// 5. The showing the borders of the board ///////////////////////////////////////////////////////////////
void display()
{
cout<<"|";
}


///////////////////////////////////// 6. Checking the neighbours of the cells ///////////////////////////////////////////////////////////////
void neighbour_check( int** board )
{

int b[g][g]; // 2nd array

for (int i = 0; i < g; i++) 
{
	for (int j = 0; j < g; j++) 
	{
	b[i][j] = board[i][j]; // storing values in another array
	}
}

for (int i = 0; i < g; i++) 
{
	for (int j = 0; j < g; j++)
	{
	int count = 0; 
	
		for (int l = -1; l < 2; l++) // checking neighbours in x-axis
		{
			for (int m = -1; m < 2; m++)  // checking neighbours in y-axis
			{
				if (l != 0 || m !=0 ) 
				{
					if (b[i + l][j + m] == 1) 
					{
						if ((i + l) < g && (i + l) > 0 && (j + m) < g && (j + m) > 0) // bounding checking
						{
						count++; // alive cell counter
						}
					}
				}
			}
		}
	//condition for survival or death
	if (count != 2 && count != 3) 
	{
	board[i][j] = 0; 
	}
	//condition for birth
	if (count == 3 ) 
	{
	board[i][j] = 1;
	}
	}
}

}
/////////////////////////////////////  7. To initialize the array with zeros so no garbage value appears ////////////////////////////////////
void array_initialization(int** board)
{

for(int i=0 ; i<g ; i++)//initializing with 0
{
	for(int j=0 ; j<g ; j++)
	{
	board[i][j] = 0;
	}
}

}
///////////////////////////////////// 8. Deletion of all the arrays used in the program /////////////////////////////////////////////////////
void deletion_of_arrays(int** board , int* sec , int* nei )
{

for(int p=0 ; p<g ; p++)
{
delete [] board[p];
}
delete [] board;

delete sec , nei ;

}
/////////////////////////////////////////////////// 9. File writing /////////////////////////////////////////////////////////////////////////
void file_writing( int** board , int gens )
{
total=0;
for(int h=0 ; h<g ; h++)
{
	for(int f=0 ; f<g ; f++)
	{	
		if(board[h][f]==1)
		{
		total++;
		}
	}
}

fstream fileclose;
fileclose.open("result.txt", ios::app); // creating new file for writing in it

fileclose<<gens<<endl;
fileclose<<total<<endl;

for(int h=0 ; h<g ; h++)
{
	for(int f=0 ; f<g ; f++)
	{	
		if(board[h][f]==1)
		{
		fileclose<<h<<" "<<f<<endl;
		}
	}
}
fileclose<<endl;

fileclose.close();// closing the file

}

/////////////////////////////////////////////////// 10. Menu of the game ////////////////////////////////////////////////////////////////////
void menu()
{
char E;

cout<<"##########  ' WELCOME TO THE JOHN CONVOY'S GAME OF LIFE '  ##########"<<endl<<endl; 
cout<<"_____________________________' MENU '__________________________________"<<endl<<endl<<endl;
cout<<"                        1. Start the game                         "<<endl<<endl;
cout<<"                        2. Rules of the game                      "<<endl<<endl;
cout<<"                        3. Exit the game                          "<<endl<<endl;
cout<<"Press 1 and enter to start. "<<endl;
cout<<"Press 2 and enter to see the rules of the game. "<<endl;
cout<<"Press 3 and enter to exit the game. "<<endl;
cin>>E;
if(E=='1')
{
start();
}
else if(E=='2')
{
rules();
cout<<"Now enjoy the game "<<endl<<endl;
start();
}
else if(E=='3')
{
int r=0;
exiting(r);
}

else if(E>'3' || E<'1')
{
while(E>'3' || E<'1')
{
cout<<"Please press the correct KEY. "<<endl;
cin>>E;
if(E=='1')
{
start();
}
else if(E=='2')
{
rules();
cout<<"Now enjoy the game "<<endl<<endl;
start();
}
else if(E=='3')
{
int r=0;
exiting(r);
}
}
}

}
/////////////////////////////////////////////////// 11. Rules of the game ///////////////////////////////////////////////////////////////////
void rules()
{
cout<<"________________________ 'OVERVIEW' _____________________________"<<endl;
cout<<"In this game Cells are arranged in a two-dimensional Grid "<<endl<<endl<<
"1. Two possible states for each cell : "<<endl<<
"a) Alive "<<endl<<
"b) Dead "<<endl<<
"2. States can change : "<<endl<<
"a) Living cell can die (death)."<<endl<<
"b) Dead cell can become alive (birth)."<<endl<<
"3. Simple set of rules specifying : "<<endl<<
"a) Death (overcrowding OR underpopulation)."<<endl<<
"b) Birth (reproduction)."<<endl<<endl<<
"The game starts with an arbitrary pattern of cells set to live status."<<endl<<
"1. Alive cell: 1 "<<endl<<
"2. Dead  cell:  0 "<<endl<<endl<<
"_____________________________ 'RULES' __________________________________"<<endl<<
"The rules of the game are as follows : "<<endl<<
"If the cell is dead : "<<endl<<
"Rule 1 : "<<endl<<
"Birth : if exactly three of its neighbors are alive, the cell will become alive at the next step"<<endl<<
"If the cell is already alive:"<<endl<<
"Rule 2 : "<<endl<<
"Survival : if the cell has two or three live neighbors, the cell remains alive."<<endl<<
"Otherwise, the cell will die : "<<endl<<
"Rule 3 : "<<endl<<
"Death by loneliness: if the cell has only zero or one alive neighbor, the cell will become dead at the next step."<<endl<<
"Rule 4 : "<<endl<<
"Death by overcrowding: if the cell is alive and has more than three alive neighbors, the cell also dies."<<endl;

}

/////////////////////////////////////////////////// 12. For exiting the game  ///////////////////////////////////////////////////////////////
int exiting(int s )
{
cout<<"You have exited the game. "<<endl;
return s;
}

