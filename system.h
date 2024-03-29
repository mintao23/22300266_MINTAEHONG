#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#define MAX_GAMES 100

typedef struct {
    int number;
    char name[MAX_GAMES];
    int price;
    int rate;
    int dlc;
} Game;

int read_games_from_file(Game *games);
void write_games_to_file(Game *games, int num_games);
void create(Game *games, int *num_games);
void read(Game *games, int num_games);
void update(Game *games, int num_games);
void delete_game(Game *games, int *num_games);
void search(Game *games, int num_games);
void popular(Game *games, int num_games);
#endif /* GAME_SYSTEM_H */
