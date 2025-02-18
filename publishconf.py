# This file is only used if you use `make publish` or
# explicitly specify it as your config file.

import os
import sys

sys.path.append(os.curdir)
from pelicanconf import *

# If your site is available via HTTPS, make sure SITEURL begins with https://
SITEURL = "https://zyc2024.com.cn"
RELATIVE_URLS = True
THEME = "/Flex"
LOAD_CONTENT_CACHE = False
FEED_ALL_ATOM = "feeds/all.atom.xml"
CATEGORY_FEED_ATOM = "feeds/{slug}.atom.xml"
STATIC_PATHS = [u"img",u"file",u".git",u"output",u"res"]
SUMMARY_MAX_LENGTH = 25
DELETE_OUTPUT_DIRECTORY = False

# ARTICLE_PATHS = ['blog']
ARTICLE_SAVE_AS = 'b/{date:%Y}{date:%m}{date:%d}/{date:%H}{date:%M}{date:%S}.html'
ARTICLE_URL = 'b/{date:%Y}{date:%m}{date:%d}/{date:%H}{date:%M}{date:%S}.html'
RELATIVE_URLS = True
# Following items are often useful when publishing

# DISQUS_SITENAME = ""
# GOOGLE_ANALYTICS = ""
