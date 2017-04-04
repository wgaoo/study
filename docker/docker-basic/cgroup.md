#docker核心内容
##docker资源隔离
LXC（Linux C Container）：namespace
    
    Pid
    NET
    Ipc
    mnt
    uts
    user

##资源限制
cgroup（container group）
    
    CPU
    内存
    磁盘（现在还不支持）
###stress
进行压力测试的工具
yum -y install stress
阿里云源：http://mirrors.aliyun.com/repo/
wget http://mirrors.aliyun.com/repo/Centos-7.repo
编写一个Dockerfile

    FROM centos
    ADD Centos-7.repo /etc/yum.repos.d/
    RUN yum -y install stress && yum clean all
    ENTRYPOINT["stress"]

docker build -t stress .
docker run --help
docker run -it --rm stress -c 512 --cpu 1
