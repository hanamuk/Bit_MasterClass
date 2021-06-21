set serveroutput on
-- if문형식

--if 조건 then
--	명령
--[elsif 조건 then
-- 	명령;
--....
--else 명령;]
--end if;

--break; //제어문 빠져나가기


--반복문 : for 카운트 변수 in 초기값.. 최대값 loop ~~ end loop;
-- 반복문 : while 조건 loop ~~end loop;
-- 반복문 : loop ~~end loop;
declare
	i number(4) := 1;
	i2 number(4) := 1;
	i3 number(4) := 1;
begin
	dbms_output.put_line('for를 이용한 처리');
	for i in 1..10 loop
		dbms_output.put_line('i 의 값 ->' || i);
	end loop;


	dbms_output.put_line('while를 이용한 처리');
 	while i2<20 loop
		dbms_output.put_line('i 의 값 ->' || i2);
		i2  := i2+1;
	end loop;

	dbms_output.put_line('loop를 이용한 처리');
	loop
	exit when i3>10;
	dbms_output.put_line('i3 의 값 ->' || i3);
	i3 := i3+1;
	
	
	end loop;
	
end;
/

-- while 과 단순반복문 (loop)으로 각 1~10까지 출력

-- 쌀국수 먹으러 가자