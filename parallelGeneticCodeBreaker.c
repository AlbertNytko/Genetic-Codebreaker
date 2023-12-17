#include <stdio.h>
#include <string.h>

/*
Fitness Function

The purpose of this function is ot dtermine how close the genetic algorithm
gets to solving the problem or its "fitness"

Since we are codebreaking, the fitness function will evaluate how 
close we are to cracking the code

strings can be compared using the strcmp() function fomr the string.h library

We will need to see how many characters are in the correct position
The number of correct characters is our fitness score and will be used to evaluate how close we are to cracking the code

since this will be parallel, we will onl be evaluating a portion of the code at a time
*/

/*
PARALLEL IMPLEMENTATION
For hybrid code I think it makes the most sense to use MPI to distribute (or possibly generate)
 sections of the population to each core and then use OpenMP to solve the segments of the code
*/

/*
Genetic Algorithm: takes a population as a parameter

while flag is true
    create a new, empty poplation
    for i in poulation
        x = random parent form population
        y = random parent form population

        child = reproduce(x, y)

        if random # between 1 and 0 is gretaer than .998 (low probability)
            child = mutate
        if child fitness == code length
            break and set flag to false because we cracked the code
        add child to new population
    for i in population
        if new population at i is more fit than population at i
            population at i = new population at i
return child
*/

/*
Reproduce: takes paretns x and y as parameters

cutoff = random number between 0 and childLength
newChild = x[0:cutoff] + y[c:childLentgh]
return newChild
*/

/*
Mutate: takes a child as an argument

changhe a random index in the child to a random value
return child
*/

/*
Main

take population size as a command line argument
initialize population (arrays that are the codeLength/nunmberOfProcessors in length)
print exanple code (the one we are trying to break)
print the result of the 
*/