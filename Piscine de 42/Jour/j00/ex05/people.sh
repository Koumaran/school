ldapsearch -Q uid="z*" cn | grep "^cn" | cut -d " " -f 2-3 | sort -fr
