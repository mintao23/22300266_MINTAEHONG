#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#define MAX_GAMES 100

int read_games_from_file(Game *games) {
    FILE *file = fopen("game.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return 0;
    }
    int game_count = 0; // 게임 수를 추적하기 위한 변수

    // 파일에서 한 줄씩 읽어옴
    while (fscanf(file, "%d %s %d %d %d", &games[game_count].number, games[game_count].name, &games[game_count].price, &games[game_count].rate, &games[game_count].dlc) == 5) {
        game_count++; // 다음 게임으로 이동
    }

    fclose(file);
    printf("%d games are loaded\n", game_count);
    return game_count; // 읽은 게임 수 반환
}



void write_games_to_file(Game *games, int num_games) {
    FILE *file = fopen("game.txt", "w");
    // 각 게임 정보를 파일에 씀
    for (int i = 0; i < num_games; i++) {
        fprintf(file, "%-2d %-25s %6d %2d %2d\n",games[i].number,games[i].name,games[i].price,games[i].rate,games[i].dlc);
    }

    fclose(file);
    printf("File is saved.\n");
}

void create(Game *games, int *num_games) {
    // 게임 추가하는 코드
    printf("Enter a new game info\n");
    int new_game_number = (*num_games) + 1;
    games[*num_games].number = new_game_number;
    printf("Name: ");
    scanf("%s", games[*num_games].name);
    printf("Price: ");
    scanf("%d", &games[*num_games].price);
    printf("Rate(5~0): ");
    scanf("%d", &games[*num_games].rate);
    printf("DLC(1:YES 0:NO): ");
    scanf("%d", &games[*num_games].dlc);
    (*num_games)++;
    printf("Game is added.\n");
}


void read(Game *games, int num_games) {
    // 게임 목록을 출력하는 코드
    printf("No Name                     price  rate dlc\n");
    for(int i=0;i<num_games;i++){
        printf("%-2d %-25s %6d %2d %2d\n",games[i].number,games[i].name,games[i].price,games[i].rate,games[i].dlc);
    }
}

void update(Game *games, int num_games) {
    // 게임 정보 업데이트하는 코드
    printf("Enter a number to change info: ");
    int num;
    scanf("%d",&num);
    int found = 0;
    for(int i=0;i<num_games;i++){
        if(num==games[i].number){
            found = 1;
            printf("%-2d %-25s %6d %2d %2d\n",games[i].number,games[i].name,games[i].price,games[i].rate,games[i].dlc);
            printf("New Name: ");
            scanf("%s", games[i].name);
            printf("New Price: ");
            scanf("%d", &games[i].price);
            printf("New Rate(5~0): ");
            scanf("%d", &games[i].rate);
            printf("New check DLC(1:YES 0:NO): ");
            scanf("%d", &games[i].dlc);
            printf("The info is changed.\n");
            break;
        }
    }
    if(!found) {
        printf("Game with number %d is not found.\n", num);
    }
}

void delete_game(Game *games, int *num_games) {
    // 삭제할 게임 번호 입력
    printf("Enter the number of the game to delete: ");
    int num;
    scanf("%d", &num);
    int found = 0;
    for (int i = 0; i < *num_games; i++) {
        if (games[i].number == num) {
            found = 1;
            for (int j = i; j < *num_games - 1; j++) {
                games[j] = games[j + 1];
                games[j].number--;
            }
            (*num_games)--; 
            break;
        }
    }

    if (found) {
        printf("Game with number %d is deleted.\n", num);
    } else {
        printf("Game with number %d is not found.\n", num);
    }
}

void search(Game *games, int num_games) {
    // 검색할 문자열 입력
    printf("Enter the starting letters of the game name to search: ");
    char search_prefix[100];
    scanf("%s", search_prefix);
    int found = 0;
    for (int i = 0; i < num_games; i++) {
        if (strncmp(games[i].name, search_prefix, strlen(search_prefix)) == 0) {
            if (!found) {
                printf("Matching games:\n");
                found = 1;
            }
            printf("%-2d %-25s %6d %2d %2d\n", games[i].number, games[i].name, games[i].price, games[i].rate, games[i].dlc);
        }
    }
    if (!found) {
        printf("No games found starting with '%s'.\n", search_prefix);
    }
}

void popular(Game *games, int num_games){
    // 평점이 5점인 게임 추천
    printf("Top rated games:\n");
    int found = 0;
    for (int i = 0; i < num_games; i++) {
        if (games[i].rate == 5) {
            if (!found) {
                found = 1;
            }
            printf("%-2d %-25s %6d %2d %2d\n", games[i].number, games[i].name, games[i].price, games[i].rate, games[i].dlc);
        }
    }
    if (!found) {
        printf("No top rated games found.\n");
    }
}


