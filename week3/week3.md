# Week3 For a While

### 基础语法

For循环：

```C
Start;
for(int i=1;i<=10;i++){
	// 循环里的内容 
    printf("%d ",i);
}
End;



```

while循环:

```C
Start;
while(cond){
    // 循环里的内容 
}
End;



```

事实上上面两种格式基本等价。

do-while循环:

```C
Start;
do{
    // 循环里的内容 
}while(cond); // 注意这里有个分号
End;



```

请思考下面几个问题：

1. do-while和while循环相比，有什么区别？ （后者至少会执行一次）

2. 如果我们希望提前终止循环，或者跳过本次循环，应该怎么做？ （break和continue, 做题中再慢慢使用）

3. 还有一种跳转语句叫做goto，可以无条件跳转到某个地方，思考它的优劣。

   ![image-20241015160232856](C:\Users\a1592\AppData\Roaming\Typora\typora-user-images\image-20241015160232856.png)

# T1 淘淘摘苹果

[[NOIP2005 普及组\] 陶陶摘苹果 - 题目详情 - HydroOJ](https://hydro.ac/d/CPL_NJU/p/P1046)https://www.luogu.com.cn/problem/P1046)

（话说洛谷上的大部分“入门”等级题都可以拿来练手，但确实很简单，做太多意义不大。）

# **T2 蒙特卡洛**

![蒙特卡洛树是什么算法？ - 知乎](https://img-blog.csdnimg.cn/20190710172344511.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly95aXNodWloYW5jaGVuZy5ibG9nLmNzZG4ubmV0,size_16,color_FFFFFF,t_70)

蒙特卡洛方法是一种基于概率和随机抽样的数值计算方法，可以用来估算π的值。请你编写一个程序，使用蒙特卡洛方法来估算π的值。

蒙特卡洛方法的一种实现具体步骤如下：

- 在一个边长为2的正方形内，随机生成大量点（建议至少生成1000000个点）。
- 计算每个点到正方形中心（坐标原点）的距离，判断该点是否位于内切圆内（内切圆半径为1）。
- 统计落在内切圆内的点的数量。
- 根据以下公式计算π的估算值：π ≈ 4 × (落在内切圆内的点数 / 总点数)。

想必就算无法严格证明，你也能从感觉上知道这样做是对的。那就开写吧。

这里我们提供一个简易版本的随机数生成器，他会随机生成[0,MAX)中的任意一个整数，你需要使用它来完成此题：

```c
#include<stdlib.h>
#include<time.h>
const int MAX = 8192;
int get_rand(){
    return rand() % MAX;
}// 你需要手动添加上面几行

int main(){
    srand(time(0)); // 记得这行也要加到你的程序里面
	printf("get a random number: %d", get_rand()); //使用例
}
```

最终，你的pi值应该保留**两位小数**。如果你的结果非常接近答案，但不太稳定，可以尝试增加生成点的数量

### input1

```
啥也没有
```



### output1

```output1
3.14
```

# T3 节奏大师

![节奏大师 的图像结果](https://tse1-mm.cn.bing.net/th/id/OIP-C.4GYgQ5hAvFKQnhdfetIOggHaEK?w=297&h=180&c=7&r=0&o=5&dpr=1.3&pid=1.7)

在著名(?)音游节奏大师中，选手们通过击打屏幕上的音符来展现自己的节奏感。每个音符根据击打的准确性分为四种等级：Perfect、Great、Good 和 Miss。同时，连击数（Combo）也是衡量选手表现的重要指标。你的任务是编写一个程序，根据选手的击打结果计算最终得分，以及最大Combo。下面是该游戏分数的计算方法：

[节奏大师分数计算规则 - 节奏大师综合讨论 - TapTap 节奏大师论坛](https://www.taptap.cn/moment/472409400821154155)







看完了吗？好，上面的文章没有一点用。为了简化计算，我们将重新制定一套得分规则和Combo计算规则如下：

初始Combo数为0, 然后不同判定的**基础分数**及效果为：

- Perfect：得100分， Combo+1；
- Great：得50分， Combo+1；
- Good：得20分， Combo+1；
- Miss：不得分,  且Combo清零；

另外，根据Combo的不同，还会对你上述判定得到的**基础分数进行加成**，具体倍率为$ （1 + Combo数 * 0.1） $倍，上限为3倍。

注意，**每次判定先计算得分再修改Combo数**。例如：

在某一时刻，玩家的Combo=5, 下一个音符为Great, 那么它这个音符的得分为：

$$ 50(基础分) * (1 + 0.5)(倍率) = 75分$$

随后Combo变为6。

参照样例以获得更多信息。

注意，由于浮点数可能出现误差，十分不建议在本题出现任何浮点数，**考虑如何使用整数表示倍率？**



## 输入输出格式

首先输入一个整数N，表示谱面音符个数。

接下来N行，每行一个字符串，只可能是’Perfect’、‘Great’、'Good’和’Miss’中的某一个。

然后，你需要输出两个整数$ score, max\_combo $, 分别表示得分与最大连击数。

保证$ N \le 10000 $



### input1

```
10
Perfect
Perfect
Good
Good
Perfect
Great
Perfect
Miss
Perfect
Perfect
```



### output1

```output1
845 7
```

### 样例1解释：

1. 第一个音符 “Perfect”：得分为100分，加成为1.0倍，实际得分100分，Combo增加至1。
2. 第二个音符 “Perfect”：得分为110分，加成为1.1倍，实际得分110分，Combo增加至2。
3. 第三个音符 “Good”：得分为24分，加成为1.2倍，实际得分24分，Combo增加至3。
4. 第四个音符 “Good”：得分为26分，加成为1.3倍，实际得分26分，Combo增加至4。
5. 第五个音符 “Perfect”：得分为140分，加成为1.4倍，实际得分140分，Combo增加至5。
6. 第六个音符 “Great”：得分为75分，加成为1.5倍，实际得分75分，Combo增加至6。
7. 第七个音符 “Perfect”：得分为160分，加成为1.6倍，实际得分160分，Combo增加至7。
8. 第八个音符 “Miss”：得分为0分，Miss，不得分，Combo清零。
9. 第九个音符 “Perfect”：得分为100分，加成为1.0倍，实际得分100分，Combo增加至1。
10. 第十个音符 “Perfect”：得分为110分，加成为1.1倍，实际得分110分，Combo增加至2。

### input2

```
24
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
Perfect
```



### output2

```output2
5100 24
```
### 样例2解释：
你可以自行计算下，以确定你对分数计算规则没有误解

# T4 其他题目

下面这些都是在校内OJ上的：

For循环： 2D, 2E

While循环： 2F, 3A, 3B

break, continue： 3C, 3D, 3H

