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
	FILE *fp = fopen("scores.txt", "r");
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

void updatePrice() {
    char foodName[255];
    int newPrice;
    printf("Insert food name : ");
    scanf("%[^\n]", foodName); getchar();
    printf("Insert new price : ");
    scanf("%d[^\n]", &newPrice); getchar();
    
    for(int i = 0; i < totFoods; i++) {
        if(strcmp(foods[i].Name, foodName) == 0) {
            foods[i].Price = newPrice;
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
    puts("4. Update Price");
    puts("5. Exit");   
}

void showGuest(){
    puts("Welcome");
    puts("1. Show Menu");
    puts("2. Exit");	
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
	        } while(choice < 1 || choice > 5);
	
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
	        	updatePrice();
	        }else if (choice == 5){
			}
		}else if (userchoice ==2){
	        showGuest();
	        int guestchoice = -1;
	
	        do {
	            printf(">> ");
	            scanf("%d", &guestchoice); getchar();
	        } while(guestchoice < 1 || guestchoice > 2);
	
	        if(guestchoice == 1) {
	            showMenu();
	        } else if(guestchoice == 2) {
	        }
		}else if (userchoice == 3){
			printf("bye bye\n");
		    onApp = false;	
		}
    }
}

int main() {
	FILE *fp = fopen("menu.txt", "r");	
    mainMenu();
    return 0;
}
