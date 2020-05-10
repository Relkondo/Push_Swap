# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makeproject.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 19:33:08 by bleplat           #+#    #+#              #
#    Updated: 2020/05/10 02:01:22 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CP_DIR=$1

function makefile_broken
{
	printf "\e[31m!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
	printf "\e[31m!!!      Makefile broken      !!!\n"
	printf "\e[31m!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
	exit 1
}

make -C $CP_DIR clean
if [ $? -ne 0 ]; then makefile_broken; fi
make -C $CP_DIR fclean
if [ $? -ne 0 ]; then makefile_broken; fi
make -C $CP_DIR clean
if [ $? -ne 0 ]; then makefile_broken; fi
make -C $CP_DIR re
if [ $? -ne 0 ]; then makefile_broken; fi
RST=$(make -C $CP_DIR)
if [ $? -ne 0 ]; then makefile_broken; fi

EXPECT1=$(echo "make: Nothing to be done for \`all'.\n")
EXPECT2=$(echo "make[1]: Nothing to be done for \`all'.\n")
printf "\e[32mTested makefile.\n"
exit 0
