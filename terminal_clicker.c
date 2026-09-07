#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <pthread.h>
char button;
char delete_everything_decision = '\0';
int save_count = 0;
double hackbux = 0;
char buffer[10000] = "\0";
char grab_again = '\0';
char grab_from_save = '\0';
struct ThreadArgs {
    double *hackbux;
    double *hps;
};
struct upgrade {
    char name[50];
    char description[1000];
    char cost[50];
    double costnumber;
    double amount;
};
struct upgrade upgrade_one = {"1. Intel Pentium 90", "\nBare bones processor that adds 1 to your click power.\nWas used in the mid to late '90s for average computing.\nIt's decent as an upgrade,\nincreased click count is a good improvement.\nSolid pick if you have the hackbux.", "Cost: 50 hackbux", 50, 0};
struct upgrade upgrade_two = {"2. Intel Pentium Pro 200", "\nWith an ability to auto-click hackbux,\nthis one is a great CPU that is able to handle 1hps (hackbux per second).\nIt's the first auto-clicking CPU, and has a blast to it!\nWas also used around the '90s.", "Cost: 1000 hackbux", 1000, 0};
struct upgrade upgrade_three = {"3. Intel Pentium 4 3.06", "\nA CPU that came out in around 2002, this one is the first to have hyper-threading. it gives 5 extra click power per click.\nAn elite upgrade from the Intel Pentium 90, I promise you your clicks will skyrocket if you haven't reached this level yet.", "Cost: 10k hackbux", 10000, 0};
struct upgrade upgrade_four = {"4. AMD Athlon 64  X2 4800+", "\nAlright, this is where we start getting serious. Released around May 2005 at around 10hps,\nthis auto-clicker saves you bigtime when youre doing chores,\nhaving breaks, or simply staring at the screen watching the number tick up.\nBeing the first with two cores,\nthis is a very bold pick mid-game.", "Cost: 100k hackbux", 100000, 0};
struct upgrade upgrade_five = {"5. Intel Core 2 Quad Q6600", "\nFour cores. Four threads. What more do you need? Released in 2007, it adds a whopping 100 clicks to your click power;\nit's a MASSIVE improvement from any of the other CPUs. Your jaw is going to drop the second you click.", "Cost: 10m hackbux", 10000000, 0};
struct upgrade upgrade_six = {"6. Intel Core i7-2600K", "\nReleased in 2011, i bet some of you playing this game on an old computer might be using it.\nAlthough I dont know why you'd be using a CPU from 15 years ago but fluff aside,\nit was amazing for its time. With Sandy Bridge microarchitecture and reaching up to 4.8GHz, it gets you\n500hps each.", "Cost: 10b hackbux", 1e10, 0};
struct upgrade upgrade_seven = {"7. AMD Ryzen 5 1600", "\nA 2017 CPU thats relatively modern and still used in decent computers to this day,\nyou would choose this one any day over any of the others for a decent work laptop.\nwith 6 cores and 12 threads, it gives a staggering 1000 click power increase,\nits truly mindboggling at this rate.", "Cost: 1t hackbux", 1e12, 0};
struct upgrade upgrade_eight = {"8. AMD Ryzen 9 5950X", "\nThe first modern gaming PC's CPU, so expect big improvement here.\nThis one gives so much autoclicking power it makes the last options look like sticks and stones.\n2000hps, take it or leave it, although no reason to leave it here!", "Cost: 100q hackbux", 1e17, 0};
struct upgrade upgrade_nine = {"9. Intel Core Ultra 9 285K", "\nNo more joking this time.\nWith a collosal 24 cores and 24 threads,\nthis is the ultimate choice.\nIt can't get any better than this, right?\n(10000 click power increase)", "Cost: 100qi hackbux", 1e20, 0};
struct upgrade upgrade_ten = {"10. AMD Ryzen 7 98003XD", "\nThis is it. Congratulations, you beat the game.\nI don't care how easy/hard it was for you,\nthis is the ultimate reward.\nTake 100khps, Just for you.", "Cost: 999s", 9.99e23, 0};

void* background_hps_tracker(void* arg) {
    struct ThreadArgs* data = (struct ThreadArgs*)arg;
    while (1) {
        sleep(1); 
        *(data->hackbux) += *(data->hps);
    }
    return NULL;
}
void previous_save(){
        FILE *saveCheck = fopen("save_file.txt", "r");
        save_count++;
        printf("Looks like you already have a save file.");
        sleep(2);
        printf("\nWould you like to continue off of it? (y for yes, n for no)\n");
        scanf(" %c", &grab_from_save);
        if(grab_from_save == 'y' || grab_from_save == 'Y'){
        grab_from_save = '\0';
        while(fgets(buffer, sizeof(buffer), saveCheck) != NULL){
        if(sscanf(buffer, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d", &hackbux, &upgrade_one.amount, &upgrade_two.amount, &upgrade_three.amount, &upgrade_four.amount, &upgrade_five.amount, &upgrade_six.amount, &upgrade_seven.amount, &upgrade_eight.amount, &upgrade_nine.amount, &upgrade_ten.amount, &save_count) == 12){
            system("cls");
        }
        }
    }
    else if(grab_from_save == 'n' || grab_from_save == 'N'){
        grab_from_save = '\0';
        system("cls");
    }
    else{
        grab_from_save = '\0';
        printf("Please choose an option");
        sleep(1);
        system("cls");
        previous_save();
    }
    fclose(saveCheck);
}
FILE *createSave;
void save_func(){
        save_count++;
        createSave = fopen("save_file.txt", "w");
        if(createSave == NULL){
            printf("Failed to write save");
            sleep(1);
        }
        if(fprintf(createSave, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %d", hackbux, upgrade_one.amount, upgrade_two.amount, upgrade_three.amount, upgrade_four.amount, upgrade_five.amount, upgrade_six.amount, upgrade_seven.amount, upgrade_eight.amount, upgrade_nine.amount, upgrade_ten.amount, save_count)){
            system("cls");
            printf("\nSaving...\n");
            sleep(1);
            printf("Saved\n");
            sleep(1);
            system("cls");
        }
        fclose(createSave);
        button = '\0';
        system("cls");
}
int main(){
    system("cls");
    double price_multiplier_upgrade_one = (upgrade_one.amount * 5);
    double price_multiplier_upgrade_two = (upgrade_two.amount * 5);
    double price_multiplier_upgrade_three = (upgrade_three.amount * 5);
    double price_multiplier_upgrade_four = (upgrade_four.amount * 5);
    double price_multiplier_upgrade_five = (upgrade_five.amount * 5);
    double price_multiplier_upgrade_six = (upgrade_six.amount * 5);
    double price_multiplier_upgrade_seven = (upgrade_seven.amount * 5);
    double price_multiplier_upgrade_eight = (upgrade_eight.amount * 5);
    double price_multiplier_upgrade_nine = (upgrade_nine.amount * 5);
    double price_multiplier_upgrade_ten = (upgrade_ten.amount * 5);
    
    printf("Press F11 or Fn + F11 for fullscreen\nPress Ctrl and + to increase font size");
    sleep(2);
    double hps = (upgrade_two.amount * 1) + (upgrade_four.amount * 10) + (upgrade_six.amount * 500) + (upgrade_eight.amount * 2000) + (upgrade_ten.amount * 100000);
    int upgrade_choose_purchase = 0;
    struct ThreadArgs game_data;
    game_data.hackbux = &hackbux;
    game_data.hps = &hps;
    pthread_t hps_thread;
  
    if (pthread_create(&hps_thread, NULL, background_hps_tracker, (void*)&game_data) != 0) {
        perror("fail to calculation hps"); 
        return 1;
    }
    char upgrade_accept_entry = '\0';
    system("cls");
    double addhackbux = 0;
    printf("Made by Kbtpo Zpvlibob");
    sleep(2);
    system("cls");
    bool placeholder = false;
    bool start_click_gone = false;
    double newhackbux = 0;
    char button;
    char tutorialButton;
    char tutorialDecision = '\0';
    double click_power = (upgrade_one.amount * 1) + (upgrade_three.amount * 5) + (upgrade_five.amount * 100) + (upgrade_seven.amount * 1000) + (upgrade_nine.amount * 10000) + 1;
    FILE *saveCheck = fopen("./save_file.txt", "r");
    if(saveCheck == NULL){
        fclose(saveCheck);
        printf("Welcome to Terminal Clicker!\n");
        sleep(2);
        printf("It appears this is your first time here.\n");
        sleep(1);
        printf("Would you like a tutorial? (y for yes, n for no)\n");
        scanf(" %c", &tutorialDecision);
        if(tutorialDecision == 'y' || tutorialDecision == 'Y'){
            system("cls");
            printf("Press any button to click.\nClicking is how you get hackbux,\nwhich are used to get upgrades.\nUpgrades give effects, mainly autoclicking, click-power, etc.");
            tutorialButton = _getch();
            tutorialButton = '\0';
            system("cls");
            for(int i = 0; i < 50; i++){
                printf("Great! Now, lets try clicking 50 times to get to the first upgrade. %.0lf/50", hackbux);
                tutorialButton = _getch();
                if(tutorialButton != '\0'){
                hackbux++;
                system("cls");
                tutorialButton = '\0';
                }
            }
            printf("Wonderful! You just gained 50 hackbux!");
            sleep(3);
        }
        else if(tutorialDecision == 'n' || tutorialDecision == 'N'){
            system("cls");
        }
    }
    else if(saveCheck != NULL){
        fclose(saveCheck);
        previous_save();
    }
    do{
        if(start_click_gone == true){
            if(hackbux < 1000){
                ;
            }
        }
        else if(start_click_gone == false){
        if(hackbux < 1000){
        printf("\nStart Clicking!\n");
        }
        else if(hackbux > 1000){
            start_click_gone = true;
        }
     }
        button = '\0';
        printf("\n\n\nhackbux per Second: %.0lf\nClick Power: %.0lf\nhackbux: %.0lf\n\n\n\n\t\t\t\tUpgrades (press '.')\n\t\t\t\tSave (press ',')\n\t\t\t\tReset All Data (press ';')", hps, click_power, hackbux, button, tutorialDecision);
        if(tutorialDecision == 'y' || tutorialDecision == 'Y'){
            if(upgrade_ten.amount == 0 && hackbux > 9.98999999999999999999999e23){
            printf("\n\nYou have enough hackbux to get upgrade ten!\n");
            }
            if(upgrade_nine.amount == 0 && hackbux > 9.9999999999999999999e19){
            printf("\n\nYou have enough hackbux to get upgrade nine!\n");
            }
            if(upgrade_eight.amount == 0 && hackbux > 9.9999999999999999e16){
            printf("\n\nYou have enough hackbux to get upgrade eight!\n");
            }
            if(upgrade_seven.amount == 0 && hackbux > 9.99999999999e11){
            printf("\n\nYou have enough hackbux to get upgrade seven!\n");
            }
            if(upgrade_six.amount == 0 && hackbux > 9.999999999e9){
            printf("\n\nYou have enough hackbux to get upgrade six!\n");
            }
            if(upgrade_five.amount == 0 && hackbux > 9999999){
            printf("\n\nYou have enough hackbux to get upgrade five!\n");
            }
            if(upgrade_four.amount == 0 && hackbux > 99999){
            printf("\n\nYou have enough hackbux to get upgrade four!\n");
            }
            if(upgrade_three.amount == 0 && hackbux > 9999){
            printf("\n\nYou have enough hackbux to get upgrade three!\n");
            }
            if(upgrade_two.amount == 0 && hackbux > 999){
            printf("\n\nYou have enough hackbux to get upgrade two!\n");
            }
            if(upgrade_one.amount == 0 && hackbux > 49){
            printf("\n\nYou have enough hackbux to get upgrade one!\nGo to the upgrades menu and choose the first upgrade by typing '1'.\n");
            }
        }
        button = _getch();
        switch(button){
            case '.':
            double price_multiplier_upgrade_one = (upgrade_one.amount * 5);
            double price_multiplier_upgrade_two = (upgrade_two.amount * 5);
            double price_multiplier_upgrade_three = (upgrade_three.amount * 5);
            double price_multiplier_upgrade_four = (upgrade_four.amount * 5);
            double price_multiplier_upgrade_five = (upgrade_five.amount * 5);
            double price_multiplier_upgrade_six = (upgrade_six.amount * 5);
            double price_multiplier_upgrade_seven = (upgrade_seven.amount * 5);
            double price_multiplier_upgrade_eight = (upgrade_eight.amount * 5);
            double price_multiplier_upgrade_nine = (upgrade_nine.amount * 5);
            double price_multiplier_upgrade_ten = (upgrade_ten.amount * 5);
              if(save_count == 0){
                system("cls");
                printf("\nWelcome to Dan's CPU Shop!");
                sleep(2);
                printf("\nHere we sell CPUs that help with various tasks.\n(save atleast once to get rid of this tutorial)");
                sleep(3);
                system("cls");
                printf("Would you like to continue? (y for yes, n for no)\n");
                scanf(" %c", &upgrade_accept_entry);
                if(upgrade_accept_entry == 'y' || upgrade_accept_entry == 'Y'){
                    system("cls");
                    //modifying this is a nightmare
                    printf("%s\n%s\nCost: %.0lf* hackbux\n\n\n*Note from Dan: One thing you need to know about floating point numbers\nbeyond around this point\nis that they can be slightly off thus the price can fluctuate.\ndont worry, just treat this as if it were a funny little quirk\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n", upgrade_ten.name, upgrade_ten.description, upgrade_ten.costnumber, upgrade_ten.amount, 
                    upgrade_nine.name, upgrade_nine.description, upgrade_nine.costnumber, upgrade_nine.amount, 
                    upgrade_eight.name, upgrade_eight.description, upgrade_eight.costnumber, upgrade_eight.amount, 
                    upgrade_seven.name, upgrade_seven.description, upgrade_seven.costnumber, upgrade_seven.amount, 
                    upgrade_six.name, upgrade_six.description, upgrade_six.costnumber, upgrade_six.amount, 
                    upgrade_five.name, upgrade_five.description, upgrade_five.costnumber, upgrade_five.amount, 
                    upgrade_four.name, upgrade_four.description, upgrade_four.costnumber, upgrade_four.amount, 
                    upgrade_three.name, upgrade_three.description, upgrade_three.costnumber, upgrade_three.amount, 
                    upgrade_two.name, upgrade_two.description, upgrade_two.costnumber, upgrade_two.amount, 
                    upgrade_one.name, upgrade_one.description, upgrade_one.costnumber, upgrade_one.amount);
                    scanf("%d", &upgrade_choose_purchase);
                    switch(upgrade_choose_purchase){
                        case 1:
                        if(upgrade_one.amount > 0){
                            upgrade_one.costnumber = upgrade_one.costnumber + price_multiplier_upgrade_one;
                        }
                        if(hackbux - upgrade_one.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_one.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_one.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_one.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 2:
                        if(upgrade_two.amount > 0){
                            upgrade_two.costnumber = upgrade_two.costnumber + price_multiplier_upgrade_two;
                        }
                        if(hackbux - upgrade_two.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_two.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_two.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_two.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 3:
                        if(upgrade_three.amount > 0){
                            upgrade_three.costnumber = upgrade_three.costnumber + price_multiplier_upgrade_three;
                        }
                        if(hackbux - upgrade_three.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_three.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_three.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_three.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 4:
                        if(upgrade_four.amount > 0){
                            upgrade_four.costnumber = upgrade_four.costnumber + price_multiplier_upgrade_four;
                        }
                        if(hackbux - upgrade_four.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_four.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_four.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_four.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 5:
                        if(upgrade_five.amount > 0){
                            upgrade_five.costnumber = upgrade_five.costnumber + price_multiplier_upgrade_five;
                        }
                        if(hackbux - upgrade_five.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_five.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_five.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_five.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 6:
                        if(upgrade_six.amount > 0){
                            upgrade_six.costnumber = upgrade_six.costnumber + price_multiplier_upgrade_six;
                        }
                        if(hackbux - upgrade_six.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_six.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_six.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_six.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 7:
                        if(upgrade_seven.amount > 0){
                            upgrade_seven.costnumber = upgrade_seven.costnumber + price_multiplier_upgrade_seven;
                        }
                        if(hackbux - upgrade_seven.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_seven.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_seven.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_seven.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 8:
                        if(upgrade_eight.amount > 0){
                            upgrade_eight.costnumber = upgrade_eight.costnumber + price_multiplier_upgrade_eight;
                        }
                        if(hackbux - upgrade_eight.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_eight.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_eight.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_eight.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 9:
                        if(upgrade_nine.amount > 0){
                            upgrade_nine.costnumber = upgrade_nine.costnumber + price_multiplier_upgrade_nine;
                        }
                        if(hackbux - upgrade_nine.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_nine.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_nine.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_nine.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 10:
                        if(upgrade_ten.amount > 0){
                            upgrade_ten.costnumber = upgrade_ten.costnumber + price_multiplier_upgrade_ten;
                        }
                        if(hackbux - upgrade_ten.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_ten.costnumber - hackbux);
                        sleep(2);
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_ten.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_ten.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case '\x1b':
                        break;
                        default:
                        printf("Choose a number between 1-10 respective of the upgrade number\n");
            }

        }
        else if(upgrade_accept_entry == 'n' || upgrade_accept_entry == 'N'){
            system("cls");
        }
    }
        else if(save_count > 0){
            system("cls");
                    //modifying this is ALSO a nightmare
                    printf("%s\n%s\nCost: %.0lf* hackbux\n\n\n*Note from Dan: One thing you need to know about floating point numbers\nbeyond around this point\nis that they can be slightly off thus the price can fluctuate.\ndont worry, just treat this as if it were a funny little quirk\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n%s\n%s\nCost: %.0lf hackbux\nOwned: %.0lf\n\n", upgrade_ten.name, upgrade_ten.description, upgrade_ten.costnumber, upgrade_ten.amount, 
                    upgrade_nine.name, upgrade_nine.description, upgrade_nine.costnumber, upgrade_nine.amount, 
                    upgrade_eight.name, upgrade_eight.description, upgrade_eight.costnumber, upgrade_eight.amount, 
                    upgrade_seven.name, upgrade_seven.description, upgrade_seven.costnumber, upgrade_seven.amount, 
                    upgrade_six.name, upgrade_six.description, upgrade_six.costnumber, upgrade_six.amount, 
                    upgrade_five.name, upgrade_five.description, upgrade_five.costnumber, upgrade_five.amount, 
                    upgrade_four.name, upgrade_four.description, upgrade_four.costnumber, upgrade_four.amount, 
                    upgrade_three.name, upgrade_three.description, upgrade_three.costnumber, upgrade_three.amount, 
                    upgrade_two.name, upgrade_two.description, upgrade_two.costnumber, upgrade_two.amount, 
                    upgrade_one.name, upgrade_one.description, upgrade_one.costnumber, upgrade_one.amount);
                    scanf("%d", &upgrade_choose_purchase);
                    switch(upgrade_choose_purchase){
                        case 1:
                        if(upgrade_one.amount > 0){
                            upgrade_one.costnumber = upgrade_one.costnumber + price_multiplier_upgrade_one;
                        }
                        if(hackbux - upgrade_one.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_one.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_one.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_one.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 2:
                        if(upgrade_two.amount > 0){
                            upgrade_two.costnumber = upgrade_two.costnumber + price_multiplier_upgrade_two;
                        }
                        if(hackbux - upgrade_two.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_two.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_two.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_two.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 3:
                        if(upgrade_three.amount > 0){
                            upgrade_three.costnumber = upgrade_three.costnumber + price_multiplier_upgrade_three;
                        }
                        if(hackbux - upgrade_three.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_three.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_three.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_three.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 4:
                        if(upgrade_four.amount > 0){
                            upgrade_four.costnumber = upgrade_four.costnumber + price_multiplier_upgrade_four;
                        }
                        if(hackbux - upgrade_four.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_four.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_four.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_four.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 5:
                        if(upgrade_five.amount > 0){
                            upgrade_five.costnumber = upgrade_five.costnumber + price_multiplier_upgrade_five;
                        }
                        if(hackbux - upgrade_five.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_five.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_five.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_five.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 6:
                        if(upgrade_six.amount > 0){
                            upgrade_six.costnumber = upgrade_six.costnumber + price_multiplier_upgrade_six;
                        }
                        if(hackbux - upgrade_six.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_six.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_six.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_six.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 7:
                        if(upgrade_seven.amount > 0){
                            upgrade_seven.costnumber = upgrade_seven.costnumber + price_multiplier_upgrade_seven;
                        }
                        if(hackbux - upgrade_seven.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_seven.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_seven.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_seven.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 8:
                        if(upgrade_eight.amount > 0){
                            upgrade_eight.costnumber = upgrade_eight.costnumber + price_multiplier_upgrade_eight;
                        }
                        if(hackbux - upgrade_eight.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_eight.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_eight.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_eight.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 9:
                        if(upgrade_nine.amount > 0){
                            upgrade_nine.costnumber = upgrade_nine.costnumber + price_multiplier_upgrade_nine;
                        }
                        if(hackbux - upgrade_nine.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_nine.costnumber - hackbux);
                            sleep(2);
                            upgrade_choose_purchase = '\0';
                            button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_nine.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_nine.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case 10:
                        if(upgrade_ten.amount > 0){
                            upgrade_ten.costnumber = upgrade_ten.costnumber + price_multiplier_upgrade_ten;
                        }
                        if(hackbux - upgrade_ten.costnumber < 0){
                            printf("\nYou cannot afford this item. You need %.0f more hackbux", upgrade_ten.costnumber - hackbux);
                        sleep(2);
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                            system("cls");
                            break;
                        }
                        newhackbux = hackbux - upgrade_ten.costnumber;
                        hackbux = newhackbux;
                        newhackbux = 0;
                        upgrade_ten.amount++;
                        system("cls");
                        upgrade_choose_purchase = '\0';
                        button = '\0';
                        break;
                        case '\x1b':
                        break;
                        default:
                        printf("Choose a number between 1-10 respective of the upgrade number\n");
            }
    } 
        break; 
    case '`':
        system("cls");
        printf("DEBUG MODE!!!\n\nUpgrades 1-10 amount in order: %.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n", upgrade_one.amount, upgrade_two.amount, upgrade_three.amount, upgrade_four.amount, upgrade_five.amount, upgrade_six.amount, upgrade_seven.amount, upgrade_eight.amount, upgrade_nine.amount, upgrade_ten.amount);
        printf("\n\nSave count: %d", save_count);
        sleep(3);
        break;
    case ',':
        save_func();
        break;
    case ';':
        system("cls");
        printf("Are you sure about this? Doing this will erase ALL progress.\n(y for yes, n for no)\n");
        scanf(" %c", &delete_everything_decision);
        if(delete_everything_decision == 'y' || delete_everything_decision == 'Y'){
            if(remove("save_file.txt") == 0){
                system("cls");
                printf("Deleted.");
                sleep(2);
                system("cls");
            }
            else{
                system("cls");
                printf("Unable to delete save file. Try deleting it manually instead.\n'save_file.txt'");
                sleep(3);
                system("cls");
            }
        }
        else if(delete_everything_decision == 'n' || delete_everything_decision == 'N'){
            ;
        }
        break;
        case '\x1b':
        system("cls");
        printf("Exiting...");
        return 0;
        default:
        hps = (upgrade_two.amount * 1) + (upgrade_four.amount * 10) + (upgrade_six.amount * 500) + (upgrade_eight.amount * 2000) + (upgrade_ten.amount * 100000);
        click_power = (upgrade_one.amount * 1) + (upgrade_three.amount * 5) + (upgrade_five.amount * 100) + (upgrade_seven.amount * 1000) + (upgrade_nine.amount * 10000) + 1;
        hackbux++;
        newhackbux = hackbux + click_power - 1;
        hackbux = newhackbux;
        newhackbux = 0;
        button = '\0';
        system("cls");
        break;
        system("cls");
        }
    }while(placeholder == false); 
}