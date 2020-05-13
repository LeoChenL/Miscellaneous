import math

def triangle():
    '''
    Pascal triangle generator
    '''
    n = 0
    prev_row = [1]
    yield prev_row
    n += 1
    prev_row = [1, 1]
    yield prev_row

    while True:
        n += 1
        row = [1]
        for i in range(1, n):
            row.append(prev_row[i-1]+prev_row[i])
        row.append(1)
        prev_row = row
        yield row


def pascal_triangle(n):
    '''
    nth row of the pascal triangel
    '''
    if n == 1:
        return [1]
    elif n == 2:
        return [1, 1]

    row = [1, n-1]
    for i in range(2, math.ceil(n/2.0)):
        value = pascal_triangle(n-1)[i-1] + pascal_triangle(n-1)[i]
        row.append(value)

    if n%2 == 0:
        res_row = row[::-1]
    else:
        res_row = row[-2::-1]
    row.extend(res_row)

    return row

if __name__ == "__main__":
    # triangle recursion
    row = pascal_triangle(7)
    print(row,'\n')

    # triangel generator
    n = 0
    results = []
    for t in triangle():
        results.append(t)
        n = n + 1
        if n == 10:
            break

    for t in results:
        print(t)
