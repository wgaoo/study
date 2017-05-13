#Linux基础
##基本命令
###文件权限
useradd adduser
chown：修改所属组
chgrp lampbrother liming：将liming用户改变所属组为lampbrother
文件所有者：创建者；所属组：
umask：定义文件默认的权限，
umask –S：显示新建文件的默认权限（touch的文件，会少x权限，Linux中规定，缺省创建的问题件没有可执行权限）
umask：写出来很奇怪，权限掩码（777-022=755）
##文件搜索命令
尽量减少搜索，占用资源比较多；windows everything（只支持NTFS分区）
find命令：find 【搜索范围】【匹配条件】
• 根据名查找
    -name 根据文件名搜索，*匹配所有；？匹配单个
    -iname不区分大小写的搜索
• 根据大小查找
    -size +/-/ +：表示大于，-表示小于，不加表示刚好等于
    单位是数据块，一个数据块默认是0.5K字节
    /proc目录，经常发生变化，会有错误提示，正常
• 根据所有者查找
    -user根据用户查找
    -group根据所属组查找
• 根据时间查找
    $find /etc –ctime -5（5分之内，文件属性更改的文件）
    -amin 访问时间access
    -cmin 文件属性change（所有者、所属组、权限等被修改时间）
    -mmin文件内容modify
    根据文件类型查找
    -type f：文件 d目录 l软连接
    -inum根据i节点查找，
• 控制
    find /etc –size +163840 –a –size -204800
    -a 表示and，两个条件都必须满足
    -o表示or
    find /etc –name inittab –exec ls –l {} \;
    -exec
    -ok：需要询问确认，比如对find的结果进行删除
    {}\;{}表示find查找的结果，\;表示转义结束
• locate命令
实现快速查找，按照历史记录查找；建立文件资料库（在资料库中找）
locate init
locate维护的文件资料库
locate locate 可以看到var/lib/mlocate/mlocate.db，即为locate查找的资料库
但是有的文件无法locate到，因为没有建立索引
updatedb：升级locate对应的文件资料库，但是在/tmp下创建的文件找不到（因为该文件不存放在文件资料库中）
locate -i 查找时不区分大小写
• whichi搜索命令
查看命令的目录
同时可以得到命令是否有别名相关的信息
• whereis命令
• grep在文件内容中搜索
Grep multiuser /etc/inittab
-I 不区分大小写
-v 排除指定的字
a) 帮助命令
    a. man命令
    最前面部分，命令的简单介绍
    1对命令的帮助，5对配置文件的帮助
    b. info额外的帮助命令
    c. help可以查看shell内置命令的帮助信息
    Help if
b) 打包命令
c) 网络命令
    a. Write（只能给在线用户发送）
    write xxxx ! 最后按ctrl+D退出
    b. wall（write all，给所有用户发信）
    Wall xxxx
    Ping 自己的ip地址表示网络是通的（不是127或localhost）
    mail发送邮件
    
    mail
    help
    1
    h
    d + [num]
    c. last列出曾经登录的时间信息
    Lastlog
    Traceroute
    netstat
    -tuln 查看本机监听的端口
    -an 查看所有的监听信息，会显示状态，更多
    -rn查看网管
1) 密码更改
    root用户可以更改任何人的密码
    who查看当前的登录用户
    终端：tty本地终端
        pts：远程登录
    w：得到更详细的用户登录信息
    uptime：查看时间
        

软件包管理
用户管理
进程管理

###文件系统构成
1) /usr/bin /bin存放用户可执行命令
    • /usr/sbin /sbin
    • /home：用户缺省宿主目录
    • /proc：虚拟文件系统，存放当前内存镜像
    • /dev：存放设备文件
    • /lib：存放系统系统运行所需共享库
    • /lost+found：存放系统出错检查结果
    • /tmp：存放临时文件
    • /etc：存放配置文件
    • /var：包含经常发生变化的文件，如邮件、日志、计划任务
    • /usr：存放所有命令、库、手册（unix software resource）；/usr/local存放第三方库
    • /mnt：临时文件系统的安装点
    • /boot：自举程序启动目录（存放GRUB、内核）
2) 常用命令
+ df：查看分区情况
    -h/m：以M的方式，人性化的方式显示
+ du：查看文件和目录大小
    -h：以人性化的方式显示
+ fsck、e2fsck：检测文件系统，在单用户模式使用
    -p分区名：修复分区；-y：yes：自动修复
+ file：判断文件类型
设备挂载
1. 设备类型：
    字符块设备：光盘、硬盘（快），ll查看时标记为b
    字符设备：打印机（慢），ll查看时标记为c
2. 挂载光盘
    mount /dev/cdrom /mnt/dcrom：光盘已经放进去了
    /dev/cdrom/CentOS存放了安装文件
    df看到光盘挂载信息
3. 卸载光盘
    umount 【挂载点】
    eject：
###分区与格式化管理
1. 添加硬盘或分区
    a. 创建分区fdisk：
        fdisk –l：查看磁盘分区信息；fdisk –l /dev/sdb
        fdisk /dev/sdb进入界面
            m：帮助信息
            p：打印分区表
            n：添加新的分区
            t：改变分区文件类型
            d：删除分区
            w：保存退出
            q：不保存退出
            fdisk /dev/sdb（不一定是sdb，根据插槽确定）
    b. mkfs格式化文件系统
        mkfs：mkfs.ext3 /dev/sdb1
        -b：在格式化时指定数据块大小
    c. 挂载
        mount /dev/sdb1 /web，然后就可以使用了
        df查看分区信息
    d. 写入配置文件
            /etc/fstab    六个部分
        § 物理名、卷标（ID）
        § 挂载点（文件夹名）
        § 文件系统类型
        § 缺省设置
        § 是否在引导时进行检测（0：不检测；1：检测）
        § 检测顺序（0:1:2：）
            /dev/sdb1  /web  /ext3    default    1    2
            e2label指定卷标：e2label 分区名 卷标
2. swap file
    a. 用dd命令创建固定大小文件
        数据拷贝：dd if=/dev/sda of=/dev/sdb将sda的数据完全拷贝到sdb
        创建指定大小文件：dd if=/dev/zero of=/var/swap/file.swap bs=1024（数据块大小） count=xx（块数），创建xxk大小的文件
        /dev/zero伪设备，不断的写入0
        /dev/null黑洞伪设备
    b. makeswap  /var/swap/file.swap，将刚才的固定大小文件当做swap空间来用
    c. swapon  /var/swap/file.swap启用swap空间
    d. swapoff  可以关闭swap空间
    e. 编辑/etc/fstab，使得开机自动加swap空间
        /var/swap/file.swap  swap  swap  default  0  0

##磁盘配额
磁盘配额只能针对分区来设置（指定用户在各个分区用多少），在/etc/fstab文件中设置
userquota/groupquota，给/dev/sda2，/test目录添加配额信息
1. 开启分区的磁盘配额功能
    在第四个位置，添加,userquota（组配额添加,groupquota）
2. 创建配额数据库
    使用quotacheck –cvua（c：创建，v：显示详细信息，u：建立用户配额，g：建立组配额，a：自动创建）
    打开/test文件，可以看到创建的配额文件
3. quotaon /test开启配额信息
4. 编辑用户配额信息
    edquota gao：进入vim界面，开始配置gao的配额信息
    block（soft+hard）：空间大小
    inodes（soft+hard）：文件数目（i节点数目）
5. quota 用户名：查看用户的配额信息
6. repquota /test查看目录下每个用户的配额信息
7. edquota –p Helen samlee xxx xxx拷贝helen的用户信息
    for xxx in xx do:
        edquota –p Helen xxx
    done