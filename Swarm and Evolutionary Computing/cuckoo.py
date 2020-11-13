from random import uniform
from random import randint
import math
# Number of cities = 11
distanceMatrix = [
                    [0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18],
                    [29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12],
                    [20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13],
                    [21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25],
                    [16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22],
                    [31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37],
                    [100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84],
                    [12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13],
                    [4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18],
                    [31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38],
                    [18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0]
                ]

def levyFlight(u):
    return math.pow(u, -1.0/3.0)

def randF():
    return uniform(0.0001, 0.9999)

def calculateDistance(path):
    index = path[0]
    distance = 0
    for nextIndex in path[1:]:
        distance += distanceMatrix[index][nextIndex]
        index = nextIndex
        return distance+distanceMatrix[path[-1]][path[0]]

def swap(sequence, i, j):
    temp = sequence[i]
    sequence[i] = sequence[j]
    sequence[j] = temp

def twoOptMove(nest, a, c):
    nest = nest[0][:]
    swap(nest, a, c)
    return (nest, calculateDistance(nest))

def doubleBridgeMove(nest, a, b, c, d):
    nest = nest[0][:]
    swap(nest, a, b)
    swap(nest, b, d)
    return (nest, calculateDistance(nest))

numNests = 10
pa = int(0.2*numNests)
pc = int(0.6*numNests)
maxGen = 50
n = len(distanceMatrix)
nests = []
initPath = list(range(0, n))
index = 0
for i in range(numNests):
    if index == n-1:
        index = 0
    swap(initPath, index, index+1)
    index += 1
    nests.append((initPath[:], calculateDistance(initPath)))
nests.sort(key=lambda tup: tup[1])
for t in range(maxGen):
    cuckooNest = nests[randint(0, pc)]
    if(levyFlight(randF()) > 2):
        cuckooNest = doubleBridgeMove(cuckooNest, randint(0, n-1), randint(0, n-1), randint(0, n-1), randint(0, n-1))
    else:
        cuckooNest = twoOptMove(cuckooNest, randint(0, n-1), randint(0, n-1))
    randomNestIndex = randint(0, numNests-1)
    if(nests[randomNestIndex][1] > cuckooNest[1]):
       nests[randomNestIndex] = cuckooNest
    for i in range(numNests-pa, numNests):
        nests[i] = twoOptMove(nests[i], randint(0, n-1), randint(0, n-1))
    nests.sort(key=lambda tup: tup[1])
    if (t+1) % 5 == 0:
        print("\nGEN#", t+1, ": ", nests[0])
print("\nCUCKOO's SOLUTION", end=': ')
print(nests[0])
