T = int(input())
while T > 0:
    T -= 1
    a,b,c,x,y,d = map(int, input().split())
    
    ans = 0
    num = d // x
    remain = d % x
    cost1 = num * a
    cost2 = a if remain else 0
    if num:
        if remain <= y:
            cost2 = min(cost2, remain * b)
        else:
            cost2 = min(cost2, (remain - y) * c + b * y)
    ans = cost1 + cost2

    if d > x:
        len = x + y
        num = d // len
        remain = d % len
        cost1 = num * (a + b * y)
        cost2 = 0
        if remain == 0:
            cost2 = 0
        elif remain <= x:
            cost2 = a
            cost2 -= min(y * num , x - remain) * b
        else:
            cost2 = a + (remain - x) * b
        if num:
            cost2 = min(cost2, remain * c)
        ans = min(ans, cost1 + cost2)
    if d >= x + y:
        ans = min(ans, a + y * b + c * (d - x - y))
    print(ans) 