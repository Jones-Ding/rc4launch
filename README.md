# rc4launch

## 简介

一个简单的 RC4 加密的启动器



## 用法

```shell
./rc4launch -[参数] src pwd
```

参数为 *十六进制(**x**)* 和 *字符串(**s**)*



e.g.

```shell
./rc4launch -sx hello rc4
# 输入值为字符串，输出为16进制

./rc4launch -ss hello rc4
# 输入值为字符串，输出为字符串

#...
```

