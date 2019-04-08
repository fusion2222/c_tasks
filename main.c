#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/*
 * TASK: The russian roulette
 *
 * 23 soldiers standing in a circle. In the center is standing officer. From
 * randomly chosen one he will count till 5, and he will shoot the fifth soldier.
 * He continues like this until there is only single soldier left. Print his index
 * number into console. Allow user to specify index of soldier, which will survive
 * as the last - this will adjust starting position of officer's counting.
 *
 * ASSUMPTIONS:
 *
 * The officer will count only in one direction.
 */

const short int TOTAL_SOLDIERS_LENGTH = 23;
const short int TOTAL_SURVIVORS = 1;
const short int TOTAL_DEAD = TOTAL_SOLDIERS_LENGTH - TOTAL_SURVIVORS;
const short int OFFICER_SHOOT_ORDER = 5;  // Officer will shoot every fifth soldier.

char* soldiers[TOTAL_SOLDIERS_LENGTH] = {
    "Simon",
    "Andrew",
    "James",
    "John",
    "Philip",
    "Bartholomew",
    "Matthew",
    "Thomas",
    "James",
    "Thaddaeus",
    "Simon",
    "Judas",
    "Matthias",
    "Michael",
    "Gabriel",
    "Raphael",
    "Uriel",
    "Sealtiel",
    "Jegudiel",
    "Barachiel",
    "Jerahmeel",
    "Suriel",
    "Zedekiel",
};


void print_array(){  // For debugging purposes only.
    printf("\n");
    for (int i = TOTAL_SOLDIERS_LENGTH - 1; i >= 0 ; i--) {
        printf("%s\n", soldiers[i]);
    }
    printf("\n");
}


int is_soldier_dead(index){
    return soldiers[index] == NULL;
}

int main(){
    srand( time(NULL) );  // seeding rand()
    // In order to do this, our soldiers array will contain names of soldiers.
    // If soldier's name is NULL instead, we consider such soldier as dead.

    int soldiers_dead = 0;
    int shooting_index = 0;
    int random_starting_position = (int)roundf((float)rand() / RAND_MAX * (float)TOTAL_SOLDIERS_LENGTH);
    int full_soldier_index = random_starting_position;
    int current_soldier_index;

    printf("Officer starts to count from soldier number %d\n", random_starting_position);
    printf("Officer loads gun and is about to shoot soldiers...\n", random_starting_position);

    // Shoot soldiers.
    while(soldiers_dead < TOTAL_DEAD){

        full_soldier_index++;
        current_soldier_index = full_soldier_index % TOTAL_SOLDIERS_LENGTH;

        if(is_soldier_dead(current_soldier_index)){
            // Officer will count only alive soldiers.
            continue;
        }

        shooting_index++;

        if(shooting_index == OFFICER_SHOOT_ORDER){
            printf("Officer shot soldier #%d %s\n", current_soldier_index, soldiers[current_soldier_index]);
            soldiers[current_soldier_index] = NULL;
            shooting_index = 0;
            soldiers_dead++;
        }

        // DEBUG: print_array(soldiers) if needed

    }

    // Now lets look up the only survivor.
    for(int i = TOTAL_SOLDIERS_LENGTH - 1; i >= 0; i--){
        if(!is_soldier_dead(i)){
            printf("The only survivor is soldier #%d %s", i, soldiers[i]);
            break;
        }
    }

    return 0;

}
