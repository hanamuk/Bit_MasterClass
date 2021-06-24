# -----------------------------------------------
#  집합
#       - 집합에 관련된 자료형
#       - 순서를 지정하지 않는다
#       - 중복을 허용하지 않는다


s = set()               # 빈 집합을 생성
s = set([1,2,3,1,1])
#print(s)
s2 = {3,4,5,6}

print(s.intersection(s2)) #교집합
print(s.union(s2)) #합집합

print(s & s2) #교집합
print(s | s2) #합집합
print(s - s2) #차집합