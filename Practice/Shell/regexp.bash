1、查找不以大写字母开头的行（三种写法）。
grep '^[^A-Z]' 2.txt
grep -v '^[A-Z]' 2.txt
grep '^[^[:upper:]]' 2.txt
2、查找有数字的行（两种写法）
grep '[0-9]' 2.txt
grep -P '\d' 2.txt
3、查找一个数字和一个字母连起来的
grep -E '[0-9][a-zA-Z]|[a-zA-Z][0-9]' 2.txt
4、查找不以r开头的行
grep -v '^r' 2.txt
grep '^[^r]' 2.txt
5、查找以数字开头的
grep '^[0-9]' 2.txt
6、查找以大写字母开头的
grep '^[A-Z]' 2.txt
7、查找以小写字母开头的
grep '^[a-z]' 2.txt
8、查找以点结束的
grep '\.$' 2.txt
9、去掉空行
grep -v '^$' 2.txt
10、查找完全匹配abc的行
grep '\<abc\>' 2.txt
11、查找A后有三个数字的行
grep -E 'A[0-9]{3}' 2.txt
grep  'A[0-9]\{3\}' 2.txt
12、统计root在/etc/passwd里出现了几次
grep -o 'root' 1.txt |wc -l

13、用正则表达式找出自己的IP地址、广播地址、子网掩码
ifconfig eth0|grep Bcast|grep -o '[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}'
ifconfig eth0|grep Bcast| grep -E -o '([0-9]{1,3}.){3}[0-9]{1,3}'
ifconfig eth0|grep Bcast| grep -P -o '\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}'
ifconfig eth0|grep Bcast| grep -P -o '(\d{1,3}.){3}\d{1,3}'
ifconfig eth0|grep Bcast| grep -P -o '(\d+.){3}\d+'

# egrep --color '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' /etc/sysconfig/network-scripts/ifcfg-eth0
IPADDR=10.1.1.1
NETMASK=255.255.255.0
GATEWAY=10.1.1.254

# egrep --color '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' /etc/sysconfig/network-scripts/ifcfg-eth0
IPADDR=10.1.1.1
NETMASK=255.255.255.0
GATEWAY=10.1.1.254


14、找出文件中的ip地址并且打印替换成172.16.2.254
grep -o -E '([0-9]{1,3}\.){3}[0-9]{1,3}' 1.txt |sed -n 's/192.168.0.\(254\)/172.16.2.\1/p'

15、找出文件中的ip地址
grep -o -E '([0-9]{1,3}\.){3}[0-9]{1,3}' 1.txt

16、找出全部是数字的行
grep -E '^[0-9]+$' test
17、找出邮箱地址
grep -E '^[0-9]+@[a-z0-9]+\.[a-z]+$'


grep --help:
匹配模式选择：
Regexp selection and interpretation:
  -E, --extended-regexp 扩展正则
  -G, --basic-regexp 基本正则
  -P, --perl-regexp 调用perl的正则
  -e, --regexp=PATTERN use PATTERN for matching
  -f, --file=FILE obtain PATTERN from FILE
  -i, --ignore-case 忽略大小写
  -w, --word-regexp 匹配整个单词
