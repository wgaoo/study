kubectl create -f nginx-pod.yaml
错误，这是因为鉴权错误，需要修改/etc/kubernetes/apiserver，注释掉ServiceAccount参数
继续执行：kubectl create -f nginx-pod.yaml
如果状态异常，则添加：/etc/sysconfig/docker，INSECURE_REGISTRY='--insecure-registry gcr.io'