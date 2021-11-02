# 遇到的问题
## 一
Failed to connect to github.com port 443: 拒绝连接

解决方法：关闭vpn。

或者
git config --global --unset http.proxy
git config --global --unset https.proxy

或者
window ipv4 dns修改为8.8.8.8

## 二 
git push rewrite-muduo master:master
Git:RPC失败。curI7 GNUTLS recy error(-54): Error in the pull function

解决方法：
网络不稳定，重启vscode，开启vpn

或者
git config --global http.postBuffer 1048576000