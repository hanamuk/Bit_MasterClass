"""
        숫자형 종류
            - 정수형
            - 실수형
            - 복소수형 1 + 2j, 3i  ( 많이 사용안함 )
            - 8진수   0o25
            - 16진수  0x25
"""

# 파이션의 모든 자료형은 객체로 취급한다
# 실행 : alt + shift + F10

""" [ 기초 연산자 ]
    1. 산술연산자
        + : 더하기
        - : 빼기
        * : 곱하기
        / : 나누기(실수값 결과)
        // : 나누기(정수값 결과)
        % : 나머지
        ** : 자승
    
    2. 관계연산자
        <   >   <=  >=  ==  !=
    
    3. 논리연산자
        not     or      and
        
    4. 이진(비트) 연산자
        ~   :  이진 not   
        |   :  이진 or
        &   :  이진 and
        ^   :  이진 xor
        <<  :  shift
        >>  :  shift
        
    5. 대입연산자
        =
        +=  -=  *=  /=  //= %=
        &=  |=  ^=
        >>= <<=
    
    6. 기타연산자 : 딕셔너리, 문자열, 리스트, 튜플 등의 자료형에서 사용
        is      : 비교하는 객체의 주소가 같으면 true, 다르면 false
        is not  : 비교하는 객체의 주소가 다르면 true, 같으면 false 
        in      : 요소에 포함되면 true, 없으면 false
        not in  : 요소에 포함되지 않으면 false, 없으면 true
      

    [참고] 증가(++), 감소(--) 연산자 없음         
"""

a = 5
b = 2

""" [ 출력결과 ] 
        a + b = 7
        a - b = 3
        a * b = 10
        a / b = 2.5
        a // b = 2
        a % b = 1
        a ** b = 25
"""
'''
add = a+b
sub = a-b
muti = a*b
fdiv = a/b
idiv = a//b
remain = a%b
squa = a**b

print('a+b =' + str(add))
print('a-b =' + str(sub))
print('a*b =' + str(muti))
print('a/b =' + str(fdiv))  #정수와 정수 나눠도 결과는 실수형 (3.0이후로)
print('a//b =' + str(idiv))
print('a%b =' + str(remain))
print('a**b =' + str(squa))

#복소소 : 많이 사용은 안하지만
print(1j +2j)
'''
#출력포멧
y  = 8.3/2.7
print('실수 1 :{0}, 정수 : {1}'.format(y,100))
print('실수 2 :{}, 정수 : {}'.format(y,200))
print('실수 3 :{1}, 정수 : {0}'.format(300,y))
print('실수 :{1:.1f}, 정수 : {0}'.format(300,y))

#기타연산자
print('Hello' is 'hello')
print('Hello' is not 'Hello')
print('H' in 'Hello')
print('H' not in 'Hello')