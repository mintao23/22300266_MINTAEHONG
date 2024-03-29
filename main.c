#include <stdio.h>
#include <stdlib.h>
#include "system.h"

void display_menu() {
    // 메뉴를 출력하는 코드
}

int get_user_choice() {
    int choice=0;
    // 사용자의 선택을 입력받는 코드
    return choice;
}

int main() {
    // 데이터 초기화
    Game games[MAX_GAMES];
    int num_games = 0;

    // 데이터 파일로부터 초기 데이터 목록을 로딩
    num_games=read_games_from_file(games);

    // 메뉴를 표시하고 작업을 수행
    while (1) {
        display_menu();
        int choice = get_user_choice();
        switch(choice) {
        case 0:
            printf("Exiting the program.\n");
            exit(0);
            break;
        case 1:
            create(games, num_games);
            break;
        case 2:
            read(games, num_games);
            break;
        case 3:
            update(games, num_games);
            break;
        case 4:
            delete_game(games, num_games);
            break;
        case 5:
            search(games, num_games);
            break;
        case 6:
            write_games_to_file(games, num_games);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
    }

    return 0;
}
