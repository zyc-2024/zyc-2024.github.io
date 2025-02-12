import time,sys
import urllib3
import random
import re

def get_header(pid):
    headers=[
    "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko",
    "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.116 Safari/537.36",
    "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:48.0) Gecko/20100101 Firefox/48.0",
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.79 Safari/537.36 Edge/14.14393"
    ]
    Referer='http://www.luogu.org/problem/lists?name=&orderitem=&order=&tag=&page='+str((pid-1000)/50+1)
    return {'User-Agent':headers[random.randint(0,3)],'Referer':Referer}

def get_html(url,pid):
    req = urllib3.request("POST",url=url, headers=get_header(pid))
    return req.read()

def main():
    for i in range(1001,10257):
        url = "http://www.luogu.org/problem/show?pid="+str(i)
        html = get_html(url,i)
        print(i,"      ",html)

if __name__ == '__main__':
    main()
