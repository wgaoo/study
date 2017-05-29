##ssh加密过程
非对称加密算法（使用公钥加密，然后用私钥解密）
ssh加密过程：
    1）首先将公钥下载到本地
    2）使用公钥加密后，传输到服务器（ssh只能保证传输过程中的安全，本地中木马无法保护）
    3）ssh链接时，第一次要下载并保存公钥（1024位的公钥）
    4）
##ssh的配置文件
####服务器端配置文件
Port 22 #端口号
ListenAddress 0.0.0.0，监听ip地址，0.0.0.0表示监听任何（在本机有多个ip时使用）
HostKey：保存密钥对信息
SyslogFacility：日志
LogLevel：日志等级
GSSAPIAuthentication： GSS验证，使用DNS的方式验证，只要开启该认证，就会等很久

PermitRootLogin no
PubkeyAuthentication yes
AuthorizedKeysFile .ssh/authorized_key：公钥保存位置
PasswdAuthentication yes：是否使用密码验证
PermitEmptyPasswords no：不允许空密码登录
####ssh_config客户端
改变GSSAPIAuthentication的客户端也可以，最好改为GSSAPIAuthentication no

##ssh命令
ssh
scp
sftp
    sftp root@xxx.xxx.xxx.xxx
    help查看帮助信息
        ls：查看远程
        lls：查看本地

##ssh密钥对登录