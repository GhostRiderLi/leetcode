# unique binary search tree

## 解题思路

计算有n个节点不同拓扑形态的二叉搜索树，每个n节点的二叉树，可以由两个节点数只和为 n-1 的子二叉树构成: 左子树的节点数为i，则右子树的节点数为 n - i - 1。假设那个节点的二叉树有f(n)种形态，则可以递归的定义, 代码实现如下：
$$
f(n) = \sum_{i=0}^n-1 f(i)f(n-i-1), (0\leqi\leqn-1)
$$

```C
int numTreesResurve(int n){
    int sum = 0;
    if (n == 0){
        sum = 1;
    }
    for(int i = 0; i < n; ++i) {
        sum += numTreesResurve(i) * numTreesResurve(n - i - 1);
    }
    return sum;
}
```