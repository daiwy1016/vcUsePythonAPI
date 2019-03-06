#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2019-03-06 07:15:30
# @Author  : 小戴 (408366645@qq.com)
# @Link    : http://www.phpet.com/
# @Version : $Id$

import os,sys
def walk_dir(dirpath,dirfile):
     if not os.path.exists(dirpath) :
         print ("%s does not exits, please try again !",dirpath)
         return -1
     print ("111");
     dirtuple=[dirs for dirs in os.walk(dirpath)][0]
     print (dirtuple);
     return -1
     root=dirtuple[0]
     #print 'root is',root
     if root[len(root)-1] != os.sep :
         root+=os.sep
     
     f=file(dirfile,'a')
     for files in dirtuple[2]:
         f.write('%s\n' % (root+files))
         f.flush()   #avoid buffer overflow
     f.close()
     return 1
#walk_dir('F:\\vsproj\\ConsoleApplication1\\ConsoleApplication1','F:\\vsproj\ConsoleApplication1\\ConsoleApplication1\\test.py')