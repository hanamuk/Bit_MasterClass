'''
    # compile
     - 동일한 정규표현식을 매번 다시 쓰기 번거로움을 해결
     - compile로 해당표현식을 re.RegexObject 객체로 저장하여 사용가능
'''

import re


#----------------------------------------
webs = ['http://www.test.co.kr',
        'https://www.test1.com',
        'http://www.test.com',
        'ftp://www.test.com',
        'http:://www.test.com',
       'htp://www.test.com',
       'http://www.google.com',
       'https://www.homepage.com.']

