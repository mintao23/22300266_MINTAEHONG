#ifndef FUNCTION_H
#define FUNCTION_H

#include "data.h" // 데이터 헤더 파일 포함

// 함수 프로토타입
void load_data_from_file(Item *items, int *num_items);
void save_data_to_file(Item *items, int num_items);
void add_item(Item *items, int *num_items);
void view_all_items(Item *items, int num_items);
void update_item(Item *items, int num_items);
void delete_item(Item *items, int *num_items);
void search_items(Item *items, int num_items);

#endif // FUNCTION_H
