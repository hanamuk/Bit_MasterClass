-- * ���̺��� ���� ��������(������) : �÷����� ������ ����� �� ����
-- select �÷���,.. into ��������,... from ���̺��,..;

accept num prompt 'ã�� ����� ����� �Է� -> '
declare
	name sawon.saname%type;
-- ������̺��� ����̸��� ���� ������ Ÿ���� �Ȱ��� �������

begin
	
	select saname into name from sawon where sabun = &num;
	dbms_output.put_line('�̸� :'||name);
end;
/