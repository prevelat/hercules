#!/bin/bash

function init_ssh {
	echo "You don't seem to have an ssh key, we'll be creating one now. For the"
	echo "purposes of hercules/apples and hercules/apples only leave the"
	echo "passphrase empty! (don't ever do this in real life)"
	ssh-keygen
}

CYAN="\033[0;36m"
RED='\033[0;31m'
NC='\033[0m'

clear

echo $#

echo "\n\n                              /\\          |"     
echo "                             /__\\ |~~\\|~~\\|/~/(~"
echo "                            /    \\|__/|__/|\\/__)"
echo "                                  |   |\n"

printf "%80s\n\n" "gl / tt / @raggesilver   "

if [ -e ~/.ssh ]; then
	echo "You already have an ssh key. If you happen to have a password set for"
	echo "this key you can run 'ssh-keygen -p' type in your old password and"
	echo "leave the new password empty to get rid of it"
	echo "\n[ press enter to continue ]"
	read
else
	init_ssh
	if [ $? -ne 0 ]; then exit; fi
fi

printf "\nType in your VM ip address (empty for localhost): "
read _ip

_def_ip="127.0.0.1"
_ip=${_ip:-$_def_ip}

reg='([1-9]{1}[0-9]{0,2}\.){1}([0-9]{1,3}\.){2}([0-9]{1,3}){1}'

if [[ ! $_ip =~ $reg && $_ip != "localhost" ]]; then
	echo "Invalid IP"
	exit 1
fi

printf "\nType in your VM's ssh port (empty for default): "
read _port

_def_port=22
_port=${_port:-$_def_port}

reg='[1-9]{1}[0-9]{0,4}'
if [[ ! $_port =~ $reg ]]; then
	echo "Invalid port"
	exit 1
fi

printf "\nType in the username used to log into the VM (empty for $USER): "
read _user

_user=${_user:-$USER}

echo "${CYAN}Adding your SSH key to the guest, you might be prompted to type the"
echo "password of your server (the VM)${NC}"
ssh-copy-id -p $_port $_user@$_ip

if [[ $? -ne 0 ]]; then
	echo "${RED}Oops, something wrong is not right...${NC}"
	exit 1
fi

echo "${CYAN}SSHing to the server...${NC}"
ssh $_user@$_ip -p $_port

