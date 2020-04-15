#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "Function.h"

int main() {
     //Initialisation des 3 joueurs possibles maximum, la console me met une erreur si je n'initialise pas !
    char* name;
    int bank;
    int score;
    int ExtraTurn;
    int win;
    Player player;
    player.name = ' ';
    player.bank = player.ExtraTurn = player.score = player.win = 0;
    Player player2;
    player2.name = ' ';
    player2.bank = player2.ExtraTurn = player2.score = player2.win = 0;
    Player player3;
    player3.name = ' ';
    player3.bank = player3.ExtraTurn = player3.score = player3.win = 0;

    printMenu();

    // Ici il y'a les 3 erreurs sur 4 de la console, vous pouvez build pour voir (je crois qu'il faut faire le double pointeur)
    numberOfPlayers();
    wheelTurn(player, player2);
    
    return 0;
}