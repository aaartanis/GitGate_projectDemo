#! bin/bash
# author:huangshengcong

function mergefile {
	file_list=()
	for m in `seq 1 $core_numb`;do
	#echo $i
	file_list+=$target$m".root  "
	done
	hadd $target_file $file_list
}
time=$(date "+%Y%m%d%H%M")
result_path=$(pwd)/result/
core_numb=48

i=0
while i==1;do
	echo "---------------------------------"
	echo "Please enter the project keywords"
	echo "---------------------------------"
	read keywords 
	echo ""
	echo "The following calculation item are detected"
	echo ""

	ls | grep $keywords
        file_name=`ls | grep $keywords`

	echo "Excute or not? [y/n]"
	read agree_to_excute

	if [ $agree_to_excute == "y" ];then # $agree_to_excute "y" 前后有空格
		break
	fi
	echo "Reselect keywords? [y/n]"
	read reselect
	if [ $reselect == "n" ];then
		break
	fi
done

#loop iso
#deg=("0deg" "45deg" "90deg")
deg=("90deg")
distance=("25cm" "50cm" "100cm" "150cm" "200cm")
for i in $file_name;do
	mkdir $result_path/$i
	pwd
	cd $i
	pwd
	cd output
	pwd
	
	#if 0;then
	n=10
	for j in ${deg[@]};do
		cd $j
		for k in ${distance[@]}; do
			cd $k
			let n++
			target=$n"_receptor"
			target_file=$n"_receptor.root"
			rm -f $target_file
			mergefile
			cp $target_file $result_path/$i/$target_file
			cd ..
		done
        cd ..
	done

	cd iso
	target=0_receptor
	target_file=0_receptor.root
	rm -f $target_file
	mergefile
	cp $target_file $result_path/$i/$target_file
	cd ../
	#fi
	
	
    cd ../
    cd ../
done
