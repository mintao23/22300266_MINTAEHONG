#ifndef DATA_H
#define DATA_H

#define MAX_GAMES 100

typedef struct {
    int id;
    char name[100];
    int price;
    int rate;
    int dlc;
} Game;

void load_data_from_file(Game *games, int *num_games);
void save_data_to_file(Game *games, int num_games);

#endif // DATA_H
