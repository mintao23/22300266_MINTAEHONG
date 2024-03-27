#ifndef FUNCTION_H
#define FUNCTION_H

#include "data.h" // 데이터 헤더 파일 포함

// 함수 프로토타입
void load_data(char *filename, Game *games, int *num_games);
void create(Game *games, int *num_games);
void read(Game *games, int *num_games);
void update(Game *games, int *num_games);
void delete_game(Game *games, int *num_games);
void search(Game *games, int *num_games);
void save_data_to_file(Game *games, int num_games);

#endif // FUNCTION_H
