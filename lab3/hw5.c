// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

void printStatistics(struct st_channel* c[], int size){
	printf("> Statistics of Channels\n");
	int countLevel[5]={0};
	int sumLevel[5]={0};
	int maxSubsLevel[5]={-1,-1,-1,-1,-1};
	char maxSubsChannel[5][100];
	for(int i=0;i<size;i++){
		int level=c[i]->level;
		countLevel[level]++;
		sumLevel[level]+=c[i]->count;
		if(c[i]->count>maxSubsLevel[level]){
			maxSubsLevel[level]=c[i]->count;
			strcpy(maxSubsChannel[level], c[i]->name);
		}
	}
	for(int i=0;i<5;i++){
		double averageSubs = (double)sumLevel[i] / countLevel[i];
		printf("%s : %d channels, Average %.1f, Top channel : %s (%d people)\n",LNAME[i], countLevel[i], averageSubs, maxSubsChannel[i], maxSubsLevel[i]);
	}

}

void pickupRandomChannels(struct st_channel* c[], int size) {
    printf("> Pick up Channels\n");
    printf("> How many channels do you want to pick up? > ");
    int pick;
    scanf("%d", &pick);
    if (pick > size || pick <= 0) {
        printf("Invalid number of channels to pick up.\n");
        return;
    }
    int chnum[pick]; 
    int count = 0; 
    while (count < pick) {
        int num = rand() % size;
        int alreadyPicked = 0;
        for (int i = 0; i < count; i++) {
            if (chnum[i] == num) {
                alreadyPicked = 1;
                break;
            }
        }
        if (!alreadyPicked) {
            chnum[count] = num;
            count++;
        }
    }
    printf("Random Channels\n");
    for (int i = 0; i < pick; i++) {
        printf("[%2d] %-20s %10d peoples [%s] \n", chnum[i] + 1, c[chnum[i]]->name, c[chnum[i]]->count, LNAME[c[chnum[i]]->level]);
    }
}
void searchChannel(struct st_channel* c[], int size){
	printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");
	int choice;
	int count=0;
    scanf("%d", &choice);
    if (choice == 1) {
        int minSubs, maxSubs;
        printf("> Enter the range of people (from ~ to) > ");
        scanf("%d %d", &minSubs, &maxSubs);
		printf("> Result:\n");
        int found = 0; 
        for (int i = 0; i < size; i++) {
            if (c[i]->count >= minSubs && c[i]->count <= maxSubs) {
                printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
				count++;
                found = 1;
            }
        }
		printf("> %d channels are found.\n",count);
        if (!found) {
            printf("No channels found within the specified subscriber count range.\n");
        }
    }else if (choice == 2) {
        char searchName[100];
        printf("> Enter a name ");
        scanf(" %s", searchName);
		printf("> Result:\n");
        int found = 0; // 검색 결과 여부를 나타내는 변수
        for (int i = 0; i < size; i++) {
            if (strstr(c[i]->name, searchName) != NULL) {
                printf("[%2d] %-20s %10d peoples [%s] \n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
				count++;
                found = 1;
            }
        }
		printf("> %d channels are found.\n",count);
        if (!found) {
            printf("No channels found matching the specified name.\n");
        }
	}else{
		printf("Invalid choice. Please enter 1 or 2.\n");
	}
}


void updateChannel(struct st_channel* c[], int size){
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");


}

int deleteChannel(struct st_channel* c[], int size){
	int no, yesno;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");

	return size;
}


void makeReport(struct st_channel* c[], int size){


}