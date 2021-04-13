#include <stdio.h>
#include <stdlib.h>

char matrix[5][5];
																		
void init_matrix(int);																//initializing the matrix
void player1_move();																	//player's move
void player2_move();
void disp_matrix_5X5();																//displaying the current matrix															
void game_rules();                                                                  //displaying the rules of the GAME
char check_5X5();																	//checking if there is a winner																

//main function

int main()
{
	int input=5;
	char done=' ';
	char turn='X';


    	init_matrix(input);	
    	disp_matrix_5X5();
  
	

																	//initializing the matrix
	do
	{
    	if(turn=='X')
    	{
    	
    			player1_move();																//player's move
               
    			disp_matrix_5X5();															//displaying the current matrix
    			done=check_5X5();															//checking the matrix
                turn='O';
    	
    	    	if(done!=' ')
    				break;																	//if the return is other than ' ',we break here
    	
    	 
    	}
    	if(turn=='O')
    	{
    	
    			player2_move();																//player's move


    			disp_matrix_5X5();															//displaying the current matrix
    			done=check_5X5();															//checking the matrix
                turn='X';
                
    			if(done!=' ')
    				break;																	//if the return is other than ' ',we break here
	     
	    
    	}
	}while(done==' ');
    
	if(done=='X')																//if the return is 'X',user won
		printf("player1  lost\n");														
	else if(done=='O')															//if the return is 'O',computer won
		printf("player2  lost\n");													
	else if(done=='D')															//if the return is 'D',match drawn
		printf("Match Drawn\n");

	return 0;
}

//initializing the matrix

void init_matrix(int n)																	
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			matrix[i][j]=' ';													//initially all indices are made empty

}

//player's move

void player1_move()
    {
    	int x,y;
    	printf("\t player 1 turn\n\n");

    	printf("\t Enter x  co-ordinate of your move: ");
    	scanf("%d",&x);														    	//user to input the x & y co-ordinate of his move
        if(x>5 || x<1)
        {printf("\tinvalid input... input must b from 1 to 5 in digits\n");
        player1_move();}
        
    	printf("\t Enter y co-ordinate of your move: ");
    	scanf("%d",&y);	
        if(y>5 || y<1)
        {printf("\tinvalid input... input must b from 1 to 5 in digits\n");
        player1_move();}



    	if(matrix[--x][--y]!=' '){													//if his input index is not empty,invalid move is shown
    		printf("Invalid move,try again\n\n");
    		player1_move();
    	}
    	else
    		matrix[x][y]='X';														//otherwise,we put a 'X' in that index
    	printf("\n\n\n");
    
    }


void player2_move()
    {
    	int x,y;
    	printf("\t player 2 turn\n\n");

     	printf("\t Enter x  co-ordinate of your move: ");
    	scanf("%d",&x);														    	//user to input the x & y co-ordinate of his move
         if(x>5 || x<1)
        {printf("\tinvalid input... input must b from 1 to 5 in digits\n");
        player2_move();}
 
 
    	printf("\t Enter y co-ordinate of your move: ");
    	scanf("%d",&y);	
        if(y>5 || y<1)
        {printf("\tinvalid input... input must b from 1 to 5 in digits\n");
        player2_move();}


    		if(matrix[--x][--y]!=' '){											//if his input index is not empty,invalid move is shown
    		printf("Invalid move,try again\n\n");
    		player2_move();
    	}
    	else
    		matrix[x][y]='O';													//otherwise,we put a 'O' in that index
    	printf("\n\n\n");
    }


//displaying the current matrix 

void disp_matrix_5X5()
{   
    system("cls");
    printf("\n \n");

	printf("\t HLP1 PROJECT OF TIC TAC GAME OF ORDER 5X5\n\n");
	
	printf("\t To quiet the game enter 6\n\n");
	printf("\t to restart the game enter 7 \n\n");
	printf("\t For rules of the game enter 8\n\n");


	printf("\n \n");

	int i;

	for(i=0;i<5;i++){
		printf("             |     |     |     |\n");
		printf("          %c  |  %c  |  %c  |  %c  |  %c  \n",matrix[i][0],matrix[i][1],matrix[i][2],matrix[i][3],matrix[i][4]);
		if(i!=4)
			printf("        ----- ----- ----- ----- ----- \n");
	}
	printf("\n\n");
}

void game_rules()
{
    printf("\t the co-ordinates are limited from 1 to 5\n");
    printf("\t one who enters 3 adjacent entries either by row or by column or diagonally will lose the GAME\n");
    printf("\t In case of quieting the game you wouldn't be able to resume it\n\n");
    printf("\t HINTS\n\n");
    printf("\t try to cover up corners first \n\n");
    printf("\t try cover up two adjacent boxes and leave it\n\n");
    
}

//checking if there is a winner

char check_5X5()
{
	int i,j;

	//row checking
	
	//checking if the elements of rows have  identicals

	for(i=0;i<3;i++)
	{	if((matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2]))							
			return matrix[i][0];
	else if((matrix[i][1]==matrix[i][2]&&matrix[i][2]==matrix[i][3]))							
			return matrix[i][1];
	else if((matrix[i][2]==matrix[i][3]&&matrix[i][3]==matrix[i][4]))							
			return matrix[i][2];
	}


	for(i=1;i<4;i++)
	{	if((matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2]))							
			return matrix[i][0];
	else if((matrix[i][1]==matrix[i][2]&&matrix[i][2]==matrix[i][3]))							
			return matrix[i][1];
	else if((matrix[i][2]==matrix[i][3]&&matrix[i][3]==matrix[i][4]))							
			return matrix[i][2];
    }

	for(i=2;i<5;i++)
	{	if((matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2]))							
			return matrix[i][0];
	else if((matrix[i][1]==matrix[i][2]&&matrix[i][2]==matrix[i][3]))							
			return matrix[i][1];
	else if((matrix[i][2]==matrix[i][3]&&matrix[i][3]==matrix[i][4]))							
			return matrix[i][2];
	}



	//column checking

	//checking if the elements of columns are identical

	for(i=0;i<3;i++)
	{	if((matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i]))							
			return matrix[0][i];

	else if((matrix[1][i]==matrix[2][i]&&matrix[2][i]==matrix[3][i]))							
			return matrix[1][i];

    else if((matrix[2][i]==matrix[3][i]&&matrix[3][i]==matrix[4][i]))							
			return matrix[2][i];
	}


	for(i=1;i<4;i++)
	{	if((matrix[1][i]==matrix[2][i]&&matrix[2][i]==matrix[3][i]))							
			return matrix[1][i];

	else if((matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i]))							
			return matrix[0][i];

	else if((matrix[2][i]==matrix[3][i]&&matrix[3][i]==matrix[4][i]))							
			return matrix[2][i];
	}


	for(i=2;i<5;i++)
	{	if((matrix[2][i]==matrix[3][i]&&matrix[3][i]==matrix[4][i]))							
			return matrix[2][i];

	else if((matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i]))							
			return matrix[0][i];


	else if((matrix[1][i]==matrix[2][i]&&matrix[2][i]==matrix[3][i]))							
			return matrix[1][i];
	}



	//diagonal checking

	//checking if (1,1),(2,2),(3,3),(4,4) & (5,5) have identical

	if((matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2]))								
		return matrix[0][0];

if(matrix[1][1]==matrix[2][2]&&matrix[2][2]==matrix[3][3])								
		return matrix[1][1];

if((matrix[2][2]==matrix[3][3]&&matrix[3][3]==matrix[4][4]))								
		return matrix[2][2];

	//checking if (1,5),(2,4),(3,3),(4,2) & (5,1) have identical

	if((matrix[0][4]==matrix[1][3]&&matrix[1][3]==matrix[2][2]))								
			return matrix[0][4];

	if((matrix[1][3]==matrix[2][2]&&matrix[2][2]==matrix[3][1]))								
			return matrix[1][3];

	if((matrix[2][2]==matrix[3][1]&&matrix[3][1]==matrix[4][0]))								
			return matrix[2][2];
    
    //checking if (3,1),(2,2),(1,3) are identical
    
    if((matrix[2][0]==matrix[1][1]&&matrix[1][1]==matrix[0][2]))								
			return matrix[0][2];
 
    //checking if (5,2),(3,3)(2,5) are identicals
    
    if((matrix[5][2]==matrix[3][3]&&matrix[3][3]==matrix[2][5]))								
			return matrix[5][2];
    
	//if there is no identical rows,columns or diagonals,we then check if there is any empty index left

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix[i][j]==' ')
				return ' ';																	//if we find any empty index,we simply return it
		}
	}

	//there is no identical rows,columns or diagonals,there is no empty indices left means the match is drawn and we return 'D'

	return 'D';
}