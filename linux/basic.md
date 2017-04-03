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
        
##系统引导启动流程
###系统的启动流程
2) 固件启动，POST加电自检（部分设备直接进入固件操作界面，硬件设置），进入BIOS
    a) 安全设置
    b) 引导介质列表
    c) 电源管理    
    d) BIOS/固件时钟（与操作系统无关，hardware clock）；
        hwclock命令，查看固件时间；date查看系统时钟
        硬件时间与系统时间同步
        hwclock –help
        修改时间的方法
        
        遇到time error时，注意查看此选项
    e) 若新添加硬件，比如硬盘，先到固件中查看是否检测此设备
3) MBR（Must Boot Record）
    在0磁头，0柱面，0扇区，包含三个内容
4) BootLoader（446 B/bytes）自举程序
5) Partition table（64B）磁盘分区表
6) Magic Number（2B）结束标志字
1. 载入BootLoader，Linux中的BootLoader为Grub，比较老的或嵌入式中BootLoader lilo，Windows BootLoader为ntldr（nt：new thchnology）
    /etc/grub.conf为grub的配置文件，记录了linux内核存放的位置，vmlinuz（用z表示为压缩文件），内核版本号：2.6.18（主版本号.次版本号（奇数为测试版，偶数为正式版）.末版本号）
1) 载入内核（为单个压缩过的可执行文件）（硬件驱动）
    /vmlinuz为指向内核文件的连接
    /usr/src/linux中存放了内核的源代码文件
    /boot中存放了linux内核可执行文件
    内核做两件事：
    a) 驱动硬件
    b) 启动init进程
2) init进程，pid恒为1，ppid父进程（0为内核调度器）
    1. 父进程终止，子进程必须终止（父进程死了，子进程没死，则系统将其父进程指向为init），成为孤儿进程
    2. 子进程死亡，而父亲不知道（父进程和子进程存在联系），则称为zoobi进程
6) 读取执行配置文件/etc/inittab
    grep –v “^#” /etc/inittab | more 
    man inittab，查看inittab配置文件的帮助
    配置linux的运行级别，runlevel
    0：hault=shutdown关机
Ø 1：单用户模式，这种模式类似于windows的安全模式（没有图形界面，只有root可以登录）
Ø 2、3：字符界面的多用户模式，是最常用的服务器模式；2没有nfs服务，是network file system系统，nfs简单易用，但安全性并不好；推荐使用ftp、ssh服务传输文件；
Ø 4：没有使用，用户自己定义
Ø 5：系统缺省的运行级别-X11，X-Xwindow图形界面，11为版本号
Ø 6：reboot重启
    使用runlevel查看当前运行级别；
    切换运行级别，调用init X切换运行级别；init s/S切换到单用户运行级别
7) /etc/inittab文件的四个部分
a) id：唯一性标识，1-4位的字母或数字
b) run-levels：指定运行级别，可以指定多个
c) action：指定运行状态
Ø initdefault：指定系统缺省启动的运行级别（id：3：initdefault）
Ø sysinit：指定系统启动，任何级别都运行的脚本，有/etc/rc.d/rc.sysinit（启动系统服务：环境变量设置、时间设置、日志等）
Ø wait：执行完脚本后，才能进行下一步操作
Ø once：执行，并不等待
Ø ctrlaltdel：可以用Ctrl+Alt+Del，进行关机
Ø x：5：respawn：/etc/X11/prefdm –nodaemon仅在运行级别5执行命令
d) process：指定要运行的脚本或命令
e) inittab中终端（Ctrl+Alt+F1-6）切换到命令行终端
    Ctrl+Alt+F7，最后一个回到图形界面
8) /etc/rc.d/rc #判断initdefault，对应启动对应/etc/rc.d/rcn.d下的脚本
    a) 手动启动服务/etc/rc.d/init.d/目录下存放了所有启动脚本，rc#.d下仅为链接
    b) 用/etc/rc.d/init.d/sshd start，重启sshd服务
9) /etc/rc.d/rcn.d在n运行级别执行的脚本
a) 以大写S开头：S-Start，该运行级别要启动的；紧跟着的数字，表示启动顺序；最后是脚本名称；（xwindow，图形用户界面）
b) 以大写K开头：K-Kill，该运行级别要关闭的；
    改变命名规则，比如S->s，则该脚本不执行
10) 弹出username、password，验证
VIM
三种模式
解决库依赖
Www.rpmfind.com 解决库依赖
常用操作
1) 设置自启动程序
a) 编写脚本，ln –s创建软链接到/etc/rc.d/init.d和/etc/rc.d/rcn.d
b) 将K->S，或使用命令
    chkconfig –list 列出所有服务的缺省启动状态
    chkconfig –-levels X 服务名 on/off（chkconfig –level 235 off）
    ntsysv –level X
2) dmsg，查询所有系统启动的信息（dmsg | grep eth0，查看启动过程中是否启动网卡）
3) /var/log查看启动日志文件boot.log或者messages保存系统日常日志
##GRUB
grub所在的根目录即在/boot
1. 配置文件/boot/grub/grub.conf，软链接/etc/grub.conf，文件内容
    ○ default：指定缺省启动系统
    ○ timeout：指定缺省启动时间
    ○ splashimage：定义grub启动背景图=（hd0，0）/grub/splash.xpm.gz表示第0块硬盘的第0个分区（即根分区），（Linux中的Photoshop，gmap）
    ○ title：定义标题
    ○ root：（hd0,0）定义/boot所在位置
    ○ kernel：定义内核所在位置
    ○ initrd：载入镜像文件
2. 使用案例
3. 忘记root密码（进入grub修改）
    进入单用户模式，疯狂按【Esc】按钮，进入grub；
    使用以下命令：e编辑当前的启动菜单项目；c进入grub的命令行方式；b启动当前的菜单项；d删除当前行；Esc返回到GRUB启动菜单界面；
    按【e】进入GRUB编辑菜单
    移动到Kernel行，编辑指定内核行，加入如下命令：
    
    则可直接进入运行级别1
    键入b建，之间开始运行内核（单用户模式只有root可以进入，且不需要密码）
    直接用password root即可更开root的密码
4. 给GRUB添加密码
    grub>md5crypt
    grub-md5-crypt
    md5crypt
    在title之间，键入password –md5 XXX（md5加密后的密码）
5. grub配置文件错误，file not found
    按c进入grub命令行
    然后手动用命令行方式引导
6. /etc/inittab损坏或被删除
    此时没有运行级别，系统无法正常引导
    进入系统修复模式，光驱中有光盘，设置通过光盘引导，按F2进入BIOS设置模式，按F5进入rescue mode，载入光盘Linux修复环境，chroot /mnt/sysimage改变根分区，查看init进程为何不能引导
软件包管理
用户管理
进程管理

##进程管理的概念
进程和程序的区别：进程是动态、程序是静态；进程与程序无一一对应关系；
孤儿进程：父进程消失了，子进程还在运行
zoobi进程：子进程已经挂掉，父进程不知道
前台进程：find / -name init
后台进程：find / -name init > /test/init.find &（后台执行符号）
进程的状态：就绪状态、等待状态、运行状态
详细划分：
###进程管理命令
1. w查看当前所有登录用于信息，其中JCPU所有终端相关进程所占用时间，PCPU终端执行程序所占用时间，WHAT用户正在做什么；load average记录1/5/15分钟的负载程度；IDLE表示系统闲置时间；
2. ps命令
    a：显示所有用户的进程
    u：显示用户名和启动时间
    x：显示没有控制终端的进程
    e：显示所有进程，包括有和没有终端的
    l：长格式显示
    w：宽行显示，可以使用多个w进行加宽
    ps命令选项：PID、
    --sort PID/UID/TIME…
    ps –uU gao，查看gao的占用
    pstree：进程树
3. kill命令
    kill 【PID】：杀死父进程
    kill –l 列出所有kill的信号
    kill -9 【PID】：信号9，强制关闭
    kill -1 重启进程
    xkill 图形界面杀死进程
    killall：关闭所有同名的进程
    ls /proc中存放进程相关信息；/proc/cpuinfo cpu信息；/proc/meminfo内存信息；/proc/partitions分区信息
    pgrep：查看PID；pgrep httpd
    pkill：关闭其父进程
4. 关于优先级的命令
    ○ nice：指定程序运行的优先级
        nice –n command
        nice -5 myproc
    ○ renice：改变一个正在运行进程的优先级
        格式：renice n pid
        例如：renice -5 777
        优先级取值范围（-20-19）数字越小优先权越大
5. nohup希望命令在用户推出后仍执行
    格式：nohup commond &（后台执行符号）
6. 进程小关小操作
7. 进程的终止
    CTRL+Z挂起（暂停）、CTRL+C终止
8. 进程的恢复（jobs查看暂停、后台运行的进程）
    fg 编号：切到后台（编号通过jobs查到）
    bg 编号：切到前台
9. top
    d：指定刷新时间间隔
    k：kill
    c：显示整个命令行
    u：查看指定用户的进程
    h/?：help
    r：重新设置优先级
    计划任务
    Linux文件系统管理

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

##备份与恢复
备份介质
    硬盘：
    光盘：XXX
    磁带：XXX（便宜，适合海量存储）
    可移动存储设备：
策略
1. 完全备份
     
2. 增量备份
     
3. 系统备份
    /etc、/boot、/var/lob、/usr/local
4. 用户数据备份
    /home，采用增量备份的方式
    建立备份日志
流程
    1. 备份
    2. 备份分区ro（read only）、umount（远程、卸载备份分区）
    3. 压缩bzip2（空间小，不易损坏）
    4. 校验md5sum –c
    5. 加密CnuPG、PGP（windows）
            对称秘钥：加密锁密同一个密码
            非对称秘钥：公钥+私钥
        ○ cp：
                -p ：保留原文件所有属性（修改时间等）
                -u：增量备份
        ○ tar
         
##日志管理
Shell编程 
    Secure Shell（安全壳协议）
    原来的telnet，没有加密，很危险
SSH服务管理
 
DHCP服务管理
