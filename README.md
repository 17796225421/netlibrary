# 遇到的问题
## 一
git无法同步到github，如443错误，这时候八成你也无法ping通github（长城）
```
vim /etc/hosts
```
打开https://websites.ipaddress.com/www.github.com  得到github实时ip，
在vim中添加：实时ip github.com