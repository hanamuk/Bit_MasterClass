
set serveroutput on
set verify off



declare
   cursor mycur is select sabun , saname , sahire , sapay from sawon;
   v_salrank number(3);
   v_workdates number(10);
   v_workYear number(3);
   v_workMonth number(3);
   v_workWork varchar2(20);

begin
   for i in mycur loop
--   급여순위
   select count(sapay)+1 into v_salrank from sawon where i.sapay < sapay;
--   근무기간
   select months_between(sysdate,sahire) into v_workdates from sawon where i.sabun = sabun;
   v_workYear := trunc(v_workdates/12 ,0);
   v_workMonth := mod(v_workdates , 12);
   v_workWork := to_char(v_workYear || 'year' || v_workMonth || 'mon');
   dbms_output.put_line(i.saname || ' ' || v_salrank || ' '|| v_workdates||' ' || v_workYear || ' ' || v_workMonth || ' ' || v_workWork);

   insert into sawon_result (sabun , sname , hiredate , sal , hiredate_work , sal_rank) values (i.sabun, i.saname , i.sahire, i.sapay, v_workWork , v_salrank);
   end loop;

end;
/