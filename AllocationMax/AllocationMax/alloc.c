#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Function.h"
#define BUFFER_SIZE 20
#define MYSTERIOUS_MAX 30
int numberOfturn = 1;
void printRules() {
	int choice;
	printf("=========== WELCOME TO THE RULEBOOK ===========\n");
	printf("IF YOU WANT TO COMEBACK IN MENU, PRESS '0' ");
	printf("To play, there must be 2 or 3 players, as well as a game Masterwho will choose the word mystery !\n");
	printf("1) The objectif of the games is to find the word mystery by giving letters\n");
	printf("2) In this game, you will have to spin a wheel every time it is your turn to try to win some money\n");
	printf("3) There are different amounts of money available in the weel ranging from 300$ to 900$ !\n");
	printf("4) You win the sum of money from the wheel if you find a consonant of the word mystery !\n");
	printf("5) After that, you will have to make a choice between trying to fin dthe word, or buying a vowel ( Unless all vowels have been found )\n");
	printf("6) A vowel costs 250$ !\n");
	printf("7) In the wheel, we have 3 'specials' cases : Bankrupt / Extra Turn / Lose a Turn\n ");
	printf("8) Bankrupt : You are not lucky, your money bank drops to 0, and you pass your turn :(\n");
	printf("9) Lose a Turn : Your are not lucky, you pass your turn :(\n");
	printf("10) Extra Turn : ??? \n");
	printf("11) There are 3 round, so it's the first whowins 2 rounds who won ! Except if you are three, there can be equality !\n");
	printf("That's All ! If you want to comeback in menu, press '0' !\n");
	scanf_s("%d", &choice);
	if (choice == 0)
	{
		void printMenu();

	}

}
/* J'ai changé des trucs ici ! J'ai tous simplement mis la méthode AddPlayer ici, sa évite de créer 928374 méthodes pour rien
   et ça simplifie aussi.*/

int numberOfPlayers() {
	int nop;
	printf("Select Number of player");
	fgets(nop, 1, stdin);
	Player p1,p2,p3,p4,p5;
	switch (nop)
	{
	case 1:
		addPlayer(p1);
		break;
	case 2 :
		addPlayer(p2);
		break;
	case 3: 
		addPlayer(p3);
		break;
	case 4:
		addPlayer(p4);
		break;
	case 5:
		addPlayer(p5);
		break;
	default:
		printf("To much players");
		break;
	}

}
void printMenu() {
	int choice;
	// Menu avec choix :
	printf("======= WHAT DO YOU WANT TO DO ? =======\n");
	printf("0 = Exit\n");
	printf("1 = Play\n");
	printf("2 = See the rules\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 0:
		// exit(0) ferme l'application
		printf("Thank you for playing the games !");
		exit(0);
	case 1:
		// Paramètre du jeux
	case 2:
		printRules();
	default:
		printf("Please, enter a valid number ( 1, 2 or 3 )\n");
		printMenu();
		break;
	}

}
/* Pas mal d'amélioration, notamment le ExtraTurn, le fait que les joueurs vont jouer chacun leur tour
   Tous simplement car les tours impair : tour du 1er joueur et Tours pairs : tour du 2ème joueurs !*/

   // Je pensais faire une 2ème fonction WheelTurn, avec tous simplement 3joueurs, comme ça, je fai modulo 3 et c'est fini !
void wheelTurn(Player j1, Player j2) {
	// Ici du vrai hasard avec srand() et time en variable
	while (j1.win != 1 || j2.win != 1)
	{
		// Si le tour est impair, alors c'est au joueur 1 de jouer :
		if (numberOfturn % 2 == 1)
		{
			wheelresult(&j1);
		}
		// Sinon si c'est pair, c'est au joueur 2 :
		wheelresult(&j2);
	}
}
/* La fonction demande simplement au joueur qui joue s'il veut utiliser son Extra Turn et return un chiffre
   qui sera utile puisque la condition pourra l'utiliser pour savoir si on lui met un tour bonus ou non !*/
int checkExtraTurn(Player player) {
	int choice;
	if (player.ExtraTurn != 0)
	{
		printf(" Do you want to use your Extra Turn ? ( 1 = Yes / 2 = No ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			player.ExtraTurn -= 1;
			return 1;
		}
		return 2;
	}
	return 0;
}
// Ici c'et simple, si le mot est découvert, alors le joueur qui l'a dévouvert gagnera puisque la boucle while s'arrêtera
void win(Player player) {
	player.win = 1;
}
//=========================================================================================
void scanfFix() {
	while (getchar() != '\n');
}

char* input(int maxLength)
{
		static char buffer[MYSTERIOUS_MAX];

	fflush(stdout);

	if (fgets(buffer, maxLength, stdin) != NULL) {
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		return buffer;
	}
	else {
		perror("I/O Error.");
		exit(1);
	}
	return NULL;
}


void wheelresult(Player* p) {
	srand(time(NULL));
	int random = rand() % 24 + 1;
	if (random <= 5) {
		printf(" You have 300$");
		p->bank += 300;
	}
	else if (random <= 6) {
		printf(" You have 350$");
		p->bank += 350;
	}
	else if (random <= 8) {
		printf(" You have 400$");
		p->bank += 400;
	}
	else if (random <=9) {
		printf(" You have 450$");
		p->bank += 450;
	}
	else if (random <= 12) {
		printf(" You have 500$");
		p->bank += 500;
	}
	else if (random <= 15) {
		printf(" You have 600$");
		p->bank += 600;
	}
	else if (random <= 17) {
		printf(" You have 700$");
		p->bank += 700;
	}
	else if (random <= 19) {
		printf(" You have 800$");
		p->bank += 800;
	}
	else if (random <= 21) {
		printf(" You have 900$");
		p->bank += 900;
	}
	else if (random <= 22) {
		printf(" You have extraturn");
		printf("Waw, you have 'Extra Turn' :D \n You are going to restart the wheel \n");
		p->ExtraTurn += 1;
		numberOfturn++;
	}
	else if (random <= 23) {
		printf(" NOOOO, you fell into 'Bankrupt' !\n");
		checkExtraTurn(*p);
		if (checkExtraTurn(*p) == 0 || checkExtraTurn(*p) == 2)
		{
			p->bank = 0;
		}
		// Sinon on lui redonne un tour, et il n'y a pas le malus ! 
		printf("You have used your ExtraTurn !\n ");
		// En rajoutant 1 tour, il passera d'un tour pair à impair, à la fin du tour, nous allons re-ajouter un tour 
		// (voir plus bas), de ce fait nous retomberons sur un nombre pair, et la boucle while relancera donc un tour 
		//pour le joueur
		numberOfturn++;
	}
	else
	{
		printf(" You have lose a turn");
		printf("NOOOO, you fell into 'Lose a Turn'\n");
		// Ici c'est la même schématique que Bankrupt();
		checkExtraTurn(*p);
		if (checkExtraTurn(*p) == 0 || checkExtraTurn(*p) == 2)
		{
			//LoseATurn();
		}
		printf("You have used your ExtraTurn !\n ");
		numberOfturn++;
	}
}

void propositionlettre(Player p)
{
	int result;
	char letter;
	printf("enter letter");
	letter = getchar();
	result = findLetter(&p, letter);

}

void SecretsWords(SecretWord sw) {
	int i = 0;
	char tempo[200];
	printf("Enter your the secret word : ");
	while ((tempo[i] = _getch()) != '\r') {
		putchar('*');
		i++;
	}
	sw.size = i;
	free(i);
	sw.word = malloc(sw.size * sizeof(char));
	strncpy_s(sw.word, sw.size, tempo, sw.size);
	printf("%d %s", sw.size, sw.word);
	free(tempo);
}

void addPlayer(Player j)
{
	j.name = malloc(BUFFER_SIZE * sizeof(char));
	printf("What your name ? (10 letters max)");
	fgets(j.name, BUFFER_SIZE, stdin);
	j.bank = j.score = 0;
	j.name = "";
}

int findLetter(Player* p,char lettre) {

	int index[5];
	int t = 0;
	SecretWord s;
	for (int i = 0; i < strlen(s.word); i++) {
		if (s.word[i] == lettre) {
			index[t] = i;
			printf("letter c at position %d", i + 1);
			t++;
		}
	}
	if (t > 1) {
		return 1;
	}
	else {
		return 0;
	}
}
