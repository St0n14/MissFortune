#pragma once
typedef struct Player Player;
typedef struct SecretWord SecretWord;
struct Player {
    char* name;
    int bank;
    int score;
    int ExtraTurn;
    int win;
};

struct SecretWord {
    char* word;
    int size;
};

void printRules();
int numberOfPlayers();
void printMenu();
void wheelTurn(Player player, Player players2);
void scanfFix();
char* input(int maxLength);
int checkExtraTurn(Player player);
void wheelresult(Player*);
void propositionlettre(Player p);
void SecretsWords(SecretWord sw);
void addPlayer(Player j);