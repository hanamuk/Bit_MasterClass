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


begin
	dbms_output.put_line('for�� �̿��� ó��');
	for i in 1..10 loop
		dbms_output.put_line('i �� �� ->' || i);
	end loop;

	dbms_output.put_line('while�� �̿��� ó��');

	i number(4) := 1;
 	while i<10 loop
		dbms_output.put_line('i �� �� ->' || i);
	i  := i+1;
	end loop;

	i2 number(4) := 1;
	loop
	dbms_output.put_line('loop�� �̿��� ó��');
	i2  := i2+1;
	end loop;
end;
/

-- while �� �ܼ��ݺ��� (loop)���� �� 1~10���� ���


