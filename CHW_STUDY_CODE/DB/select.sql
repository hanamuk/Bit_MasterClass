-- * 테이블에서 행을 가져오기(단일행) : 컬럼명은 변수로 사용할 수 없다
-- select 컬럼명,.. into 담을변수,... from 테이블명,..;

accept num prompt '찾을 사원의 사번을 입력 -> '
declare
	name sawon.saname%type;
-- 사원테이블의 사원이름을 받을 변수의 타입을 똑같이 만들어줌

begin
	
	select saname into name from sawon where sabun = &num;
	dbms_output.put_line('이름 :'||name);
end;
/