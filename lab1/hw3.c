#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5���� ȣ�� �� �� ���尡 �ִ� ���� ã�Ƴ���. (���ϰ� 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // ���� ����� ����Ѵ�.

int main(){
  char mnames[10][20]; // ���л����(�ִ� 10��)
  int mroom[10];		// ���л���ܺ� ȣ�� ���� ���
  char wnames[10][20]; // ���л����(�ִ� 10��)
  int wroom[10];		// ���л���ܺ� ȣ�� ���� ���
  int person[2][5]={0};   // 2�� ���� 5�� ȣ���� ���� �ο� �� 
  int mcount=0, wcount=0; // �ο� �հ� (��, ��)
  int menu;

  srand(time(0));
  printf("===========================================\n");
  printf("��Ȱ�� ȣ�� ���� ���α׷�\n");
  printf("===========================================\n");
  while(1){
    printf("�޴� : 1.���л� ��� 2.���л� ��� 0.���� > ");
    scanf("%d", &menu);
    if(menu==0) break;
    else if(menu==1) {
      if(mcount>=10) {
        printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
        continue;
      }
      printf("�л� �̸���? > ");
      scanf("%s", mnames[mcount]);
      int roomno = findRoom(person[0]);
      mroom[mcount] = 100+roomno;
      printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", mnames[mcount], mroom[mcount]);
      mcount++;
    }
    else if(menu==2) {
      if(wcount>=10) {
        printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
        continue;
      }
      printf("�л� �̸���? > ");
      scanf("%s", wnames[wcount]);
      int roomno = findRoom(person[1]);
      wroom[wcount] = 200+roomno;
      printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", wnames[wcount], wroom[wcount]);
      wcount++;
    }
  }

  printf("===========================================\n");
  printf("��Ȱ�� ȣ�� ���� ����� ������ �����ϴ�.\n");
  printf("===========================================\n");
  printReport(mnames, mroom, mcount, wnames, wroom, wcount);

  return 0;
}

int findRoom(int persons[5]){
// �� ���� ���� ������ �ڵ� ����
    int emptyRooms[5];
    int emptyCount = 0;
    for (int i = 0; i < 5; i++) {
        if (persons[i] < 2) { 
            emptyRooms[emptyCount] = i; 
            emptyCount++; 
        }
    }
    if (emptyCount == 0) {
        return -1; 
    }
    int randomIndex = rand() % emptyCount;
    return emptyRooms[randomIndex] + 1;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// �� ���� ���� ������ �ڵ� ����
    printf("���л� ��� (%d��)\n", mc);
    for (int i = 0; i < mc; i++){
        printf("%d. %s [%dȣ]\n", i+1, mn[i], mr[i]);
    }
    printf("\n");
    printf("���л� ��� (%d��)\n", wc);
    for (int i = 0; i < wc; i++){
        printf("%d. %s [%dȣ]\n", i+1, wn[i], wr[i]);
    }
    printf("\n");
    printf("ȣ�Ǻ� ���� ���\n");
    for(int i=0;i<2;i++){
      for(int j=0;j<5;j++){
        printf("%dȣ : ",(i+1)*100+j+1);
        if(i==0){
          for(int k=0;k<mc;k++){
            if(mr[k]==(i+1)*100+j+1){
              printf("%s ",mn[k]);
            }
          }
        }else{
          for(int k=0;k<wc;k++){
            if(wr[k]==(i+1)*100+j+1){
              printf("%s ",wn[k]);
            }
          }
        }
        printf("\n");
      }
    }
}