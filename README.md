# spellCorrect

标签（空格分隔）： 中文编辑距离 缓存

---

这是一个简单的文本纠错程序。
> 1.系统启动时，开启工作线程池，开启扫描线程，根据本地词库建立索引(gbk字符集)。
> 2.从客户端输入查询`query`时，服务器首先查询缓存。有，返回；没有，则根据`query`做编辑距离计算，求出最小的编辑距离。
> 3.将查询放入缓存，返回结果。