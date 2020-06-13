#include <stdio.h>
#include <stdlib.h>

void show_menu();
void show_list(char* filename);
void add_list(char* filename);

int main () {
	int num;

	while(num != 3) {
		show_menu();
		scanf("%d", &num);
		
		switch(num) {
			case 1:
				show_list("movie.txt");
				break;
			case 2:
				add_list("movie.txt");
				break;
			case 3:
				printf("\nGood bye!\n");
				break;
			default :
				printf("Wrong input, do it againg\n");
		}
	}	
	return 0;
}



void show_menu() {
	printf("\nSelect menu(1~3) \n\n");
	printf("1. See the list\n");
	printf("2. New movie \n");
	printf("3. Exit \n\n");		
}

void show_list(char* filename) {
	FILE* fp1 = fopen(filename, "r");

	
	char strTmp[255];

	int count_number = 0;
	float current_rate = 6;
	float total_rate = 0;
	
	printf("\nnumber        movie name             rate\n");
	
	while(fscanf(fp1, "%s %f\n", strTmp, &current_rate) != EOF)
	{	
		count_number ++;
		printf("  %-11d %-15s %10.1f\n", count_number, strTmp, current_rate);
		total_rate += current_rate;
		
	}

	printf("\n\nTotal watched movies : %d\n", count_number);
	printf("Rate average : %.1f \n", (float)(total_rate / count_number) );

	fclose(fp1);
	
}

void add_list(char* filename) {
	FILE* fp2 = fopen(filename, "a");
	char moviename[255];
	float stars = 0;

	printf("\nMovie name? \n");
	scanf("%s", moviename);
	printf("How many points? \n");
	scanf("%f", &stars);

	fprintf(fp2, "%s %f\n", moviename, stars);
	printf("New movie added..\n");
	
	fclose(fp2);
}
