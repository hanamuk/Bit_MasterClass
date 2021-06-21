

set serveroutput on
set verify off

declare 
	cursor mycur is select  sapay,sabun from sawon;
	v_comm sawon.comm%type;
	cnt number(3);
begin

	for i in mycur loop 
		 if i.sapay < 1000 then
      		 	v_comm := i.sapay * 0.1;
   		elsif i.sapay <= 2000 then
      			v_comm := i.sapay * 0.15;
  		 elsif i.sapay > 2000 then
      			v_comm := i.sapay * 0.2;
  		 else
     		 	v_comm := 0;
  		 end if;

  		 update sawon set comm = v_comm where i.sabun = sabun;
   		cnt := mycur%rowcount;
	end loop;
	
	dbms_output.put_line('����� ����� ���� ' || cnt ||'�� �Դϴ�');


end;
/

--%rowtype �Ӽ��� for�� �ݺ��� �ȿ� .fetch ���� �ݺ��� �ۿ��� ����ؾ���.