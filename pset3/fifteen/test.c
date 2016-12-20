#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

void init(void);
void draw(void);
bool move(int);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }
    
    init();
    
    draw();
    
    printf("\nEnter a tile to move: ");
    int tile = GetInt();
    
    move(tile);
    
    draw();
    
    tile = GetInt();
    
    move(tile);
    
    draw();
    
}

void init(void)
{
    int num = d * d - 1;
    if((d*d-1) % 2 == 0){
        for(int i = 0; i < d; i++){
            for(int j = 0; j < d; j++){
                if(num == 0){
                }else{
                    board[i][j] = num;
                    num--;
                }
            }
        }
    }else{
        for(int i = 0; i < d; i++){
            for(int j = 0; j < d; j++){
                if(num == 2){
                    board[i][j+1] = 2;
                    num--;
                }else if(num == 1){
                    board[i][j-1] = 1;
                    num--;
                }else{
                    board[i][j] = num;
                    num--;
                }
            }
        }
    }
}

void draw(void){
    for (int i = 0; i < d; i++){
        printf("|");
        for(int j = 0; j < d; j++){
            if(board[i][j] == 0){
                printf("   _  |");
            }else if(board[i][j] > 9){
                printf("  %i  |", board[i][j]);       
            }else{
                printf("   %i  |", board[i][j]);
            }
        }
        printf("\n-");
        for(int k = 0; k < d; k++){
            printf("-------");
        }
        printf("\n");
    }
}

bool move(int tile)
{
    int emptyX, emptyY;
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if(board[i][j] == 0){
                emptyY = i;
                emptyX = j;
            }
        }
    }
    if(emptyX - 1 >= 0){
        if(board[emptyY][emptyX-1]==tile){
            board[emptyY][emptyX] = tile;
            board[emptyY][emptyX-1] = 0;
            return true;
        }
    }
    if(emptyX + 1 < d){
        if(board[emptyY][emptyX+1]==tile){
            board[emptyY][emptyX] = tile;
            board[emptyY][emptyX+1] = 0;
            return true;
        }
    }
    if(emptyY - 1 >= 0){
        if(board[emptyY-1][emptyX]==tile){
            board[emptyY][emptyX] = tile;
            board[emptyY-1][emptyX] = 0;
            return true;
        }
    }
    if(emptyY + 1 < d){
        if(board[emptyY+1][emptyX]==tile){
            board[emptyY][emptyX] = tile;
            board[emptyY+1][emptyX] = 0;
            return true;
        }
    }
    return false;
}
