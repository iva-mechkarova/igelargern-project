/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Morgan
 *
 * Created on 06 March 2019, 12:11
 */

#include "game_init.h"
#include "game_logic.h"
#include <stdio.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    //the board is defined as a 2-Dimensional array of squares
    square board[NUM_ROWS][NUM_COLUMNS];
    
    //an array containing the players (MAX 6 players)
    player players[6];
    
    //the number of players
    int numPlayers =0;
    
    //creates the squares of the board
    initialize_board(board);
    
    //prints the board
    print_board(board);
    
    //creates the players
    numPlayers = initialize_players(players);
    
    //initilize colour
    initialize_colour(players,numPlayers);
    
    //asks each player to place their tokens
    //on the first column of the board
    place_tokens(board, players, numPlayers);
    
    
    //manages the turns of the game and identifies a winner
    play_game(board, players, numPlayers);
    
    //TEST-------------------------------------------------------
    int z=0;
    while(z<numPlayers){
        printf("Player Pos %d Name : %s\n",z, players[z].playername);
        switch (players[z].playersToken.col) 
        {
            case (RED): printf("Player Pos %d Colour : %s\n", z, "RED");
            break;
            case (BLU): printf("Player Pos %d Colour : %s\n", z, "BLUE");
            break;
            case (GREEN): printf("Player Pos %d Colour : %s\n", z, "GREEN");
            break;
            case (YELLOW): printf("Player Pos %d Colour : %s\n", z, "YELLOW");
            break;
            case (PINK): printf("Player Pos %d Colour : %s\n", z, "PINK");
            break;
            case (ORANGE): printf("Player Pos %d Colour : %s\n", z, "ORANGE");
            break;
        }
        z++;
    }
    printf("Number of players:%d",numPlayers);
    
    return 0;

}

