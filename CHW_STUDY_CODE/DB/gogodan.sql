set serveroutput on
set verify off 	
	

accept dan prompt '���ڸ� �Է� -> '
begin
	
	for  j in 1..9 loop
	dbms_output.put_line(&dan ||' X '||j|| '�� �� ->' || &dan* j);
	end loop;

end;
/

-- while �� �ܼ��ݺ��� (loop)���� �� 1~10���� ���
