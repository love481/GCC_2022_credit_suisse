def solution(n, employees, shifts):
    # Write solution here
    shiftsList=[]
    for i in range(n):
        for j in range(2):
            if shifts[i][j] not in shiftsList:
                shiftsList.append(shifts[i][j])
    shiftsList.sort()
    print(len(shiftsList)-1)
    for i in range(len(shiftsList)-1):
        employeess=[]
        for j,shift in enumerate(shifts):
            if shift[0]<=shiftsList[i] and shift[1]>=shiftsList[i+1]:
                employeess.append(employees[j])
        employeess.sort()
        print(shiftsList[i],shiftsList[i+1],len(employeess)," ".join(employeess))
def main():
    n = int(input())
    employees = input().split(" ")
    shifts = []
    for i in range(n):
        line = input().split(" ")
        shifts.append([int(line[0]), int(line[1])])

    solution(n, employees, shifts)


if __name__ == '__main__':
    main()












    

