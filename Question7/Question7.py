from typing import List
def get_cycle_state(trans,cur_node, visited,stack):
    visited[cur_node] = True
    stack[cur_node] = True
    for adjacent_node in trans[cur_node]:
        if visited[adjacent_node] == False:
            if get_cycle_state(trans,adjacent_node, visited,stack) == True:
                return True
        elif stack[adjacent_node] == True:
            return True
    stack[cur_node] = False
    return False
def solution(n: int, l: int, transfers: List[List[int]]) -> bool:
    trans={i:[] for i in range(n)}
    for i in range(l):
        if transfers[i][0]!=transfers[i][1]:
            trans[transfers[i][0]].append(transfers[i][1])
            
    visited = [False] * (n)
    stack = [False] * (n)
    for cur_node in range(n):
        if visited[cur_node] == False:
            if get_cycle_state(trans,cur_node,visited,stack) == True:
                return True
    return False
def main():
    n, l = [int(i) for i in input().split(" ")]
    transfers = []
    for i in range(l):
      line = input().split(" ")
      transfers.append([int(line[0]), int(line[1])])
    result = solution(n, l, transfers)
    print("Ineligible" if result else "Eligible")
    
if __name__ == '__main__':
    main()
