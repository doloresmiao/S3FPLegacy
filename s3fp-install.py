#!/usr/bin/env python 

import os
import sys
import subprocess as subp

if (len(sys.argv) != 2): 
    print ("Usage: s3fp-install.py [option]")
    print ("[option] = build | clean")
    sys.exit() 
OPT = sys.argv[1].strip() 


if (OPT == "build"):
    os.system("libtoolize")
    os.system("aclocal")
    os.system("automake --add-missing")
    os.system("autoconf")
    os.system("./configure --prefix=/home/wfchiang/tools/s3fp")
    os.system("make") 

elif (OPT == "clean"):
    os.system("make clean") 
    os.system("rm *~ aclocal.m4 config.guess config.log config.status config.sub configure depcomp missing install-sh ltmain.sh libtool") 
    os.system("rm -rf autom4te.cache") 

    rm_makefile = subp.Popen("find ./ -type f -name \"Makefile\"", shell=True, stdout=subp.PIPE, stderr=subp.PIPE)
    rm_makefile.wait()
    for aline in rm_makefile.stdout: 
        aline = aline.strip().decode("utf-8")
        if (aline.endswith("Makefile") and not "fpbench" in aline):
            os.system("rm " + aline) 

    rm_makefile = subp.Popen("find ./ -type f -name \"Makefile.in\"", shell=True, stdout=subp.PIPE, stderr=subp.PIPE)
    rm_makefile.wait()
    for aline in rm_makefile.stdout: 
        aline = aline.strip().decode("utf-8")
        if (aline.endswith("Makefile.in") and not "fpbench" in aline):
            os.system("rm " + aline)          

    rm_makefile = subp.Popen("find ./ -type f -name \"*.Po\"", shell=True, stdout=subp.PIPE, stderr=subp.PIPE)
    rm_makefile.wait()
    for aline in rm_makefile.stdout: 
        aline = aline.strip().decode("utf-8")
        os.system("rm " + aline)                         

else:
    sys.exit("ERROR: invalid option: " + OPT) 
