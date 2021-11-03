#!/bin/bash
time2=$(date "+%Y%m%d%H%M")
# 加入时间后缀，方便之后的批量计算
for i in $1;do
# 这里可以改成 for i in 115.23 137.34 157.28 175.14;do 这样就不需要传递参数（直接把需要设置的参数传入脚本）
# 如果有其他变量的话增加循环的层数即可，增加
	mkdir "$i-$time2"
	cd "$i-$time2"
	cp -r ../base/mac ./
	cp -r ../base/data ./
	#mkdir output
	cp -r ../base/output ./
	e=$(echo "$i * 12" | bc)
	# 这里计算MeV/u对应的能量
	
	sed -i "/\/gps\/energy/s/\b[0-9]\{4\}\b/$e/" mac/main.mac
	#先使用/gps/energy找到对应的行，而后使用正则表达式替换4位数字,修改不同能量

	sed -i "/\/control\/execute/s/400/$i/" mac/HIMM_room2.mac
	#替代400，更换不同ridge filter,sed 后有变量时使用双引号

	pwd
	cd ../
done

