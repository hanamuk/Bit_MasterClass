"""
import datetime
today = datetime.date.today();
print('today is ', today)
"""
from datetime import date, datetime, timedelta
#날짜 구하기
today = date.today()
print('오늘',today)

#년, 월 , 일
print('연도', today.year)
print('월', today.month)
print('일', today.day)

#현재의 날짜와 시간 구하기(datetime)
#from datetime datetime

cur_time = datetime.today()
print(cur_time)

#날짜계산(timedelta)
today = date.today()
print('어제 : ', today+ timedelta(days=-1))
print('어제 : ', today+ timedelta(days=-7))
print('어제 : ', today+ timedelta(days=10))

#날짜 출력 형식(strftime())
today = date.today()
print(today.strftime('%m/%d/%Y'))
print(today.strftime('%Y %m %d %H'))

#문자열을 날짜 형식으로 변환strptime()
str = '2021-06-24 16:14:30'
mydate = datetime.strptime(str, '%Y-%m-%d %H:%M:%S')
print(mydate)
print(type(mydate))