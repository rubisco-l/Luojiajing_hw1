# 代码编写思路

## 余子式函数minor\_matrix：

为了方便求解，编写了一个生成余子式的函数： <img src="attachments/Pasted%20image%2020250503212314.png" width="400" /> <img src="attachments/Pasted%20image%2020250503212254.png" width="400" />

## 计算行列式

由Laplace定理，把行列式按第一行展开，使用递归函数的方法计算

## 求逆

根据伴随矩阵来求逆

$\textbf{A}^{-1}=\dfrac{1}{|\textbf{A}|}\textbf{A}^*$

## 求秩

不使用高斯消元法，而是用递归方式计算秩，思路如下：

1. 从最大可能的秩开始，尝试找到一个该阶的非零子式；
2. 如果找不到，再试小一阶的子式；
3. 一直到找到第一个非零子式，其阶数即为矩阵的秩。

# 编程中遇到的问题

## 1.1 【cmake】标准问题

第一次编写完cmake后报错：

```
[build] D:\X-lab\Luojiajing_hw1\src\algebra.c:141:5: error: 'for' loop initial declarations are only allowed in C99 or C11 mode  
[build] for (int i = 0; i < a.rows; i++)
```

在 C89/C90 标准（默认编译标准）中，变量声明必须在代码块开头，不能在 for 循环头部声明变量。

## 1.2解决方法

在cmake中加入

```cmake
# 设置 C 语言标准为 C99

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_STANDARD_REQUIRED ON)
```

## 2.2【cmake】缓存问题

移动文件位置后再次build，遇到报错：

```
CMake Error: The source "D:/X-lab/C_demo/CMakeLists.txt" does not match the source "D:/rubisco/ZJU/X-lab/C-demo/CMakeLists.txt" used to generate cache. Re-run cmake with a different source directory.
```

原因为：
之前在 `D:/rubisco/ZJU/X-lab/C-demo/` 目录里运行过 `cmake`，CMake 生成了一个 缓存。
第二次试图从 不同路径 重新运行 CMake，但它还在使用旧缓存，所以报错说“路径不一致”。

## 2.2解决方法

删除原本的build文件夹，并重新建立

## 3.1【git】detached HEAD

在某次commit后git status显示

```shell
head detached from 4f7dd09
```

原因：之前checkout到了某个commit上，而不是分支
如果此时做了一些更改并提交了，它们不会绑定在任何分支上，一旦切换分支，它们可能“丢失”（只能通过 commit-id 找回来）。

## 3.2解决方法

先把之前的改动保存在一个新的分支上

```
git switch -c temp-work

git switch main
git merge temp-work
```

# testing用例

## add\_matrix

输入：
\+
2 2
1.1 1.3
2.4 3.7
2 2
3.1 4.3
5.1 7.1
\+
2 2
1.1 1.2
2.4 3.5
2 3
1 2 2.1
3 2 3.3
q

输出：
4.20    5.60
7.50    10.80
Error: Matrix a and b must have the same rows and cols. <img src="attachments/Pasted%20image%2020250503193002.png" width="400" />

## sub\_matrix

## 输入：

2 2
5.1 7.3
9.4 12.7
2 2
1.1 2.3
4.4 3.7
-------

2 3
1.1 2.2 3.3
4.4 5.5 6.6
3 2
1.1 2.2
3.3 4.4
5.5 6.6
q

输出：
4.00    5.00
5.00    9.00
Error: Matrix a and b must have the same rows and cols. <img src="attachments/Pasted%20image%2020250503193127.png" width="400" />

## mul\_matrix

输入：
\*
2 3
1 2 3
4 5 6
3 2
7 8
9 10
11 12
\*
2 2
1 2
3 4
3 3
1 2 3
4 5 6
7 8 9
q

输出：
58.00   64.00
139.00  154.00
Error: The number of cols of matrix a must be equal to the number of rows of matrix b. <img src="attachments/Pasted%20image%2020250503193152.png" width="400" />

## scale\_matrix

输入：
.
2 3
1.0 2.0 3.0
4.0 5.0 6.0
q

输出：
2.00    4.00    6.00
8.00    10.00   12.00 <img src="attachments/Pasted%20image%2020250503193615.png" width="400" />

## transpose\_matrix

输入：
t
2 3
1 2 3
4 5 6
q

输出：
1.00    4.00
2.00    5.00
3.00    6.00 <img src="attachments/Pasted%20image%2020250503194550.png" width="400" />

## trace\_matrix

输入：
j
3 3
1 2 3
4 5 6
7 8 9
j
2 3
1 2 3
4 5 6
q

输出：
15.00
Error: The matrix must be a square matrix.
0.00 <img src="attachments/Pasted%20image%2020250503194812.png" width="400" />

## det\_matrix

输入：
d
3 3
6 1 1
4 -2 5
2 8 7 <img src="attachments/Pasted%20image%2020250503210328.png" width="400" />

## inv\_matrix

输入：
i
2 2
4.00  7.00
2.00  6.00 <img src="attachments/Pasted%20image%2020250503215039.png" width="400" />

## rank\_matrix

输入：
r
3 3
1 2 3
4 5 6
5 7 9

rank = 2 <img src="attachments/Pasted%20image%2020250503212457.png" width="400" />

