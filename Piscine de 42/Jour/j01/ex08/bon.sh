ldapsearch -Q -LLL "sn=*bon*" sn | grep sn | wc -l | awk '{print $1}'
