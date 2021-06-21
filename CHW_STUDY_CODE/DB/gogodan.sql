set serveroutput on
set verify off 	
	

accept dan prompt '숫자를 입력 -> '
begin
	
	for  j in 1..9 loop
	dbms_output.put_line(&dan ||' X '||j|| '의 값 ->' || &dan* j);
	end loop;

end;
/

-- while 과 단순반복문 (loop)으로 각 1~10까지 출력
