from urllib.request import urlretrieve as u
import urllib
a=['ouclu7mc', 'o6h1568f', 'ot2lqv06', 'o582339p', 'o541q6h4', 'o04kwup1', 'o128w494', 'o552o2n2', 'ov5211nl', 'ojcj3cg1', 'o67mcw4n', 'ott1b061', 'o720hv4m', 'odbh6lg1', 'ose7b530', 'o8tfs48k', 'o1o96rc1', 'ow3dy08p', 'oiu18abu', 'o9ln0642', 'oc84w82c', 'ozz9p8qv', 'o3wa63nm', 'o99cu505', 'orjv520s', 'o89m004m', 'o319j2h7', 'o75r5w17', 'ov0rri66', 'o18n6gt2', 'ova28915', 'ouzv4848', 'o69e9h16', 'o1f0l19r', 'ou9sm62m', 'o56b05mo', 'o1ls9650', 'o39nep29', 'oo2qe9mn', 'o45uz1ey', 'o9i742f9', 'on05o3wl', 'ort6135z', 'orno1q4t', 'o3ywxvk2', 'oxydg5ov', 'o711elba', 'ogyf6oi5', 'oq916l38', 'o73454lm', 'o50v6410', 'oj7tf88o', 'oj1c2gb2', 'ojpvzu2k', 'oylh71b8', 'obk31qux', 'o4m35cff', 'oua479o0', 'o65tu911', 'od72x5go', 'oj8o8690', 'of6r0359', 'oh84gtc8', 'o7v25x0c', 'o25z5525', 'o0y49s6p', 'ox882tf6', 'oh43r781', 'o46pn1lv', 'oniol293', 'og0619qg', 'o9l8c4xo', 'ox2ol1b4', 'o13xhkg9', 'o8lc34a7', 'obj8875k', 'o72v9f4k', 'oh804j3p', 'o7122fx9', 'o6gt7567', 'ob6c8b09', 'on2ay17o', 'oxwskuf0', 'o9o15mu7', 'o0kmz6fb', 'obt4a9au', 'og921tl2', 'o51bcj07', 'oa1ptb26', 'oqb8rxh0', 'o3lz3v0g', 'og9iz6uy', 'omh30a8d', 'o3mg08u0', 'o1k11htj', 'o32rcshj', 'ol8yvlc3', 'o8245vqm', 'o2t2139p', 'ok8q6814', 'o10c903b', 'od61mhlp', 'o7k69ds0', 'o3x678w8', 'oy1x5z83', 'o8737o2v', 'oh8kj13n', 'os8acxmx', 'o7j6u3y6', 'oc742431', 'o64ctt8l', 'ohodp9y6', 'ol5bpc4j', 'on3b19tn', 'oz0qw609', 'op8mxd5y', 'o4376xg0', 'oi7fjju3', 'ovo233xs', 'ox1vn0t7']
for i in a:
    try:
        u("https://www.luogu.com/paste/{}".format(i),"G:\\Desktop\\test\\{}.html".format(i))
    except urllib.error.HTTPError:
        print(i.split("/")[-1],"404")
    except KeyboardInterrupt:
        raise(KeyboardInterrupt)
    except:
        print(i.split("/")[-1],"Other errorrrrrrrrs")
