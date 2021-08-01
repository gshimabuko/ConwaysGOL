/*
 *
 *
 *
 */

#include <iostream>
#include "board.h"
#include <time.h>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
int main()
{
    int initialCells{ 0 };
    //int count { 0 };
    int row{ 0 };
    int col{ 0 };
    int liveCells{ 0 };
    int neighbours{ 0 };
    std::vector<int> cellSort;
    int currentBoard[SIZE][SIZE];
    int nextBoard[SIZE][SIZE];
    std::cout << "Welcome to Conways Game of Life!\n";
    std::cout << "Your board is " << SIZE << "X" << SIZE << ".\n";
    std::cout << "Choose how many live cells do you want to start with:\n";
    do
    {
        std::cin >> initialCells;
        if ((initialCells >= 0) && (initialCells <= SIZE*SIZE))
        {
            std::cout << "You will start with " << initialCells << " live cells!\n";
        } else
        {
            std::cout << "This is not a good ammmount of cells. Pick a different number:\n";
        }
    }while(!((initialCells >= 0) && (initialCells <= SIZE*SIZE)));
    std::cout << "This is your current Board. Choose where to place your live cells: \n";
    do
    {
        currentBoard[row][col] = 0;
        nextBoard[row][col] = 0;
        if (col == SIZE -1)
        {
            row++;
            if(row != SIZE)
            {
                col = -1;
            }
        }
        col++;
    }while((row<SIZE)&&(col<SIZE));
    for(int i=0; i < SIZE*SIZE; i++)       // add 0-99 to the vector
    {
        cellSort.push_back(i);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cellSort.begin(), cellSort.end(), std::default_random_engine(seed));
    do
    {
        row = cellSort[liveCells] / SIZE;
        col = cellSort[liveCells] % SIZE;
        currentBoard[row][col] = 1;
        liveCells++;
//        std::cout << "Attempt " << count << ".\nLive cells: " << liveCells << "\n";        
    }while (liveCells < initialCells);
    row = 0;
    col = 0;
    do
    {
        if (col < SIZE - 1)
        {
            std::cout << currentBoard[row][col] << " ";
        }else
        {
            std::cout << currentBoard[row][col] << "\n";
            if (row != SIZE -1)
            {
                col = -1;
            }
            row++;
        }
        col++;
    }while((row<SIZE)&&(col<SIZE));

    std::cout << "Starting!\n";
    std::cout << "Printing second generation!\n";
    row = 0;
    col = 0;
    do
    {
        if (row == 0)
        {
            if (col == 0)
            {
                if (currentBoard[row][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col] == 1)
                {
                    neighbours++;
                }
            }
            else if ( col == SIZE - 1)
            {
                if (currentBoard[row][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col] == 1)
                {
                    neighbours++;
                }
               
            } else
            {
                if (currentBoard[row][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col - 1] == 1)
                {
                    neighbours++;
                }
            }
        } 
        else if (row == SIZE -1)
        {
            if (col == 0)
            {
                if (currentBoard[row][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col] == 1)
                {
                    neighbours++;
                }
            } else if(col == SIZE - 1)
            {
                if (currentBoard[row][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col] == 1)
                {
                    neighbours++;
                }

            } else
            {
                if (currentBoard[row][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col - 1] == 1)
                {
                    neighbours++;
                }
           }              
        }
        else
        {
            if (col == 0)
            {
                if (currentBoard[row][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col +1] == 1)
                {
                    neighbours++;
                }
            } else if (col == SIZE - 1)
            {
                if (currentBoard[row][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col - 1] == 1)
                {
                    neighbours++;
                }
           
            }
            else
            {
                if (currentBoard[row][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col - 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row - 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col + 1] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col] == 1)
                {
                    neighbours++;
                }
                if (currentBoard[row + 1][col - 1] == 1)
                {
                    neighbours++;
                }
            }                          
        }
        if (neighbours < 2)
        {
            nextBoard[row][col]=0;
        } else if (neighbours > 2)
        {
            nextBoard[row][col]=1;
        } else if(neighbours > 3)
        {
            nextBoard[row][col] = 0;
        } else
        {
            nextBoard[row][col] = currentBoard [row][col];
        }
        std::cout << nextBoard[row][col] << " ";
        if(col == SIZE - 1)
        {
            std::cout << "\n";
            if (row != SIZE -1)
            {
                col = -1;
            }
            row++;
        }
        col++;
        neighbours = 0;
    }while((row<SIZE)&&(col<SIZE));
    return(0);
}

