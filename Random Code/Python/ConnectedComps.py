adjacencyList = [
    [1],
    [3],
    [1],
    [2, 4],
    [5],
    [7],
    [4],
    [6]
]

belongComponent = []
currentNumberComponents = 0

def dfs(currectComponentID, currentVertex):
    if (belongComponent[currentVertex] != -1) : return
    
    belongComponent[currentVertex] = currectComponentID
    
    for i in range (0, len(adjacencyList)) :
        nextVertex = adjacencyList[currentVertex][i]
        dfs(currectComponentID, nextVertex)
        

for u in range(0, 8) :
    belongComponent.append(-1)
    
for u in range (0, 8) :
    if(belongComponent == -1) :
        dfs(currentNumberComponents, u)
        currentNumberComponents += 1

print(currentNumberComponents)
