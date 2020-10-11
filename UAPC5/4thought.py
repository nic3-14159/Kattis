m = int(input())
ops = ['+', '-', '*', '//']
possible = dict()

for i in range(0, 64):
    if (i == 6):
        i = 16
    equation = "4 "
    equation += (ops[i % 4] + " 4 ")
    equation += (ops[(i//4) % 4] + " 4 ")
    equation += (ops[(i//16) % 4] + " 4")
    n = eval(equation)
    possible[n] = equation.replace("//", "/") + " = " + str(n)

for _ in range(0, m):
    n = int(input())
    if n in possible:
        print(possible[n])
    else:
        print("no solution")
