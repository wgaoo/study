#!/bin/bash
# w_gao@foxmail.com
# Sun May 14 20:43:28 CST 2017

TARGET_DIR=$1

function untardir
{
	local CUR_DIR=$1
	echo "$(date): rescurive untar dir : ${CUR_DIR}"

	if [ -d ${CUR_DIR} ]; then
		for CHILD_COMPRESS_FILE in $(ls ${CUR_DIR}); do

			echo ${CUR_DIR}/${CHILD_COMPRESS_FILE} | grep "tar.gz" > /dev/null 2>&1
			if [ $? -eq 0 ]; then
				tar -zxf ${CUR_DIR}/${CHILD_COMPRESS_FILE} -C ${CUR_DIR}
			fi

			echo ${CUR_DIR}/${CHILD_COMPRESS_FILE} | grep "tar.bz2" > /dev/null 2>&1
			if [ $? -eq 0 ]; then
				tar -jxf ${CUR_DIR}/${CHILD_COMPRESS_FILE} -C ${CUR_DIR}
			fi

			echo ${CUR_DIR}/${CHILD_COMPRESS_FILE} | grep "zip" > /dev/null 2>&1
			if [ $? -eq 0 ]; then
				unzip ${CUR_DIR}/${CHILD_COMPRESS_FILE} -d ${CUR_DIR} > /dev/null 2>&1
			fi
		done

		for CHILD_DIR in $(ls ${CUR_DIR}); do
			# echo CHILD_DIR=${CHILD_DIR}
			if [ -d ${CUR_DIR}/${CHILD_DIR} ]; then
				untardir ${CUR_DIR}/${CHILD_DIR}
			fi
		done
	fi
}

untardir $1
exit $?