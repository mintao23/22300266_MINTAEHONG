#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "function.h"

int main() {
    // 데이터 초기화
    Item items[MAX_ITEMS];
    int num_items = 0;

    // 데이터 파일로부터 초기 데이터 목록을 로딩
    load_data_from_file(items, &num_items);

    // 메뉴를 표시하고 작업을 수행
    while (1) {
        display_menu();
        int choice = get_user_choice();
        execute_menu(choice, items, &num_items);
    }

    return 0;
}
