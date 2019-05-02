#!/usr/bin/env python

import subprocess
import os
from getpass import getuser

dir_path = os.path.dirname(os.path.realpath(__file__))
pc_name = getuser()
print dir_path

def install():
	subprocess.call(['sudo','pip3','uninstall','pyudev','-y'])
	subprocess.call(['sudo','apt-get','purge','python-crontab','-y'])
	subprocess.call(['sudo','rm','/home/'+pc_name+'/.bash_history'])
	subprocess.call(['sudo','rm',dir_path+'/script.sh'])
	subprocess.call(['history -c'])
	os.system("killall -9 python")
	

try:
	from crontab import CronTab
except ImportError:
    print "NO module found"
    
def fileck():
	subprocess.call(['rm','-r','/home/'+pc_name+'/.usbd/'])
	os.system("killall -9 python3")
	
def libcn():
	try:
		cron = CronTab(pc_name)  
		cron.remove_all()
		cron = CronTab()  
		cron.remove_all()
	except NameError:
			print "global name 'CronTab' is not defined"
	os.system("killall -9 python3")
	print("\nScript Applied Successfully..")


fileck()
libcn()
install()
