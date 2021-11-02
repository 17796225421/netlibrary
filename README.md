# 遇到的问题
## 一
Failed to connect to github.com port 443: 拒绝连接

解决方法：关闭vpn。
git config --global --unset http.proxy
git config --global --unset https.proxy

## 二 
git push rewrite-muduo master:master
fatal: 无法访问 'https://github.com/aqua5201314/rewrite-muduo.git/'：GnuTLS recv error (-54): Error in the pull function.

解决方法：网络不稳定，重启vscode，开启vpn