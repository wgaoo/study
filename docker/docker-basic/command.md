#容器
##容器(container)
+ docker search centos
+ docker pull centos
+ docker run centos /bin/echo "hello world"
+ docker ps -a
+ docker run --name mydocker -it centos /bin/bash
+ ip ad li    				#查看容器的ip地址，因为没有iptables命令
+ docker start 627c887e4a2d  	#启动容器
+ docker run -d --name mydocker1 centos 	# -d 指定从后台启动
+ docker run -d --name mynginx nginx		# 
+ 进入容器：
docker attach b1232ad6a24f				    # 进入容器，这种方法有时会失败，需要，可以通过：
	docker inspect --format "{{.State.Pid}}" mynginx   		获得容器的pid
	nsenter --target 4055 --mount --uts --ipc --net --pid	进入容器
docker exec ...
+ docker stop 627c887e4a2d				# 停止容器
+ brctl show: 查看docker的网桥

##镜像(image)
docker save ${cid} > ubuntu.tar 		#导出镜像，为镜像id
docker export ${iid} > mynginx.tar 		#导出容器，为容器id
##docker网络：
iptables -t nat -L -n ：可以看到对docker做了一个nat转换，在容器中可以上网
在容器中 ip ro li,可以看到容器中路由到docker0网桥地址
docker run -d -P --name mynginx1 nginx, docker ps -l 可以看到随机的端口映射
看到 0.0.0.0:1025->80,表示将80端口映射到1025,访问EIP的1025，可以看到nginx界面
docker run -d -p 91:80 --name mynginx2 nginx ,同样可访问EIP的91端口
##nginx：
/etc/nginx/nginx.conf
/etc/nginx/conf.d/default.conf,可以看到 root   /usr/share/nginx/html

##数据管理
1. 数据卷
	-v /data
		docker run -it --name volum-test1 -h nginx -v /data centos 
		docker inspect -f {{.Volumes}} volum-test1 错误，
			直接 docker inspect volum-test1 / docker inspect volum-test1 | grep Mounts -A 10 查看
	-v /opt:/opt 最后不能加斜线 vm:container
		/opt:/opt:ro 只读模式，## 也支持挂载文件
		docker run -it --name volume-test2 -h nginx -v /opt:/opt centos

2. 数据卷容器
	--volumes-from
	可以让一个容器存储数据
	docker run -it --name volume-test4 --volumes-from volum-test1 centos
	
3. docker的日志如何处理？直接写到物理主机

##镜像构建
1. 手动构建
docker run --name nginx-man -it centos
yum install -y wget gcc gcc-c++ make openssl-devel
wget http://nginx.org/download/nginx-1.11.12.tar.gz
mv *.gz /usr/local/src/
cd /usr/local/src/
tar zxf nginx-1.11.12.tar.gz
tar zxf pcre2-10.21.tar.gz
useradd -s /sbin/nologin -M www
cd nginx-1.11.12
./configure --prefix=/usr/local/nginx --user=www --group=www --with-http_ssl_module --with-http_stub_status_module --with-pcre=/usr/local/src/pcre2-10.21
make
make install
echo "/usr/local/sbin/nginx" >> /etc/rc.local
echo "daemon off;" >> /usr/local/nginx/conf/nginx.conf
docker commit -m "my nginx" 3687ae5dc519 mynginx:err 将容器制作为镜像
docker run -d -p 92:80 mynginx:err

2. 自动构建（Dockerfile）
+ 基础镜像信息
+ 维护者信息
+ 操作命令
+ 启动时执行的指令
+ 操作过程

**一个dockerfile例子**
目录结构

	[root@gw-centos7 docker-file]# tree /opt/docker-file/
	/opt/docker-file/
	└── nginx
	    ├── Dockerfile
	    └── test.tar.gz
Dockerfile内容

	# this is my docker file
	# version 1.o
	# Author w_gao@foxmail.com
	# Base images
	FROM centos
	# MAINTAINER
	MAINTAINER w_gao@foxmail.com
	# ADD
	ADD test.tar.gz /opt
	# RUN
	RUN yum install -y gcc
	# WORKDIR ~= cd
	WORKDIR /opt/test
	RUN touch test-workdir
docker build -t nginx-file:v1 /opt/docker-file/nginx/


