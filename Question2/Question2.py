def solution(files):
    # Write solution here
    counter_letter= {}
    totalOddLet=0
    oddLet=[]
    len_files=len(files)
    for i in range(len_files):
        if files[i] not in counter_letter.keys():
            counter_letter[files[i]] = 1
        else:
            counter_letter[files[i]] += 1
    for x in counter_letter.keys():
        if (counter_letter[x] % 2 != 0):
            oddLet.append(x)
            totalOddLet += 1
    while  len_files!=0:
        if totalOddLet >1 or totalOddLet%2!=1 and  len_files%2 == 0:
            len_files -=1
            totalOddLet -= 1
        else:
            return len_files


def main():
    str = input()
    answer = solution(str)
    print(answer)


if __name__ == '__main__':
    main()
