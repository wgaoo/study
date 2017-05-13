查看版本号
##systemctl
1. 查看系统版本号
    $ systemctl --version
2. 重启系统
    $ sudo systemctl reboot
3. 关闭系统，切断电源
    $ sudo systemctl poweroff
4. CPU停止工作
    $ sudo systemctl halt
5. 暂停系统
    $ sudo systemctl suspend
6. 让系统进入冬眠状态
    $ sudo systemctl hibernate
7. 让系统进入交互式休眠状态
    sudo systemctl hybrid-sleep
8. 启动进入救援状态（单用户状态）
    $ sudo systemctl rescue

##systemctl-analyze
    # 查看启动耗时
    $ systemd-analyze                                                                                       

    # 查看每个服务的启动耗时
    $ systemd-analyze blame

    # 显示瀑布状的启动过程流
    $ systemd-analyze critical-chain

    # 显示指定服务的启动流
    $ systemd-analyze critical-chain atd.service
