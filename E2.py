T = int(input())
while T > 0:
    T -= 1
    a,b,c,x,y,d = map(int, input().split())
    
    ans = 0
    if d <= x:
        ans = a
    elif d <= x + y:
        ans = a + b * (d - x)
    else:
        ans = a + b * y + c * (d - x - y)


    num = d // x
    remain = d % x
    cost1 = num * a
    cost2 = a if remain != 0 else 0
    if remain <= y:
        cost2 = min(cost2, b * remain)
    else:
        cost2 = min(cost2, b * y + c * (remain - y))
    ans = min(ans, cost1 + cost2)

    
    len = x + y
    num = d // len
    remain = d % len
    cost1 = num * (a + b * y)
    cost2 = 0
    if remain == 0:
        cost2 = 0
    elif remain <= x:
        cost2 = a
        cost2 -= min(x - remain, y * num) * b
    else:
        cost2 = a + b * (remain - x)

    if num != 0:
        cost2 = min(cost2, remain * c)
    ans = min(ans, cost1 + cost2)
    print(ans)