#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"

int main() {
    // 데이터 초기화
    Game games[MAX_GAMES];
    int num_games = 0;
    // 데이터 파일로부터 초기 데이터 목록을 로딩
    num_games=read_games_from_file(games);

    // 메뉴를 표시하고 작업을 수행
    while (1) {
        printf("1.Add 2.Read 3.Update 4.Delete 5.Search 6.Save 7.Popular 0.Exit\n");
        printf("Enter a number: ");
        int choice =0;
        scanf("%d",&choice);
        switch(choice) {
        case 0:
            printf("Exiting the program.\n");
            exit(0);
            break;
        case 1:
            create(games, &num_games);
            break;
        case 2:
            read(games, num_games);
            break;
        case 3:
            update(games, num_games);
            break;
        case 4:
            delete_game(games, &num_games);
            break;
        case 5:
            search(games, num_games);
            break;
        case 6:
            write_games_to_file(games, num_games);
            break;
        case 7:
            popular(games,num_games);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
