# Week2 If-Else,Switch-case

### 基础语法

If语句：

```C
Start;
if(cond){
    A;
}
End;



```

If-Else:

```C
Start;
if(cond){
    A;
}
else{
    B;
}
End;
```

If-Else if:

```C
Start;
if(cond1){
    A;
}
else if(cond2){
    B;
}
else{
    C;
}
End;
```

switch-case:

```C
Start;
int x = ...;
switch(x){
    case 1:{
        A;
        break;
    }
    case 2:{
        B;
        break;
    }
    case ...:
        Others;
        break;
}
```

### 布尔值介绍

简而言之就是上面的cond, **只有true和false两种取值**

C语言中并没有直接定义bool类型，只能由其他类型转化得来。

**所有的“0”都被视为False，非零视为true**

同时你需要知道这几个逻辑运算符：and(&&),   or(||),  not(!)

以及，能产生bool值的那些比较运算符：>, <, <=, >=, ==, !=....



### 变量作用域

既然引入了大括号，就顺便谈谈变量作用域的问题

```C
#include <stdio.h>

int a = 10;

void func1() {
    int a = 20;
    printf("(func1) a = %d\n", a);
}

void func2(){
	printf("(func2) a = %d\n", a);
}

int main() {
    int a = 30;
	int b = 100;
    func1();
    func2();
    
    {	
        int a = 40;
        {
            printf("(here1) a = %d, b = %d",a,b);
            {
                {
                    {
						int b = 200;
                    }
                    printf("(here2) a = %d, b = %d",a,b);
                }
            }
        }
    }
    return 0;
}
```

1. 同一作用域下不能声明同名变量
2. 每个大括号内部可视作一个作用域
3. 内部作用域能看见外部变量，外部则不能看见内部
4. 优先使用内部变量



## 练习题目：

t1: 找到三个数的最大值

t2: 计算平闰年（校内OJ上）

t3: HydroOJ [**B3993**](https://hydro.ac/d/CPL_NJU/p/B3993)(练习switch-case)

校内OJ 2A,2B,2C

