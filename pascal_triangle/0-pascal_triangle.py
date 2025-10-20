#!/usr/bin/python3
""" Pascal Trigle Algorith """


def pascal_triangle(n):
    """
        function that returns list of lists that presents
            pascal triangle of specified number
        n: level of pascal triangle
    """

    ResultList = []
    if (n <= 0):
        return ([])
    elif (n == 1):
        ResultList.append([1])
        return (ResultList)
    else:
        toAdd = 1
        myList = [1]
        print(myList)
        for i in range(n - 1):
            for j in range(len(myList)):
                if (j == len(myList) - 1):
                    myList.append(1)
                    ResultList.append(myList[:])
                    break
                else:
                    storage = myList[j + 1]
                    myList[j + 1] = toAdd + myList[j + 1]
                    toAdd = storage
        return (ResultList)
