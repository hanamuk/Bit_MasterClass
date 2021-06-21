--입력받은 사원번호의 사원 커미션을 변경하는 프로그램(테이블에 comm n(10) 컬럼 추가 후 작업)
--단, 커미션은 급여가 1000미만   -> 급여의 10%
                --1000 ~ 2000    -> 급여의 15%
         --2000초과   -> 급여의 20%
         --null   -> 0

set serveroutput on
set verify off

--alter table sawon add comm number (10);

accept num prompt '숫자를 입력 -> '

declare
   name sawon.saname%type;
   comm sawon.sapay%type;
begin
   select saname, sapay into name, comm from sawon where sabun = &num;
   if comm < 1000 then
      comm := comm*1.1;
   elsif comm < 2000 then
      comm := comm*1.15;
   elsif comm > 2000 then
      comm := comm*1.2;
   end if;
   dbms_output.put_line(name || ' 커미션 : ' || comm);
end;
/
