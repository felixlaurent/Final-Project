#include <stdio.h>
#include <string.h>

// food's detail
struct food {
    char Name[255];
    int Price;
    bool available;
};

// Global Variables
food foods[50];
int totFoods = 0;

// Function Prototypes
void showMenu() {
    for(int i = 0; i < totFoods; i++) {
        if(foods[i].available) {
            printf("%s %d\n", foods[i].Name, foods[i].Price);
        }
    }
}

void addFood(food x) {
    strcpy(foods[totFoods].Name, x.Name);
    foods[totFoods].Price = x.Price;
    foods[totFoods].available = true;
    totFoods++;
}

void removeFood() {
    char foodName[255];
    printf("Insert unavailable food : ");
    scanf("%[^\n]", foodName); getchar();

    for(int i = 0; i < totFoods; i++) {
        if(strcmp(foods[i].Name, foodName) == 0) {
            foods[i].available = false;
        }
    }
}
void showUser(){
    puts("Who are you?");
    puts("1. Admin");
    puts("2. Guest");	
    puts("3. Exit");
}

void showChoices() {
    puts("Main Menu");
    puts("1. Add Menu");
    puts("2. Show Available Menu");
    puts("3. Remove Menu");
    puts("4. Back");
}

void mainMenu() {
    bool onApp = true;

    while(onApp) {
    	showUser();
		int userchoice =-1;
		
        do {
            printf(">> ");
            scanf("%d", &userchoice); getchar();
        } while(userchoice < 1 || userchoice > 3);
		if (userchoice == 1){
        showChoices();
        int choice = -1;

        do {
            printf(">> ");
            scanf("%d", &choice); getchar();
        } while(choice < 1 || choice > 4);

        if(choice == 1) {
            food newMenu;
            printf("Name: ");
            scanf("%[^\n]", newMenu.Name); getchar();
            printf("Price: ");
            scanf("%d", &newMenu.Price); getchar();
            addFood(newMenu);
        } else if(choice == 2) {
            showMenu();
        } else if(choice == 3) {
            removeFood();
        } else if(choice == 4) {
        	//gatau kenapa dia langsung back ke showUser
        }
		}else if (userchoice ==2){
			printf("What do you wanna eat today?\n");
		}else if (userchoice == 3){
			printf("bye bye\n");
		    onApp = false;	
		}
    }
}

int main() {
    mainMenu();
    return 0;
}


