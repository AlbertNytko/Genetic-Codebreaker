# -*- coding: utf-8 -*-
"""

@author: xfang13, Matt Tobeck, Audra Heistand

"""
import random

import numpy as np


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


def genetic_algorithm(population):
    flag = True
    while flag:
        # new_population = []
        for i in population:
            # select parents
            x = random.sample(population, 1)
            y = random.sample(population, 1)
            # create child form parents
            child = reproduce(x, y)
            # chnace to mutate child
            if random.uniform(0.0, 1.0) > .998:
                child = mutate(child)

            if fitness(child) == 28:
                flag = False
                break

    return child


def reproduce(x, y):
    x = x[0]
    y = y[0]
    c = random.randrange(0, 8)
    child = x[0:c] + y[c:8]
    return child


def mutate(child):
    child[random.randrange(8)] = random.randrange(8)
    return child


if __name__ == '__main__':
    # print fitness([2, 4, 7, 4, 8, 5, 1, 3])
    population_size = 10000
    population_set = [[random.randint(1, 8) for j in range(8)]for i in range(population_size)]
    print(genetic_algorithm(population_set))
