set serveroutput on
-- if������

--if ���� then
--	���
--[elsif ���� then
-- 	���;
--....
--else ���;]
--end if;

--break; //��� ����������


--�ݺ��� : for ī��Ʈ ���� in �ʱⰪ.. �ִ밪 loop ~~ end loop;
-- �ݺ��� : while ���� loop ~~end loop;
-- �ݺ��� : loop ~~end loop;
declare
	i number(4) := 1;
	i2 number(4) := 1;
	i3 number(4) := 1;
begin
	dbms_output.put_line('for�� �̿��� ó��');
	for i in 1..10 loop
		dbms_output.put_line('i �� �� ->' || i);
	end loop;


	dbms_output.put_line('while�� �̿��� ó��');
 	while i2<20 loop
		dbms_output.put_line('i �� �� ->' || i2);
		i2  := i2+1;
	end loop;

	dbms_output.put_line('loop�� �̿��� ó��');
	loop
	exit when i3>10;
	dbms_output.put_line('i3 �� �� ->' || i3);
	i3 := i3+1;
	
	
	end loop;
	
end;
/

-- while �� �ܼ��ݺ��� (loop)���� �� 1~10���� ���

-- �ұ��� ������ ����