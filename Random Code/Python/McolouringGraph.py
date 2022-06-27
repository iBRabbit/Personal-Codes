VERTEX_NUMBER = 3

def promisingColoring(graph, color):
    for i in range (VERTEX_NUMBER) :
        for j in range (i + 1, VERTEX_NUMBER) : 
            if (graph[i][j] and color[j] == color[i]) : return False
    return True

def coloring(graph, m, i, color):
    if (i == VERTEX_NUMBER) : 
        if promisingColoring(graph, color) : 
            print("Solution : ")
            for i in range (VERTEX_NUMBER) :
                print(color[i])
            return True
        return False
                
    for j in range (1, m + 1) :
        color[i] = j
        if coloring(graph, m, i + 1, color) : return True
        color[i] = 0
    return False
    
if __name__ == '__main__' : 
    for i in range (100) : print("")
    M = 4
    
    graph = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 0]
    ]
    
    color = [0 for i in range(VERTEX_NUMBER)]
    if not coloring(graph, M, 0, color) :
        print("No solution")
    