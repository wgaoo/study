#master
+ 环境配置
    host 192.168.163.148 安装etcd server以及kubernetes server，同时安装kubernetes client node，并且还需要安装docker；
    host 192.168.163.150 安装kubernetes client server 以及docker；
    host 192.168.163.138 安装kubernetes client server 以及docker；

+ 安装软件：
    yum install etcd kubernetes-master docker -y

+ 修改etcd参数：
    vi /etc/etcd/etcd.conf将以下几行进行修改，完成后保存退出。
    ETCD_NAME=default
    ETCD_DATA_DIR="/var/lib/etcd/default.etcd"
    ETCD_LISTEN_CLIENT_URLS="http://0.0.0.0:2379"
    ETCD_ADVERTISE_CLIENT_URLS="http://192.168.163.148:2379"

    systemctl enable etcd
    systemctl start etcd
+ 修改kubernetes server参数
    1. apiserver
        KUBE_ETCD_SERVERS="--etcd_servers=http://192.168.163.148:2379"
        KUBE_SERVICE_ADDRESSES="--service-cluster-ip-range=192.168.0.0/16"
    2. /etc/kubernetes/controller-manager
        KUBE_CONTROLLER_MANAGER_ARGS="--node-monitor-grace-period=10s --pod-eviction-timeout=10s"
    3.  /etc/kubernetes/config
        KUBE_MASTER="--master=http://192.168.163.148:8080"
    4. 启动服务
        systemctl enable kube-apiserver kube-scheduler kube-controller-manager
        systemctl start kube-apiserver kube-scheduler kube-controller-manager

#node
    以192.168.163.150为例
+ 安装
    yum install kubernetes-node flannel docker -y
    systemctl enable docker
    systemctl start docker
+ 接着我们需要配置flanneld，修改/etc/sysconfig/flanneld文件配置如下：
    FLANNEL_ETCD="http://192.168.163.148:2379"
    FLANNEL_ETCD_KEY="/coreos.com/network"
    systemctl enable flanneld.service
    systemctl restart flanneld.service
    systemctl restart docker
    
+ 修改/etc/kubernetes/config跟上面的修改一致；

/etc/kubernetes/kublet文件进行以下修改：
KUBELET_HOSTNAME="--hostname_override=192.168.163.150"
KUBELET_API_SERVER="--api_servers=http://192.168.163.148:8080"
修改完后保存退出并启动服务

systemctl enable kubelet kube-proxy
systemctl start kubelet kube-proxy
启动节点都按照这样的设置就可以完成

最后用kubectl get nodes查看节点状态

