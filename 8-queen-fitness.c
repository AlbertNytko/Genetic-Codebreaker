// IT 388, Conversion of 8-queen-fitness program into c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Boolean Library
#include <time.h> // For Random Values
/*

def fitness(initial):
    # Input should be a list
    assert(type(initial) == list)

    # Step1: make the state out of the Input
    state = np.zeros((8, 8))
    for j in range(8):
        state[initial[j]-1][j] = 1

    # Step2: find the fitness of the state
    attacks = 0
    k = -1
    for j in range(8):
        k += 1
        # direction 1: the east
        for l in range(k+1, 8):
            attacks += state[state[:, j].argmax()][l]
    
        # direction 2: the northeast
        row = state[:, j].argmax()
        column = j
        while row > 0 and column < 7:
            row -= 1
            column += 1
            attacks += state[row][column]
            
        # direction 3: the southeast
        row = state[:, j].argmax()
        column = j
        while row < 7 and column < 7:
            row += 1
            column += 1
            attacks += state[row][column]
            
    return 28 - attacks

*/

int genetic_algorithm(int population[], size_t size)
{
    int child[size];
    bool flag = true;
    srand ( time(NULL) ); // Get a new random seed

    // new_population = []
    while (flag)
    { 
        for (int i = 0; i < size; i++)
        {
            // Select Parents
            int x = rand() % size;
            int y = rand() % size;

            // Create child from parents. Assigns the values from calculated array from reproduce to the array child
            memcpy(child, reproduce(x, y), sizeof(reproduce(x, y)));

            // Chance to mutate child
            float mutate_chance = (float)rand()/RAND_MAX;

            if (mutate_chance > 0.998)
                memcpy(child, mutate(child), sizeof(mutate(child)));
        }
        // Condition to break loop needed. Until then, just setting flag to false.
        flag = false;
    }

    return child;
}

int reproduce(int x[], int y[])
{
    int x = x[0];
    int y = y[0];
    int i;
    int c = rand() % (8 + 1 - 0) + 0;
    
    // loop for obtaining x[0:c] into arr1
    for (i = 0; i < c; i++)
    {
       // int arr1[c] = 
    }
    // loop for obtaining y[c:8] into arr2
    for (i = c; i < 8; i++)
    {

       // int arr2[8 - c] = 
    }
    // merging arr1 into child
    for(int i = 0; i < c; i++)
        child[i] = arr1[i];

    // merging arr2 into child 
    for(int i = 0; i < c; i++)
        child[i + n1] = arr2[i];

    return child;
}

int* mutate(int child[])
{
    int index = child[rand() % (8 + 1 - 0) + 0];

    // Update the value at the index to a new random value
    child[index] = rand() % (8 + 1 - 0) + 0;

    return child;
}

int main(int argc, char argv[])
{
    // Population Size
    int population_size = 3000;
    int population_array[6] = {1,2,3,4,5,6};

    genetic_algorithm(population_array, sizeof(population_array) / sizeof(population_array));
}
