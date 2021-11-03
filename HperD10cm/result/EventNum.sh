#! bin/bash
dir_path=`pwd`
#find $dir_path -name "EventNum.txt" > EventNumLog.txt
find .. -name "EventNum.txt" > EventNumLog.txt
#awk -F/ '{printf $2"\n"}' EventNumLog.txt
cat 'EventNumLog.txt'|while read line
do 
    echo ${line}|awk -F/ '{printf $2"\t"}' >> output.txt
    head -n1 ${line}|awk '{printf $2"\n"}' >> output.txt
done



